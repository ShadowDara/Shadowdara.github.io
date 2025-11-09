---
layout: post
title: 'Progressive Web App'
publishedAt: '2025-10-22'
categories: blog
tag: webdev
author: Shadowdara
---

# Progressive Web App

## Info

There is a new technique to make new Webapps which are most likely like
Desktop apps except they are running in the browser and have a shortcut
on the Desktop. Currently they are only avaible in chrome and other
chromoium browsers.

## Making

To make a progressive web app you 2 new files in the root directory of your
webapp, `app.js` and `service_worker.js`. You can download both of these files here
- [app.js]() & [service_worker.js]() or copy the Code download

## Code

### app.js
```js
/* To make an Progressive Web App */

if ("serviceWorker" in navigator) {
  navigator.serviceWorker.register("/service-worker.js");
}
```

### service_worker.js
```js
/* To make an Progressive Web App */

self.addEventListener("install", event => {
  event.waitUntil(
    caches.open("app-cache").then(cache => {
      return cache.addAll(["/", "/index.html", "/styles.css", "/app.js"]);
    })
  );
});

self.addEventListener("fetch", event => {
  event.respondWith(
    caches.match(event.request).then(response => {
      return response || fetch(event.request);
    })
  );
});
```

## Issue
Feel free to open an Issue here if you have some requestions
or if something does not work etc. [Open Issue](https://github.com/ShadowDara/Shadowdara.github.io/issues/new)
