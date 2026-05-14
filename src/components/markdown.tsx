import React, { useEffect, useRef, useState } from "react";
import { parseMarkdown, parseMarkdownToDocument } from "samengine/utils";

import "../styles/mdcss.css";

export default function MarkdownNotes() {
  const [viewOnly, setViewOnly] = useState(true);
  const [htmlContent, setHtmlContent] = useState("");
  const [rawMarkdown, setRawMarkdown] = useState(
    "Created a new Note. Press STRG E to switch between view and edit"
  );
  const [saved, setSaved] = useState("Not saved yet");

  const textareaRef = useRef<HTMLTextAreaElement | null>(null);

  // Markdown → HTML
  function updatePreview(value: string) {
    setHtmlContent(parseMarkdown(value));
  }

  // initial + updates
  useEffect(() => {
    updatePreview(rawMarkdown);
  }, []);

  function toggleView() {
    setViewOnly((prev) => !prev);
  }

  // focus textarea when switching to edit mode
  useEffect(() => {
    if (!viewOnly) {
      setTimeout(() => {
        textareaRef.current?.focus();
      }, 0);
    }
  }, [viewOnly]);

  // keyboard shortcut Ctrl+E
  useEffect(() => {
    function handleKeydown(e: KeyboardEvent) {
      if (e.ctrlKey && e.key.toLowerCase() === "e") {
        e.preventDefault();
        toggleView();
      }
    }

    window.addEventListener("keydown", handleKeydown);
    return () => window.removeEventListener("keydown", handleKeydown);
  }, []);

  // export HTML
  function exportHTML() {
    let html = "<!-- Markdown Note by Applaunscher -->";
    html += parseMarkdownToDocument(rawMarkdown);

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

  return (
    <main>
      <h1 className="mt-7">Markdown Notes</h1>

      <div className="container">
        {!viewOnly && (
          <textarea
            id="notetext"
            ref={textareaRef}
            value={rawMarkdown}
            onChange={(e) => {
              setRawMarkdown(e.target.value);
              updatePreview(e.target.value);
            }}
          />
        )}

        <article
          className={`md-body ${viewOnly ? "viewonly" : ""}`}
          dangerouslySetInnerHTML={{ __html: htmlContent }}
        />
      </div>

      <div className="inline">
        <button onClick={toggleView}>
          {viewOnly ? "✏️ Edit" : "👁 View"}
        </button>

        <button onClick={exportHTML}>🛒 Export</button>

        <span className="ml-4">{saved}</span>
      </div>
    </main>
  );
}
