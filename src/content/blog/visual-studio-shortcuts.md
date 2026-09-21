---
title: "Visual Studio Shortcuts"
pubDate: "September 21 2026"
description: "Some helpful tipps for Visual Studio."
---

# Visual Studio Hotkeys for CMake & C++ Development

A practical cheat sheet for the most useful Visual Studio keyboard shortcuts when working on **C++ projects with CMake**.

> **Note:** These shortcuts refer primarily to the default Visual Studio key bindings on Windows. Some shortcuts may differ if you use a custom keyboard mapping or a different Visual Studio configuration.

---

## 🔥 Most Important Shortcuts

| Shortcut             | Action                    |
| -------------------- | ------------------------- |
| `Ctrl + S`           | Save the current file     |
| `Ctrl + Shift + S`   | Save As                   |
| `Ctrl + K, Ctrl + C` | Comment selected lines    |
| `Ctrl + K, Ctrl + U` | Uncomment selected lines  |
| `Ctrl + Z`           | Undo                      |
| `Ctrl + Y`           | Redo                      |
| `Ctrl + F`           | Find in current file      |
| `Ctrl + H`           | Replace in current file   |
| `Ctrl + Shift + F`   | Find in Files             |
| `Ctrl + Shift + H`   | Replace in Files          |
| `Ctrl + P`           | Go to file / search files |
| `Ctrl + T`           | Go to All                 |
| `F12`                | Go to Definition          |
| `Alt + F12`          | Peek Definition           |
| `Shift + F12`        | Find All References       |
| `Ctrl + F12`         | Go to Declaration         |
| `F5`                 | Start debugging           |
| `Ctrl + F5`          | Start without debugging   |
| `Shift + F5`         | Stop debugging            |
| `F9`                 | Toggle breakpoint         |
| `F10`                | Step over                 |
| `F11`                | Step into                 |
| `Shift + F11`        | Step out                  |

---

# 🧭 Navigation

Fast navigation is especially useful in large C++/CMake projects where headers, source files, CMake files, and generated code are spread across many directories.

## Files and Symbols

| Shortcut             | Action                              |
| -------------------- | ----------------------------------- |
| `Ctrl + P`           | Go to a file                        |
| `Ctrl + T`           | Go to All                           |
| `Ctrl + ,`           | Go to All                           |
| `Ctrl + G`           | Go to line                          |
| `F12`                | Go to Definition                    |
| `Ctrl + F12`         | Go to Declaration                   |
| `Alt + F12`          | Peek Definition                     |
| `Shift + F12`        | Find All References                 |
| `Ctrl + M, Ctrl + M` | Collapse/expand current code region |

### Go to All

`Ctrl + T` is particularly useful in C++ projects.

You can search for:

- Classes
- Functions
- Variables
- Files
- Types
- CMake files
- Symbols

Example:

```text
Ctrl + T
MyClass
```

This can be much faster than manually navigating through the Solution Explorer.

---

# 🔎 Searching

## Search in Current File

| Shortcut     | Action        |
| ------------ | ------------- |
| `Ctrl + F`   | Find          |
| `Ctrl + H`   | Replace       |
| `F3`         | Find next     |
| `Shift + F3` | Find previous |

## Search Across the Project

| Shortcut           | Action           |
| ------------------ | ---------------- |
| `Ctrl + Shift + F` | Find in Files    |
| `Ctrl + Shift + H` | Replace in Files |

### Example

To find all usages of a CMake variable or C++ symbol:

```text
Ctrl + Shift + F
```

Then search for:

```text
MY_LIBRARY
```

or:

```text
std::vector
```

This is useful when working with:

- `CMakeLists.txt`
- `.cmake` files
- `.cpp`
- `.hpp`
- `.h`
- `.cc`
- `.cxx`

---

# ✍️ Editing C++

## Comments

| Shortcut             | Action              |
| -------------------- | ------------------- |
| `Ctrl + K, Ctrl + C` | Comment selection   |
| `Ctrl + K, Ctrl + U` | Uncomment selection |

Example:

```cpp
// int result = calculate();
// std::cout << result << '\n';
```

