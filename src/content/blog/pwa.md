---
title: 'Make a Progressive Web App'
pubDate: 2025-11-09
tags: ["blog", "webdev", "code"]
author: Shadowdara
description: "How to make a progressive Web App for Chrome and Chromium Browsers"
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
- [app.js](https://raw.githubusercontent.com/ShadowDara/dotfiles/refs/heads/main/Snippets/PWA/app.js) & [service_worker.js](https://raw.githubusercontent.com/ShadowDara/dotfiles/refs/heads/main/Snippets/PWA/service_worker.js) or copy the Code download

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

## Issues
Feel free to open an Issue here if you have some requestions
or if something does not work etc. Send me a message on Discord at @shadowdara or an Email at shadowdara74@gmail.com.