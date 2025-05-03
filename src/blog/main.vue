<template>
    <!-- Nur anzeigen, wenn Route exakt /projects ist -->
    <div v-if="route.path === '/blog'">
      <h2>Blog</h2>
  
      <div>
        <router-link to="/blog/03.05.2025">03.05.2025</router-link>
      </div>
    </div>
  
    <!-- Unterseiten werden hier angezeigt -->
    <router-view />
  </template>
  
  <script setup>
  import { useRoute } from 'vue-router'
  const route = useRoute()
  </script>
  