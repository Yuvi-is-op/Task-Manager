#include "Task.hpp"

// Constructor
Task::Task(std::string name) : name(name) {}

Task::Task(std::string name, bool done) : name(name), done(done) {}

// Mark the task as completed/done
void Task::markDone() {
    done = true;
}

// Return whether the task is completed or not
bool Task::isDone() const {
    return done;
}

std::string Task::getName() const {
    return name;
}
