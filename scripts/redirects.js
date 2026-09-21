import path from "node:path";
import { fileURLToPath } from "node:url";
import fs from "node:fs";

export function customizeRedirects(redirects) {
  return {
    name: "customize-redirects",

    hooks: {
      "astro:build:done": ({ dir }) => {
        // Astro liefert dir eine file:// URL.
        // fileURLToPath macht daraus unter Windows einen korrekten Pfad.
        const dist = fileURLToPath(dir);

        console.log(`[customize-redirects] dist: ${dist}`);

        for (const [from, to] of Object.entries(redirects)) {
          const cleanFrom = from.replace(/^\/|\/$/g, "");

          const file = path.join(dist, cleanFrom, "index.html");

          if (!fs.existsSync(file)) {
            console.warn(
              `[customize-redirects] Redirect HTML nicht gefunden: ${file}`,
            );
            continue;
          }

          const html = `<!doctype html>
<html lang="de">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <meta http-equiv="refresh" content="0;url=${to}">
  <link rel="canonical" href="${to}">

  <title>Redirecting to ${to}</title>

  <style>
    body {
      font-family: system-ui, sans-serif;
      max-width: 600px;
      margin: 4rem auto;
      padding: 1rem;
    }

    a {
      text-decoration: underline;
    }
  </style>
</head>
<body>
  <h1>You are redirected to ${to}</h1>

  <p>
    If the redirection does not work,
    <a href="${to}">click here</a>.
  </p>
</body>
</html>`;

          fs.writeFileSync(file, html, "utf8");

          console.log(`[customize-redirects] ${from} → ${to}`);
        }
      },
    },
  };
}
