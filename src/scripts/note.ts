import {
    parseMarkdown,
    parseMarkdownToDocument,
} from "samengine/utils";

window.addEventListener("DOMContentLoaded", () => {
    const textarea = document.getElementById("notetext");
    const preview = document.getElementById("preview");
    const toggleBtn = document.getElementById("toggleBtn");
    const exportBtn = document.getElementById("exportBtn");

    let rawMarkdown = "";
    let viewOnly = false;

    function updatePreview() {
        preview.innerHTML = parseMarkdown(rawMarkdown);
    }

    function toggleView() {
        viewOnly = !viewOnly;

        if (viewOnly) {
            textarea.style.display = "none";
            preview.classList.add("viewonly");
            toggleBtn.textContent = "✏️ Edit";
        } else {
            textarea.style.display = "block";
            preview.classList.remove("viewonly");
            toggleBtn.textContent = "👁 View";
            textarea.focus();
        }
    }

    async function exportHTML() {
        const html =
            "<!-- Markdown Note -->" +
            parseMarkdownToDocument(rawMarkdown);

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

    textarea.addEventListener("input", (e) => {
        rawMarkdown = e.target.value;
        updatePreview();
    });

    toggleBtn.addEventListener("click", toggleView);
    exportBtn.addEventListener("click", exportHTML);

    updatePreview();
});
