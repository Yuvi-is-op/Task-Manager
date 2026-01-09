#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include "App.hpp"

App::App() : running(true) {}

void App::printMenu() {
    std::cout << "Commands:" << std::endl;
    std::cout << "add <task name>" << std::endl;
    std::cout << "list" << std::endl;
    std::cout << "done <index>" << std::endl;
    std::cout << "delete <index>" << std::endl;
    std::cout << "save <filename>" << std::endl;
    std::cout << "load <filename>" << std::endl;
    std::cout << "menu" << std::endl;
    std::cout << "quit" << std::endl << std::endl;
}

void App::handleCommand(const std::string& s) {
    std::string command{};
    std::string later{};
    std::string com = ltrim(s);

    for (size_t i{}; i < com.size(); i++) {
        if (com[i] == ' ') {
            command = com.substr(0, i);
            later = com.substr(i + 1);
            break;
        }
    }
    command = command.empty() ? com : command;
    later = ltrim(later);

    if (command != "list" && command != "quit" && command != "menu" && later.empty()) {
        throw std::invalid_argument("Enter argument after command");
    }

    if (command == "add") {
        manager.addTask(later);
    }
    else if (command == "list") {
        manager.listTasks();
    }
    else if (command == "done") {
        handleIndexCommand([this](int index) {manager.markTaskDone(index);}, later);
    }
    else if (command == "delete") {
        handleIndexCommand([this](int index) {manager.deleteTask(index);}, later);
    }
    else if (command == "save") {
        manager.saveToFile(later);
    }
    else if (command == "load") {
        manager.loadFromFile(later);
    }
    else if (command == "menu") {
        printMenu();
    }
    else if (command == "quit") {
        running = false;
    }
    else {
        throw std::invalid_argument("Not a valid command");
    }
    std::cout << std::endl;
}

void App::handleIndexCommand(std::function<void(int)> func, const std::string& s) {
    int index = std::stoi(s);
    func(index);
}

void App::run() {
    printMenu();
    while (running) {
        try {
            std::string command{};
            std::cout << "What would you like to do? ";
            std::getline(std::cin, command);
            handleCommand(command);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error! " << e.what() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error! " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "Error! " << e.what() << std::endl;
        }
    }
}

 std::string App::ltrim(const std::string& s) {
        for (size_t i{}; i < s.size(); i++) {
            if (s[i] != ' ') {
                return s.substr(i);
            }
        }
        return "";
    }

