<template>
  <div class="d4r-box">

    <!-- Header links bar -->
    <div>
      <!-- Home is standard -->
      <router-link to="/">Home</router-link> ·
      <router-link to="/posts/home">Posts</router-link> ·
      <router-link to="/devblog">Blog</router-link> ·
      <router-link to="/projects">Projects</router-link> ·
      <router-link to="/webtools">Webtools</router-link> ·
      <router-link to="/about_me">About me</router-link> ·
      <router-link to="/more">More</router-link>
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
