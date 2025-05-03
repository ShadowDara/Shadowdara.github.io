<template>
  <!-- Nur anzeigen, wenn Route exakt /projects ist -->
  <div v-if="route.path === '/projects'">
    <h1>My Projects</h1>

    <div>
      <h3><router-link to="/projects/cmd_shortcut">CMD Shortcut</router-link></h3> <p>A little Programm to open the Terminal in your current Folder!</p>
    </div>
  </div>

  <!-- Unterseiten werden hier angezeigt -->
  <router-view />
</template>

<script setup>
import { useRoute } from 'vue-router'
const route = useRoute()
</script>
