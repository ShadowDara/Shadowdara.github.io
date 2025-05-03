<template>
    <!-- Nur anzeigen, wenn Route exakt /projects ist -->
    <div v-if="route.path === '/projects'">
      <h2>My Projects</h2>
  
      <div>
        <router-link to="/projects/cmd_shortcut">CMD Shortcut</router-link>
      </div>
    </div>
  
    <!-- Unterseiten werden hier angezeigt -->
    <router-view />
  </template>
  
  <script setup>
  import { useRoute } from 'vue-router'
  const route = useRoute()
  </script>
  