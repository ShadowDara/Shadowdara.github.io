<template>
  <!-- Nur anzeigen, wenn Route exakt /projects ist -->
  <div v-if="route.path === '/projects'">
    <h1>My Projects</h1>
    <hr>

    <!-- CMD Shortcut-->
    <div>
      <h3>CMD Shortcut</h3>
      <p>A little Programm to open the <b>cmd</b> Terminal in your current windows explorer Folder!</p>
      <p>View <i>here</i> on <a href="https://github.com/ShadowDara/open-cmd-on-Hotkey">Github!</a></p>
    </div>
    <hr>

    <!-- Webtools -->
    <div>
      <h3><router-link to="/webtools">Webtools</router-link></h3>
      <p>some web tools which are hosted on my Webpage</p>
    </div>
  </div>

  <router-view />
</template>

<script setup>
import { useRoute } from 'vue-router'
const route = useRoute()
</script>
