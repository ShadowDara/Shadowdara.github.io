<template>
  <main>
    <h1 class="mt-7">Markdown Notes</h1>

    <div class="container">
      <textarea
        v-if="!viewOnly"
        id="notetext"
        v-model="rawMarkdown"
        @input="updatePreview"
      ></textarea>

      <article :class="{ viewonly: viewOnly }" v-html="htmlContent"></article>
    </div>

    <div class="inline">
      <button @click="toggleView">
        {{ viewOnly ? "✏️ Edit" : "👁 View" }}
      </button>

      <button @click="exportHTML">
        🛒 Export
      </button>

      <span class="ml-4">{{ saved }}</span>
    </div>
  </main>
</template>

<script lang="ts" setup>
import { ref, onMounted, onBeforeUnmount, nextTick } from "vue";
import { parseMarkdown, parseMarkdownToDocument } from "samengine/utils";

// View or Edit Mode for Markdown Notes
const viewOnly = ref(true);

const htmlContent = ref("");
const rawMarkdown = ref("Created a new Note. Press STRG E to switch between view and edit"); // Editor Inhalt
const saved = ref("Not saved yet");

// Funktion um Markdown zu HTML zu konvertieren
function updatePreview() {
  htmlContent.value = parseMarkdown(rawMarkdown.value);
}

async function toggleView() {
  viewOnly.value = !viewOnly.value;

  if (!viewOnly.value) {
    await nextTick();
    const el = document.getElementById("notetext");
    el?.focus();
  }
}

// Keyboard Shortcut: Ctrl+E → Toggle Editor
function handleKeydown(e: KeyboardEvent) {
  if (e.ctrlKey && e.key.toLowerCase() === "e") {
    e.preventDefault();
    toggleView();
  }
}

// Export HTML
async function exportHTML() {
  let html: string = "<!-- Markdown Note by Applaunscher -->";
  html += parseMarkdownToDocument(rawMarkdown.value);

  const blob = new Blob([html], { type: "text/html" });
  const url = URL.createObjectURL(blob);

  const a = document.createElement("a");
  a.href = url;
  a.download = "note_export.html";
  document.body.appendChild(a);
  a.click();
  document.body.removeChild(a);

  URL.revokeObjectURL(url);
}

// Lifecycle Hooks
onMounted(() => {
  updatePreview();
  window.addEventListener("keydown", handleKeydown);
});

onBeforeUnmount(() => {
  window.removeEventListener("keydown", handleKeydown);
});
</script>

<style>
/* === Markdown Styles (1:1 übernommen) === */
:root {
  --md-font: system-ui, sans-serif;
  --md-mono: "Fira Code", "Cascadia Code", Consolas, monospace;
  --md-max-width: 800px;
  --md-line-height: 1.7;
  --md-color: #1a1a2e;
  --md-bg: #ffffff;
  --md-code-bg: #f4f4f8;
  --md-border: #d1d5db;
  --md-accent: #3b5bdb;
  --md-blockquote: #6b7280;
}
*,
*::before,
*::after {
  box-sizing: border-box;
}
main {
  margin: 0;
  background: var(--md-bg);
  color: var(--md-color);
  display: flex;
  flex-direction: column;
  height: 100vh;
  padding: 1rem;
  padding-top: 0;
  margin-top: 0;
  font-family: sans-serif;
}
.md-body {
  font-family: var(--md-font);
  line-height: var(--md-line-height);
  max-width: var(--md-max-width);
  margin: 2rem auto;
  padding: 0 1.5rem;
}
h1,
h2,
h3,
h4,
h5,
h6 {
  margin: 1.6em 0 0.4em;
  line-height: 1.25;
  font-weight: 700;
}
h1 {
  font-size: 2rem;
  border-bottom: 2px solid var(--md-border);
  padding-bottom: 0.3em;
}
h2 {
  font-size: 1.5rem;
  border-bottom: 1px solid var(--md-border);
  padding-bottom: 0.2em;
}
p {
  margin: 0.8em 0;
}
a {
  color: var(--md-accent);
}
code {
  font-family: var(--md-mono);
  font-size: 0.875em;
  background: var(--md-code-bg);
  padding: 0.15em 0.35em;
  border-radius: 4px;
}
pre {
  background: var(--md-code-bg);
  border-radius: 6px;
  padding: 1em;
  overflow-x: auto;
}
pre code {
  background: none;
  padding: 0;
  font-size: 0.9em;
}
blockquote {
  margin: 1em 0;
  padding: 0.5em 1em;
  border-left: 4px solid var(--md-accent);
  color: var(--md-blockquote);
}
table {
  border-collapse: collapse;
  width: 100%;
  margin: 1em 0;
}
th,
td {
  border: 1px solid var(--md-border);
  padding: 0.5em 0.8em;
}
th {
  background: var(--md-code-bg);
  font-weight: 600;
}
tr:nth-child(even) td {
  background: #fafafa;
}
ul,
ol {
  padding-left: 1.5em;
  margin: 0.8em 0;
}
li {
  margin: 0.25em 0;
}
hr {
  border: none;
  border-top: 2px solid var(--md-border);
  margin: 2em 0;
}
img {
  max-width: 100%;
  height: auto;
  border-radius: 4px;
}
mark {
  background: #fef08a;
  padding: 0.1em 0.2em;
  border-radius: 2px;
}
input[type="checkbox"] {
  margin-right: 0.4em;
}
.footnotes {
  font-size: 0.875em;
  color: var(--md-blockquote);
}

.container {
  display: flex;
  gap: 1rem;
  flex: 1;
  min-height: 0;
}

textarea {
  width: 50%;
  padding: 1rem;
  font-family: monospace;
  border-radius: 10px;
  border: none;
  outline: none;
  resize: none;
  background: rgb(239, 239, 239);
}

article {
  width: 50%;
  padding: 1rem;
  border-radius: 10px;
  overflow: auto;
}

article.viewonly {
  width: 100%;
}

button {
  margin-top: 1rem;
  padding: 0.5rem 1rem;
  max-width: 120px;
  width: 100%;
  align-self: flex-start;
  box-sizing: border-box;
}

.inline button,
.inline span {
    margin-left: 4px;
    margin-right: 4px;
}

main::-webkit-scrollbar {
  width: 4px;
}

main::-webkit-scrollbar-thumb {
  background: rgba(255, 255, 255, 0.25);
}
</style>
