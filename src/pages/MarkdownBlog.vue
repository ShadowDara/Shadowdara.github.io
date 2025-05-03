<template>
  <div class="markdown">
    <h1>{{ frontmatter.title }}</h1>
    <p><em>{{ frontmatter.date }}</em></p>
    <div v-html="htmlContent"></div>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import MarkdownIt from 'markdown-it'
import fm from 'front-matter'

const htmlContent = ref('')
const frontmatter = ref({})
const md = new MarkdownIt()

onMounted(async () => {
  try {
    const response = await fetch('/posts/beispiel.md')
    if (!response.ok) throw new Error(`HTTP ${response.status}`)
    const raw = await response.text()

    const parsed = fm(raw)
    frontmatter.value = parsed.attributes
    htmlContent.value = md.render(parsed.body)
  } catch (err) {
    console.error('Markdown lloading errored:', err)
  }
})
</script>
