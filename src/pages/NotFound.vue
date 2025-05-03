<!-- src/views/NotFound.vue -->
<template>
  <links />
    <div style="text-align: center; padding: 2rem;">
      <h1>404 - Page not found</h1>
      <router-link to="/">Back to the Homepage</router-link>
    </div>
</template>

<script setup>
import links from '@/components/links.vue';
</script>
  