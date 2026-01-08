#ifndef APP_HPP
#define APP_HPP

#include <string>
#include "TaskManager.hpp"

class App {
    private:
    TaskManager manager;
    bool running;

    void printMenu();

    void handleCommand(const std::string& command);

    std::string ltrim(const std::string& s);

    public:
    App();

    void run();
};

#endif 

