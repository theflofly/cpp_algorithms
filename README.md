# About

This project is the cpp implementation of various algorithms and little challenges.

The goal is to implement:
* The algorithms and data structures from the CLRS book
* The sorting algorithms from the [wikipedia page](https://en.wikipedia.org/wiki/Sorting_algorithm)
* Graph algorithms
* The interviews questions from cracking the coding interview book
* The challenges from the Euler project

My goal is to improve my C++ skills and remain seasoned with regard to algorithmic problems.

# Implemented

## sorting

* Bubble sort
* Insertion sort
* Merge sort

## questions

* Find maximum sub array recursive
* Matrix rotation 90°
* Matrix rotation by n element (in progress)

# Build

Bazel is used to build the source files.

You can run the command `bazel build main:cpp_algorithms` to build then `./bazel-bin/main/cpp_algorithms` to run. For now you have to complete the `main` from `cpp_algorithms.cc` in order to test algorithms. I plan to add a little command line interface in the future.

# Integration into vscode

If you are using Visual Studio Code, there are two predefined tasks to build and run the bazel commands:
```
{
    "version": "2.0.0",
    "tasks": [
        {
            "taskName": "bazel build",
            "command": "bazel",
            "args": [
                "build", 
                "-c",
                "dbg",
                "main:cpp_algorithms", 
                "--verbose_failures"
                ],
            "isShellCommand": true
        },
        {
            "taskName": "bazel run",
            "command": "bazel",
            "args": [
                "run", 
                "main:cpp_algorithms"
                ],
            "isShellCommand": true
        }
    ]
}
```
The "bazel build" task builds with the debug symbols, "bazel run" build and run the executable. On Mac OSX bazel does not add the debug symbols because of a bug.

You can easily map these tasks to keymaps by going into: File > Preferences > Keyboard Shortcuts and pasting the following json payload into the keybindings.json file opened on the right of vscode.
```
[
    {
        "key": "ctrl+b",
        "command": "workbench.action.tasks.runTask",
        "args": "bazel build"
    },
    {
        "key": "ctrl+r",
        "command": "workbench.action.tasks.runTask",
        "args": "bazel run"
    },
    { 
        "key": "ctrl+d",               
        "command": "workbench.action.debug.run",
        "when": "!inDebugMode" 
    }
]
```
Then Ctrl+b to build, Ctrl+r to run and Ctrl+d to start a debugging session.

# Issues

If you see a bad implementation, have a question or have an interesting algorithm that I could implement, feel free to open an issue.

# Note

This is a work in progress that will evolve rather slowly as I work on several different projects.
