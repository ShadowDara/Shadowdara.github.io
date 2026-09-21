---
title: My C++ Lib for Different Stuff
description: 'a multi C++ lib with a lot ussable functions'
pubDate: 'September 21 2026'
tags: []
---

# My Lib

PS is completly in progress currently, so plese dont forget that
and feel free to propose changes [here](https://github.com/shadowdara/shadowdara.github.io/issues)!

<details>
  <summary>Show Code</summary>

```C++
#pragma once

// This Shadowdara Personal Library is a collection of utility
// functions and classes for various purposes, including
// configuration management, file loading, rendering, and string
// manipulation. It is designed to be used in conjunction with SDL2,
// OpenGL, and ImGui for creating graphical applications.

// for C++ 20

#pragma region sorting

// bublsort algorithm, which is a simple sorting algorithm that
// repeatedly steps through the list, compares adjacent elements
// and swaps them if they are in the wrong order. The pass through
// the list is repeated until no swaps are needed, which means the
// list is sorted.

/*
// Example usage:
std::vector<int> values = { 5, 2, 8, 1, 3 };

bubblesort(values, [](int a, int b)
    {
        return a < b;
    });
*/
template <typename T, typename Compare>
inline void bubblesort(std::vector<T>& values, Compare comp)
{
    bool swapped;

    do
    {
        swapped = false;

        for (size_t i = 0; i + 1 < values.size(); ++i)
        {
            if (comp(values[i + 1], values[i]))
            {
                std::swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

#pragma endregion
```
</details>
