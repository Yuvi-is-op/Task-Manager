#include "Task.hpp"

// Constructor
Task::Task(const std::string& name) : name(name) {}

Task::Task(const std::string& name, bool done) : name(name), done(done) {}

// Mark the task as completed/done
void Task::markDone() {
    done = true;
}

// Return whether the task is completed or not
bool Task::isDone() const {
    return done;
}

const std::string& Task::getName() const {
    return name;
}
