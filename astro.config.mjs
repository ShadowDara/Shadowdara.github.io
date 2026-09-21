// Astro Config
import { defineConfig } from "astro/config";
import tailwindcss from "@tailwindcss/vite";
import mdx from "@astrojs/mdx";
import sitemap from "@astrojs/sitemap";
import fs from "node:fs";
import { customizeRedirects } from "./scripts/redirects";
import yaml from "js-yaml";
import { visualizer } from "rollup-plugin-visualizer";
import { DevTools } from "@vitejs/devtools";
import pagefind from "astro-pagefind";

import starlight from "@astrojs/starlight";

const redirectsYaml = yaml.load(
  fs.readFileSync("./src/config/redirects.yaml", "utf8"),
);

const redirects = {};

for (const r of redirectsYaml) {
  if (Array.isArray(r.from)) {
    r.from.forEach((f) => {
      redirects[f] = r.to;
    });
  } else {
    redirects[r.from] = r.to;
  }
}

// --------------------------------------------------
// Astro Config
// --------------------------------------------------

export default defineConfig({
  vite: {
    plugins: [tailwindcss(), visualizer(), DevTools()],

    build: {
      target: "esnext",
    },

    optimizeDeps: {
      esbuildOptions: {
        target: "esnext",
      },
    },
  },

  base: "",

  integrations: [
    sitemap(), // WICHTIG:
    customizeRedirects(redirects),
    starlight({
      title: "Meine Dokumentation",
      sidebar: [
        {
          label: "Getting Started",
          items: ["getting-started", "installation", "configuration"],
        },
        {
          label: "API",
          items: ["api/overview", "api/reference"],
        },
      ],
    }),
    pagefind(),
    mdx(),
  ],

  site: "https://shadowdara.github.io",

  redirects,
});
