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
        std::cout << count << "." << task.getName() << "\t" << done;
        std::cout << std::endl;
        count++;
    }
}

void TaskManager::markTaskDone(int index) {
    if (index < 0 || index >= tasks.size()) {
        throw out_of_range("Out of range");
    }
    tasks[index].markDone();
}

void TaskManager::deleteTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        throw out_of_range("Out of range");
    }
    tasks.erase(tasks.begin() + index);
}