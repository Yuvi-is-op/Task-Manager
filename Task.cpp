#include "Task.hpp"

// Constructor
Task::Task(std::string name) : name(name) {}

// Mark the task as completed/done
void Task::markDone() {
    done = true;
}

// Return whether the task is completed or not
bool Task::isDone() const {
    return done;
}

std::string Task::getName() {
    return name;
}
