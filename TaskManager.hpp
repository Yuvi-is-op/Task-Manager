#include <vector>
#include <string>
#include "Task.hpp"

class TaskManager {
    private:
    std::vector<Task> tasks;

    public:
    TaskManager();
    
    void addTask(std::string name);

    void listTasks();

    void markTaskDone(int index);

    void deleteTask(int index);

    void saveToFile(std::string FileName);

    void loadFromFile(std::string FileName);
};