Select the lines and press:

```text
Ctrl + K, Ctrl + C
```

---

## Code Formatting

| Shortcut             | Action                 |
| -------------------- | ---------------------- |
| `Ctrl + K, Ctrl + D` | Format entire document |
| `Ctrl + K, Ctrl + F` | Format selected code   |

These are particularly useful when working with large C++ functions or after modifying CMake-generated code.

### Format Document

```text
Ctrl + K, Ctrl + D
```

### Format Selection

```text
Ctrl + K, Ctrl + F
```

---

# 🧩 Refactoring

| Shortcut      | Action                       |
| ------------- | ---------------------------- |
| `Ctrl + .`    | Quick Actions / Refactorings |
| `F2`          | Rename symbol                |
| `Shift + F12` | Find all references          |
| `F12`         | Go to definition             |

## Rename Symbol

Place the cursor on a C++ symbol and press:

```text
F2
```

This is preferable to manually using Find & Replace because Visual Studio understands C++ symbols.

For example:

```cpp
class MyClass {
public:
    void calculate();
};
```

Renaming:

```text
calculate
```

can update its references throughout the project.

---

# 🐞 Debugging

Debugging is one of the most important parts of a C++ workflow.

## Starting and Stopping

| Shortcut            | Action                  |
| ------------------- | ----------------------- |
| `F5`                | Start debugging         |
| `Ctrl + F5`         | Start without debugging |
| `Shift + F5`        | Stop debugging          |
| `Ctrl + Shift + F5` | Restart debugging       |

### Start Debugging

```text
F5
```

Visual Studio builds the required targets and starts the debugger.

### Run Without Debugger

```text
Ctrl + F5
```

Useful when you only want to run the application without debugger overhead.

---

# 🛑 Breakpoints

| Shortcut         | Action                    |
| ---------------- | ------------------------- |
| `F9`             | Toggle breakpoint         |
| `Ctrl + F9`      | Enable/disable breakpoint |
| `Ctrl + Alt + B` | Open Breakpoints window   |

Example:

```cpp
int result = calculateValue();  // F9
```

Press:

```text
F9
```

to create a breakpoint on the current line.

---

# 🪜 Stepping Through Code

| Shortcut      | Action         |
| ------------- | -------------- |
| `F10`         | Step Over      |
| `F11`         | Step Into      |
| `Shift + F11` | Step Out       |
| `Shift + F5`  | Stop debugging |

### Step Over

```text
F10
```

Executes the current line without entering a called function.

### Step Into

```text
F11
```

Enters the called function.

Example:

```cpp
int result = calculate();
```

Pressing `F11` will enter:

```cpp
calculate()
```

### Step Out

```text
Shift + F11
```

Leaves the current function and returns to the caller.

---

# 🧠 Debugging C++

Useful windows during debugging:

| Shortcut            | Action      |
| ------------------- | ----------- |
| `Ctrl + Alt + W, 1` | Watch 1     |
| `Ctrl + Alt + W, 2` | Watch 2     |
| `Ctrl + Alt + V, A` | Autos       |
| `Ctrl + Alt + V, L` | Locals      |
| `Ctrl + Alt + C`    | Call Stack  |
| `Ctrl + Alt + B`    | Breakpoints |

> The exact shortcuts for debugging windows can depend on the selected Visual Studio keyboard mapping.

---

# 🏗️ CMake & Build Workflow

When working with CMake projects in Visual Studio, the exact build commands depend on whether you use:

- CMake Project support
- CMakePresets
- Visual Studio-generated solutions
- Ninja
- MSBuild

The following shortcuts are useful regardless of the underlying build configuration.

## Build

| Shortcut           | Action           |
| ------------------ | ---------------- |
| `Ctrl + Shift + B` | Build Solution   |
| `Ctrl + Alt + F7`  | Rebuild Solution |
| `Ctrl + Break`     | Cancel build     |

### Build

```text
Ctrl + Shift + B
```

Use this frequently after modifying:

- `.cpp`
- `.hpp`
- `CMakeLists.txt`
- `.cmake`
- compiler settings
- project configuration

