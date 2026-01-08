#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
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
    std::cout << "quit" << std::endl;
}

void App::handleCommand(const std::string& s) {
    std::string command{};
    std::string later{};
    std::vector<std::string> valid = {"menu", "add", "list", "done", "delete", "save", "load", "menu", "quit"};
    std::string com = ltrim(s);

    for (int i{}; i < com.size(); i++) {
        if (com[i] == ' ') {
            command = com.substr(0, i);
            later = com.substr(i + 1);
            break;
        }
    }
    command = command == "" ? com : command;
    later = ltrim(later);

    if (std::find(valid.begin(), valid.end(), command) == valid.end()) {
        throw std::invalid_argument("Not a valid command");
    }

    if (command != "list" && command != "quit" && later.empty()) {
        throw std::invalid_argument("Enter argument after command");
        return;
    }

    if (command == "add") {
        manager.addTask(ltrim(later));
        return;
    }
    else if (command == "list") {
        manager.listTasks();
        return;
    }
    else if (command == "done") {
        int index{};
        try {
            index = std::stoi(later);
            manager.markTaskDone(index);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error! " << e.what() << std::endl;
            return;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error! " << e.what() << std::endl;
            return;
        }
        return;
    }
    else if (command == "delete") {
        int index{};
        try {
            index = std::stoi(later);
            manager.deleteTask(index);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error! " << e.what() << std::endl;
            return;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error! " << e.what() << std::endl;
            return;
        }
        return;
    }
    else if (command == "save") {
        manager.saveToFile(later);
        return;
    }
    else if (command == "load") {
        manager.loadFromFile(later);
        return;
    }
    else if (command == "menu") {
        printMenu();
    }
    else if (command == "quit") {
        running = false;
        return;
    }
    else {
        throw std::invalid_argument("Not a valid command");
    }
}

void handleIndexCommand(const int& index) {
    
}

void App::run() {
    printMenu();
    while (running) {
        std::cout << "What would you like to do? ";
        std::string command;
        std::getline(std::cin, command);
        handleCommand(command);
    }
}

 std::string App::ltrim(const std::string& s) {
        for (int i{}; i < s.size(); i++) {
            if (s[i] != ' ') {
                return s.substr(i);
            }
        }
        return "";
    }

