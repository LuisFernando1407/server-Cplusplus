#include "../amalgamate/crow_all.h"

#include <sstream>
#include <iostream>
#include <chrono>
#include <ctime>

class ExampleLogHandler : public crow::ILogHandler {
    public:
        void log(std::string /*message*/, crow::LogLevel /*level*/) override {
//            cerr << "ExampleLogHandler -> " << message;
        }
};

int main(){
    
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]{

        crow::json::wvalue response;
        response["routes"][0] = "/add/number_1/number_2";
        response["routes"][1] = "/what_time_is_it";
     
        return response;
    });

    CROW_ROUTE(app, "/add/<int>/<int>")([](const crow::request& /*req*/, crow::response& res, int a, int b){
        std::ostringstream os;
        os << a+b;
        res.write(os.str());
        res.end();
    });  


    CROW_ROUTE(app, "/what_time_is_it")([]{
        
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     
       return std::ctime(&end_time);

    });  

    crow::logger::setLogLevel(crow::LogLevel::Debug);

    app.port(18080)
        .multithreaded()
        .run();
}