#include <string>

class Task {
    private:
    std::string name;
    bool done;

    public:
    Task(std::string name);

    void markDone();

    bool isDone();

    std::string getName();
};