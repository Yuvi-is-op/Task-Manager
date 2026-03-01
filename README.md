# CLI Task Manager

A lightweight command-line task manager written in C++.
Create, track, complete, and delete tasks — all from your terminal, with file persistence across sessions.

---

## Features

- Add tasks by name
- List all tasks with their completion status
- Mark tasks as done
- Delete tasks by index
- Save and load tasks from a file

---

## Prerequisites

- C++17 or later
- g++ compiler
- make

---

## Build & Run
```bash
make        # build
make run    # build and run
make clean  # remove build files
```

---

## Usage
```
add <task name>     add a new task
list                list all tasks
done <index>        mark a task as complete
delete <index>      remove a task
save <filename>     save tasks to a file
load <filename>     load tasks from a file
menu                show this menu
quit                exit
```

---

## Project Structure
```
├── main.cpp              # entry point
├── App.hpp / .cpp        # CLI interface and command handling
├── TaskManager.hpp / .cpp  # task collection and business logic
├── Task.hpp / .cpp       # task model
└── Makefile
```

---

## License

MIT