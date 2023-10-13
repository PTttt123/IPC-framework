#include <UDS.hpp>
Transceiver::UDS::Transceiver::Transceiver(std::string name, std::string dest)
	: AbstractTransceiver(name, dest)
	, Server(name)
	, Client(dest)
{
}