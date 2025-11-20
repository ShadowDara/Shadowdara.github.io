---
layout: post
title: 'Dart to JS Bridge'
publishedAt: '2025-11-20'
categories: blog
author: Shadowdara
---

# Dart 2 JS Bridge

Dart can be compiled to Javascript. Yeah, we already knew that, right?

### But
how to convert a Dart Library to a Javascript Library which can althought
be used on the Server?

I struggled with a question a lot of time, but i will show you my results
here!

### Dart Code

This my basic Dart File. I am using `js_util` to export the dart function to
javascript.

<br>

```dart
import 'dart:js_util';

void donothing() {
    print("Baguette");
}

void main() {
    setProperty(globalThis, 'donothing', allowInterop(donothing));
}
```

<br>

then i compiled the dart to code to js with `dart compile js -O2 --omit-implicit-checks main.dart -o main.dart.js`

### MJS Bridge

Now i made a bridge to Dart via MJS and registered the function as a export const.

<br>

```js
// universal.mjs
import './main.dart.js'; // Compiled Dart-API

// MJS Wrapper for the Dart JS Export
export const donothing = globalThis.donothing;
```

<br>

### TS Bridge

Now i made here a Typescript Bridge by importing the previous created MJS File
and creating the function with their types, this is a bit ugly but it works!

<br>

```ts
// universal.ts
import './universal.mjs';

// TS Wrapper for MJS Code
export const donothing: () => any = (globalThis as any).donothing;
```

<br>

### Code

You can although download the Repository [here](https://github.com/ShadowDara/Dart-2-JS-Bridge). Please submit Issues via down below, because i want to archive
the repository for better clearance.

### Issue
Feel free to open an Issue here if you have some requestions
or if something does not work etc. [Open Issue](https://github.com/ShadowDara/Shadowdara.github.io/issues/new)
