// ################################################
// # Testing the Fixed-length integer and types
// # in Poco
// ################################################

#include <iostream>

#include <Poco/Foundation.h>
#include <Poco/ByteOrder.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello, world!" << std::endl;
    
    Poco::UInt16 port = 80;
    Poco::UInt16 networkPort = Poco::ByteOrder::toNetwork(port);
    std::cout << port << " " << networkPort << std::endl;

    return EXIT_SUCCESS;
}
