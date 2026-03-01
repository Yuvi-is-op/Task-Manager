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

## Getting Started

### Prerequisites

- C++17 or later  
- A C++ compiler (g++, clang++)

---

## Build

```bash
g++ -std=c++17 -o taskmanager main.cpp App.cpp TaskManager.cpp Task.cpp