---

# ⚙️ CMake Configuration

When changing CMake configuration, it can be useful to distinguish between:

```text
CMake configuration
        ↓
CMake generation
        ↓
Build
        ↓
Run / Debug
```

For example:

```text
CMakeLists.txt
      ↓
Configure
      ↓
Generate build system
      ↓
Build target
      ↓
F5
```

Visual Studio provides CMake-specific commands through the **CMake** menu and CMake integration.

Useful general shortcuts:

```text
Ctrl + Shift + B    Build
F5                  Debug
Ctrl + F5           Run
```

---

# 🧭 Solution Explorer

| Shortcut         | Action            |
| ---------------- | ----------------- |
| `Ctrl + Alt + L` | Solution Explorer |
| `Ctrl + Alt + O` | Output            |
| `Ctrl + Alt + M` | Error List        |

Solution Explorer is useful for navigating the generated project structure, although `Ctrl + T` is often faster for locating a specific C++ file or symbol.

---

# ⚠️ Errors and Build Output

| Shortcut         | Action         |
| ---------------- | -------------- |
| `Ctrl + \, E`    | Error List     |
| `Ctrl + Alt + O` | Output         |
| `F8`             | Next error     |
| `Shift + F8`     | Previous error |

After a CMake or compiler failure, check:

```text
Error List
```

and especially:

```text
Output
```

The **Output** window is often more useful for CMake problems because it can contain the actual compiler, linker, CMake, or build-system command that failed.

---

# 🧱 C++ Code Completion

| Shortcut             | Action                              |
| -------------------- | ----------------------------------- |
| `Ctrl + Space`       | Trigger IntelliSense                |
| `Ctrl + J`           | List members                        |
| `Ctrl + Alt + Space` | Toggle IntelliSense completion mode |
| `Esc`                | Close completion list               |

### Trigger IntelliSense

```text
Ctrl + Space
```

Useful when IntelliSense does not automatically display suggestions.

---

# 📖 Documentation & Code Understanding

| Shortcut      | Action               |
| ------------- | -------------------- |
| `F12`         | Go to Definition     |
| `Alt + F12`   | Peek Definition      |
| `Shift + F12` | Find All References  |
| `Ctrl + Q`    | Search Visual Studio |

For unfamiliar C++ code, a useful workflow is:

```text
Find symbol
    ↓
F12
    ↓
Inspect implementation
    ↓
Shift + F12
    ↓
Inspect usages
```

---

# 🪟 Windows & Panels

| Shortcut            | Action            |
| ------------------- | ----------------- |
| `Ctrl + Alt + L`    | Solution Explorer |
| `Ctrl + Alt + O`    | Output            |
| `Ctrl + Alt + M`    | Error List        |
| `Ctrl + Alt + C`    | Call Stack        |
| `Ctrl + Alt + B`    | Breakpoints       |
| `Ctrl + Alt + W, 1` | Watch 1           |
| `Ctrl + Alt + V, L` | Locals            |

---

# 🧹 Code Folding

| Shortcut             | Action                  |
| -------------------- | ----------------------- |
| `Ctrl + M, Ctrl + M` | Toggle current region   |
| `Ctrl + M, Ctrl + O` | Collapse to definitions |
| `Ctrl + M, Ctrl + L` | Toggle all outlining    |
| `Ctrl + M, Ctrl + A` | Collapse all            |

These shortcuts are useful for navigating large `.cpp` and `.hpp` files.

---

# 📝 Multiple Cursors & Selection

| Shortcut          | Action                       |
| ----------------- | ---------------------------- |
| `Alt + Click`     | Add cursor                   |
| `Ctrl + Alt + .`  | Add next matching occurrence |
| `Ctrl + D`        | Duplicate line/selection     |
| `Shift + Alt + .` | Select next occurrence       |

Multiple cursors can be useful for repetitive changes in CMake files.

Example:

```cmake
target_compile_definitions(app PRIVATE
    FEATURE_A
    FEATURE_B
    FEATURE_C
)
```

---

# 📋 Clipboard & Line Editing

