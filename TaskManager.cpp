#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "TaskManager.hpp"

TaskManager::TaskManager() {} 

void TaskManager::addTask(std::string name) {
    Task task = Task(name);
    tasks.push_back(task);
}

void TaskManager::listTasks() {
    int count = 1;

    for (const Task& task: tasks) {
        std::string done = task.isDone() ? "[X]" : "[ ]";
        std::cout << count << ".\t" << task.getName() << "\t" << done;
        std::cout << std::endl;
        count++;
    }
}

void TaskManager::markTaskDone(int index) {
    index--;
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Out of range");
    }
    tasks[index].markDone();
}

void TaskManager::deleteTask(int index) {
    index--;
    if (index < 0 || index >= tasks.size()) {
        throw std::out_of_range("Out of range");
    }
    tasks.erase(tasks.begin() + index);
}

void TaskManager::saveToFile(std::string FileName) {
    std::ofstream file(FileName);
    std::string complete{};

    if (!file) {
        throw std::runtime_error("Could not open file");
    }

    for (int index{}; index < tasks.size(); index++) {
        complete = tasks[index].isDone() ? "1" : "0";
        file << tasks[index].getName() << "|" << complete << std::endl;
    }
};

void TaskManager::loadFromFile(std::string FileName) {
    std::ifstream file(FileName);
    std::string line;

    if (!file) {
        throw std::invalid_argument("File does not exist");
    }

    tasks.clear();
    
    while (std::getline(file, line)) {
        std::string name;
        bool status;

        // Get the name and the status of the task
        int i = 0;
        while (i < line.size() && line[i] != '|') {
            name += line[i];
            i++;
        }
        if (i + 1 >= line.size()) {
            throw std::runtime_error("Corrupted file");
            return;
        }
        status = line[i + 1] == '1';

        tasks.push_back(Task(name, status));
    }
}
