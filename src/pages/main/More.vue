<template>
    <h1>More Content</h1>
    <hr>
    <p><i>Page Version:</i> <b><version /></b></p>
    <hr>
    <b><a href="/#/more/changelog">Page Changelog</a></b>
    <hr>
    <b><a href="https://github.com/shadowdara/shadowdara.github.io">Page Source Code</a></b>
    <hr>
    <b><a href="/#/more/page_linktree">Full Link Tree of the page</a></b>
    <hr>
    <p><i>More will be coming soon of course!</i></p>
    <hr>
    <h2>Links</h2>
    <links_base />
</template>

<script setup>
import version from '@/components/page_version.vue'
import links_base from '@/components/links_base.vue';
</script>
