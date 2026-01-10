// Latest commit
#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <functional>
#include "TaskManager.hpp"

class App {
    private:
    TaskManager manager;
    bool running;

    void printMenu();

    void handleCommand(const std::string& command);

    void handleIndexCommand(std::function<void(int)> func, const std::string& s);

    std::string ltrim(const std::string& s);

    public:
    App();

    void run();
};

#endif 

