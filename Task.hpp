#include <string>
using namespace std;

class Task {
    private:
    string name;
    bool done;

    public:
    Task(string name);

    void markDone();

    bool isDone();

    string getName();
};