#include "mqtt2exec.h"

mqtt2exec::mqtt2exec(std::string serverAddress, std::string clientId, std::string topic, int nRetryAttempts, int qos)
{
    callbacksLocked = false;

	SERVER_ADDR = serverAddress;
	CLIENT_ID = clientId;
	TOPIC = topic;
	QOS = qos;
	N_RETRY_ATTEMPTS = nRetryAttempts;

	cli = std::make_unique<mqtt::async_client>(SERVER_ADDR, CLIENT_ID);
	connOpts.set_clean_session(false);
	cb = std::make_unique<callback>(*cli, connOpts, *this);
	cli->set_callback(*cb);

	// Start the connection.
	// When completed, the callback will subscribe to topic.
	try {
		std::cout << "Connecting to the MQTT server..." << std::endl << std::flush;
		cli->connect(connOpts, nullptr, *cb)->wait();
	}
	catch (const mqtt::exception& exc) {
		std::cerr << "\nERROR: Unable to connect to MQTT server: '"
			<< SERVER_ADDR << "'" << exc << std::endl;
		return;
	}

	std::cout << "Connected to MQTT server" <<std::endl;

	try
	{
		char toPublish[] = "hello from mqtt2exec";
		cli->publish(TOPIC, toPublish, sizeof(toPublish));
	}
	catch (const mqtt::exception& exc)
	{
		std::cerr << "\nERROR: Unable to publish msg: '"
                        << SERVER_ADDR << "'" << exc << std::endl;
                return;
	}
}

mqtt2exec::~mqtt2exec()
{
	// Disconnect
	try {
		std::cout << "\nDisconnecting from the MQTT server..." << std::flush;
		cli->disconnect()->wait();
		std::cout << "OK" << std::endl;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc << std::endl;
	}
}

bool mqtt2exec::AddCmdCallback(std::string receivedMsg, void(*callback)())
{
	while(callbacksLocked);
	callbacksLocked = true;

	if (callbacks.find(receivedMsg) != callbacks.end())
	{
		callbacksLocked = false;
		return false;
	}
	
	callbacks[receivedMsg] = callback;
	callbacksLocked = false;
	return true;
}

bool mqtt2exec::RemoveCmdCallback(std::string receivedMsg)
{
        while(callbacksLocked);
        callbacksLocked = true;

	if (callbacks.find(receivedMsg) == callbacks.end())
        {
                callbacksLocked = false;
                return false;
        }

        callbacks.erase(receivedMsg);
        callbacksLocked = false;

	return true;
}

void mqtt2exec::action_listener::on_failure(const mqtt::token& tok) {
	std::cout << name_ << " failure";
	if (tok.get_message_id() != 0)
		std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
	std::cout << std::endl;
}

void mqtt2exec::action_listener::on_success(const mqtt::token& tok) {
	std::cout << name_ << " success";
	if (tok.get_message_id() != 0)
		std::cout << " for token: [" << tok.get_message_id() << "]" << std::endl;
	auto top = tok.get_topics();
	if (top && !top->empty())
		std::cout << "\ttoken topic: '" << (*top)[0] << "', ..." << std::endl;
	std::cout << std::endl;
}

void mqtt2exec::callback::reconnect() {
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	try {
		cli_.connect(connOpts_, nullptr, *this);
	}
	catch (const mqtt::exception& exc) {
		std::cerr << "Error: " << exc.what() << std::endl;
		exit(1);
	}
}

void mqtt2exec::callback::on_failure(const mqtt::token& tok) {
	std::cout << "Connection attempt failed" << std::endl;
	if (++nretry_ > parentObject.N_RETRY_ATTEMPTS)
		exit(1);
	reconnect();
}

void mqtt2exec::callback::on_success(const mqtt::token& tok) {}

void mqtt2exec::callback::connected(const std::string& cause) {
	std::cout << "\nConnection success" << std::endl;
	std::cout << "\nSubscribing to topic '" << parentObject.TOPIC << "'\n"
		<< "\tfor client " << parentObject.CLIENT_ID
		<< " using QoS" << parentObject.QOS << std::endl;

	cli_.subscribe(parentObject.TOPIC, parentObject.QOS, nullptr, subListener_);
}

void mqtt2exec::callback::connection_lost(const std::string& cause) {
	std::cout << "\nConnection lost" << std::endl;
	if (!cause.empty())
		std::cout << "\tcause: " << cause << std::endl;

	std::cout << "Reconnecting..." << std::endl;
	nretry_ = 0;
	reconnect();
}

void mqtt2exec::callback::message_arrived(mqtt::const_message_ptr msg) {
	while(parentObject.callbacksLocked);
	parentObject.callbacksLocked = true;

	for (auto& callback : parentObject.callbacks)
	{
		if (msg->to_string() == callback.first)
		{
			auto callbackPtr = callback.second;
			parentObject.callbacksLocked = false;
			callbackPtr();

			return;
		}
	}

	parentObject.callbacksLocked = false;
}

void mqtt2exec::callback::delivery_complete(mqtt::delivery_token_ptr token) {}
