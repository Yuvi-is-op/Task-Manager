CLI Task Manager
A lightweight command-line task manager written in C++. Create, track, complete, and delete tasks — all from your terminal, with file persistence across sessions.

Features

Add tasks by name
List all tasks with their completion status
Mark tasks as done
Delete tasks by index
Save and load tasks from a file

Getting Started
Prerequisites

C++17 or later
A C++ compiler (g++, clang++)

Build
bashg++ -std=c++17 -o taskmanager main.cpp App.cpp TaskManager.cpp Task.cpp
Run
bash./taskmanager
Usage
Once running, you'll be presented with a menu. Available commands:
CommandDescriptionadd <name>Add a new tasklistList all tasksdone <index>Mark a task as completedelete <index>Remove a tasksave <filename>Save tasks to a fileload <filename>Load tasks from a filequitExit the program
Project Structure
.
├── main.cpp          # Entry point
├── App.hpp / .cpp    # CLI interface and command handling
├── TaskManager.hpp / .cpp  # Task list logic
└── Task.hpp / .cpp   # Task model
License
MIT