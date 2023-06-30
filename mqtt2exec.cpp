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
