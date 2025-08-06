
#include "src/HttpClient.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    try
    {


        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);

        auto endpoints = resolver.resolve("api.binance.com", "https");

        boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);

        client c(io_context, ctx, endpoints, "api.binance.com");

        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return EXIT_SUCCESS;
}