// ################################################
// # Testing the Fixed-length integer and types
// # in Poco
// ################################################

#include <iostream>

#include <Poco/Foundation.h>
#include <Poco/ByteOrder.h>
#include <Poco/Any.h>
#include <Poco/DynamicAny.h>

int main(int argc, char* argv[])
{
	std::cout << "Hello, world!" << std::endl;

	Poco::UInt16 port = 80;
	// Convert from host byte order to network byte order
	// which is in big endian
	Poco::UInt16 networkPort = Poco::ByteOrder::toNetwork(port);
	std::cout << port << " " << networkPort << std::endl;

	// Any type to extract in a type-safe manner
	// as the type of the value must be known
	// to be able to extract it
	Poco::Any any = 42;
	int i = Poco::AnyCast<int>(any);		// okay
	int& ri = Poco::RefAnyCast<int>(any);	// okay
	try
	{
		short s = AnyCast<short>(any);		// throws BadCastException
	}
	catch (Poco::BadCastException&)
	{
		std::cout << "BadCastException caught when extracting Any to wrong type" << std::endl;
	}

	// DynamicAny type to hold a value of any type
	// where a DynamicAnyHolder specialization is available
	// and safe implicit/explicit conversions are supported 
	// Note that range are checked, data loss due to downcast forbiddened
	Poco::DynamicAny dany = 42;
	int ii = dany;
	std::string s1(dany.convert<std::string>());
	dany.convert(s1); // or without the need to cast
	const int& ri2(dany.extract<int>());
	short ss = dany;
	try
	{
		short ss = dany.extract<short>(); // throws BadCastException
	}
	catch (Poco::BadCastException&)
	{
		std::cout << "BadCastException caught when downcasting DynamicAny" << std::endl;
	}

	return EXIT_SUCCESS;
}
