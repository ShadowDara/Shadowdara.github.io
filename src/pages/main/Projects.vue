<template>
  <!-- Nur anzeigen, wenn Route exakt /projects ist -->
  <div v-if="route.path === '/projects'">
    <h1>My Projects</h1>

    <!-- CMD Shortcut-->
    <hr>
    <div>
      <h3>CMD Shortcut</h3>
      <p>A little Programm to open the <b>cmd</b> Terminal in your current windows explorer Folder!</p>
      <p>View <i>here</i> on <a href="https://github.com/ShadowDara/open-cmd-on-Hotkey">Github!</a></p>
    </div>

    <!-- Webtools -->
    <hr>
    <div>
      <h3><router-link to="/webtools">Webtools</router-link></h3>
      <p>some web tools which are hosted on my Webpage</p>
    </div>

    <!-- No fucking cors -->
    <hr>
    <div>
      <h3><router-link to="/webtools/nofuckingcors">No fucking CORS</router-link></h3>
      <p>generate a Bypass CORS restrictions on your browser or create an own server with the template source code!</p>
      <p>View <i>here</i> on <a href="https://github.com/ShadowDara/no-fucking-cors">Github!</a></p>
    </div>

  </div>

  <router-view />
</template>

<script setup>
import { useRoute } from 'vue-router'
const route = useRoute()
</script>
