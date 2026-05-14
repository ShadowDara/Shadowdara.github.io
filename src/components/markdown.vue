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

      <article class="md-body" :class="{ viewonly: viewOnly }" v-html="htmlContent"></article>
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

import "../styles/mdcss.css"

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

<style></style>
