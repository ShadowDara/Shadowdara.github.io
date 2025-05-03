<template>
  <div class="d4r-box">

    <!-- Header links bar -->
    <div>
      <!-- Home is standard -->
      <router-link to="/">Home</router-link> ·
      <router-link to="/blog">Blog</router-link> ·
      <router-link to="/projects">Projects</router-link> ·
      <router-link to="/webtools">Webtools</router-link> ·
      <a href="https://github.com/shadowdara/shadowdara.github.io" target="_blank">Source Code</a>
    </div>
    <hr>

    <!-- The Homepage -->

    <router-view />
  </div>
</template>

<script setup>
import { useRoute } from 'vue-router'
const route = useRoute()
</script>