| Shortcut         | Action         |
| ---------------- | -------------- |
| `Ctrl + C`       | Copy           |
| `Ctrl + X`       | Cut            |
| `Ctrl + V`       | Paste          |
| `Ctrl + Z`       | Undo           |
| `Ctrl + Y`       | Redo           |
| `Ctrl + D`       | Duplicate line |
| `Shift + Delete` | Delete line    |
| `Alt + Up`       | Move line up   |
| `Alt + Down`     | Move line down |

Moving lines is especially useful when reorganizing CMake targets or C++ initialization lists.

---

# 🧰 Useful CMake Workflow

A practical workflow for a CMake-based C++ project can look like this:

```text
1. Open project
        ↓
2. Ctrl + T
        ↓
3. Find CMakeLists.txt / source file
        ↓
4. Edit code
        ↓
5. Ctrl + K, Ctrl + D
        ↓
6. Ctrl + Shift + B
        ↓
7. Fix compiler errors
        ↓
8. F9
        ↓
9. F5
        ↓
10. F10 / F11
        ↓
11. Inspect variables / call stack
```

---

# ⭐ Recommended Daily Shortcuts

If you only want to memorize a small set, start with these:

```text
Ctrl + T       Go to All
Ctrl + F       Find
Ctrl + Shift + F   Find in Files

F12            Go to Definition
Shift + F12    Find All References
F2             Rename Symbol
Ctrl + .       Quick Actions

Ctrl + K, Ctrl + C   Comment
Ctrl + K, Ctrl + U   Uncomment
Ctrl + K, Ctrl + D   Format Document

Ctrl + Shift + B    Build
F5                  Debug
Ctrl + F5           Run without Debugging

F9             Toggle Breakpoint
F10            Step Over
F11            Step Into
Shift + F11    Step Out

Ctrl + Alt + O      Output
Ctrl + Alt + L      Solution Explorer
Ctrl + Alt + M      Error List
```

---

# 🚀 Recommended C++/CMake Productivity Workflow

For everyday development, the following shortcuts cover most tasks:

### 1. Find code

```text
Ctrl + T
```

### 2. Understand a symbol

```text
F12
```

### 3. Find where it is used

```text
Shift + F12
```

### 4. Modify and format

```text
Ctrl + K, Ctrl + D
```

### 5. Build

```text
Ctrl + Shift + B
```

### 6. Debug

```text
F5
```

### 7. Step through the code

```text
F10
F11
Shift + F11
```

### 8. Inspect problems

```text
Ctrl + Alt + O
Ctrl + Alt + M
```

---

# 📌 Quick Reference

```text
╔══════════════════════════════════════════════╗
║         VISUAL STUDIO C++ / CMAKE            ║
╠══════════════════════════════════════════════╣
║ NAVIGATION                                   ║
║ Ctrl + T              Go to All              ║
║ F12                   Go to Definition       ║
║ Shift + F12           Find References        ║
║ F2                    Rename Symbol          ║
║                                              ║
║ EDITING                                      ║
║ Ctrl + K, Ctrl + C    Comment                ║
║ Ctrl + K, Ctrl + U    Uncomment              ║
║ Ctrl + K, Ctrl + D    Format Document        ║
║ Ctrl + .              Quick Actions          ║
║                                              ║
║ SEARCH                                       ║
║ Ctrl + F              Find                   ║
║ Ctrl + H              Replace                ║
║ Ctrl + Shift + F      Find in Files          ║
║                                              ║
║ BUILD                                        ║
║ Ctrl + Shift + B      Build                  ║
║ Ctrl + F5             Run                    ║
║ F5                    Debug                  ║
║                                              ║
║ DEBUGGING                                    ║
║ F9                    Breakpoint             ║
║ F10                   Step Over              ║
║ F11                   Step Into              ║
║ Shift + F11           Step Out               ║
║                                              ║
║ WINDOWS                                      ║
║ Ctrl + Alt + L        Solution Explorer      ║
║ Ctrl + Alt + O        Output                 ║
║ Ctrl + Alt + M        Error List             ║
╚══════════════════════════════════════════════╝
```
