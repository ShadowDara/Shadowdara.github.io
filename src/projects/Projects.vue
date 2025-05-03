<template>
  <!-- Nur anzeigen, wenn Route exakt /projects ist -->
  <div v-if="route.path === '/projects'">
    <h1>My Projects</h1>
    <hr>

    <!-- CMD Shortcut-->
    <div>
      <h3><router-link to="/projects/cmd_shortcut">CMD Shortcut</router-link></h3>
      <p>A little Programm to open the Terminal in your current Folder!</p>
    </div>
    <hr>

    <!-- Webtools -->
    <div>
      <h3><router-link to="/webtools">Webtools</router-link></h3>
      <p>some tools and generate which are hosted on my Webpage</p>
    </div>
  </div>

  <router-view />
</template>

<script setup>
import { useRoute } from 'vue-router'
const route = useRoute()
</script>
