#include <string>

class Task {
    private:
    std::string name;
    bool done;

    public:
    Task(std::string name);

    Task(std::string name, bool done);

    void markDone();

    bool isDone() const;

    std::string getName() const;
};