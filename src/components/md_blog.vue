<template>
  <div class="markdown">
    <h1>{{ frontmatter.title }}</h1>
    <p><em>{{ frontmatter.date }}</em></p>
    <div v-html="htmlContent"></div>
  </div>
</template>

<script setup>
import { ref, watch, onMounted } from 'vue'
import fm from 'front-matter'
import MarkdownIt from 'markdown-it'

const props = defineProps({
  src: String // ← erwartet Pfad zur Markdown-Datei
})

const htmlContent = ref('')
const frontmatter = ref({})
const md = new MarkdownIt()

async function loadMarkdown(file) {
  try {
    const response = await fetch(file)
    if (!response.ok) throw new Error(`HTTP ${response.status}`)
    const raw = await response.text()
    const parsed = fm(raw)
    frontmatter.value = parsed.attributes
    htmlContent.value = md.render(parsed.body)
  } catch (err) {
    console.error('Markdown loading failed:', err)
  }
}

watch(() => props.src, (newVal) => {
  if (newVal) loadMarkdown(newVal)
}, { immediate: true }) // ← sofort laden und bei Änderung neu laden
</script>
