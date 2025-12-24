#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class Logger {
    std::ofstream file;

  public:
    Logger(const std::string &filename) {
        std::cout << "[Logger] Constructor called\n";
        file.open(filename, std::ios::app); // RAII: Open on creation
        if (!file.is_open( )) {
            throw std::runtime_error("Failed to open log file");
        }
        std::cout << "[Logger] Log file opened: " << filename << "\n";
    }

    ~Logger( ) {
        std::cout << "[Logger] Destructor called\n";
        if (file.is_open( )) {
            std::cout << "[Logger] Closing log file\n";
            file.close( ); // RAII: Automatically closes
        }
        std::cout << "[Logger] Logger shut down\n";
    }

    void log(const std::string &message) {
        std::cout << "[Logger] Logging message: " << message << "\n";
        if (file.is_open( )) {
            file << "[LOG] " << message << "\n";
        } else {
            std::cerr << "[Logger] Attempted to log to a closed file\n";
        }
    }
};

class Application {
    std::shared_ptr<Logger> logger; // shared ownership
    int id;

  public:
    Application(std::shared_ptr<Logger> loggerPtr, int appId) : logger(std::move(loggerPtr)), id(appId) {
        std::cout << "[Application " << id << "] Constructor called\n";
    }

    ~Application( ) {
        std::cout << "[Application " << id << "] Destructor called\n";
    }

    void run( ) {
        std::cout << "[Application " << id << "] run() called\n";
        logger->log("Application " + std::to_string(id) + " started");
        logger->log("Application " + std::to_string(id) + " running");
    }
};

int main( ) {
    std::cout << "[main] Program started\n";
    try {
        std::shared_ptr<Logger> logger = std::make_shared<Logger>("app.log");
        std::cout << "[main] Logger created. Use count: " << logger.use_count( ) << "\n";

        Application app1(logger, 1);
        std::cout << "[main] app1 created. Logger use count: " << logger.use_count( ) << "\n";

        Application app2(logger, 2);
        std::cout << "[main] app2 created. Logger use count: " << logger.use_count( ) << "\n";

        app1.run( );
        app2.run( );

        std::cout << "[main] Applications ran. Logger use count: " << logger.use_count( ) << "\n";

    } catch (const std::exception &e) {
        std::cerr << "[main] Error: " << e.what( ) << "\n";
    }

    std::cout << "[main] Exiting main\n";
    return 0;
}
