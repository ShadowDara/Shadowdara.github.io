// Astro Config
import { defineConfig } from "astro/config";
import tailwindcss from "@tailwindcss/vite";
import mdx from "@astrojs/mdx";
import sitemap from "@astrojs/sitemap";
import fs from "node:fs";
import { customizeRedirects } from "./scripts/redirects";
import yaml from "js-yaml";

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
    plugins: [tailwindcss()],

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
    mdx(),
    sitemap(),

    // WICHTIG:
    customizeRedirects(redirects),
  ],

  site: "https://shadowdara.github.io",

  redirects,
});
