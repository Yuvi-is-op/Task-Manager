#pragma once

#include <string>

class Task {
    private:
    std::string name;
    bool done;

    public:
    Task(const std::string name);

    Task(const std::string name, bool done);

    void markDone();

    bool isDone() const;

    std::string getName() const;
};