add_library(Binance STATIC
    Binance.cpp
    Binance.h
    "src/BinanceHttp.h" 
    "src/BinanceHttp.cpp" 
    "src/HttpClient.h"
    "src/HttpClient.cpp")


target_include_directories(Binance
    PUBLIC               # headers visible to anything that links libA
        ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Boost CONFIG REQUIRED COMPONENTS asio system)
target_link_libraries(Binance PRIVATE Boost::asio Boost::system)