#pragma once

#include <vector>
#include <string>
#include "Task.hpp"

class TaskManager {
    private:
    std::vector<Task> tasks;

    public:
    TaskManager();
    
    void addTask(const std::string& name);

    void listTasks();

    void markTaskDone(int index);

    void deleteTask(int index);

    void saveToFile(const std::string& FileName);

    void loadFromFile(const std::string& FileName);
};
