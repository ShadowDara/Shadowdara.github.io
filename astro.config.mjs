// Astro Config
import { defineConfig } from 'astro/config';
import tailwindcss from '@tailwindcss/vite';
import mdx from '@astrojs/mdx';
import sitemap from '@astrojs/sitemap';

import fs from "fs";
import yaml from "js-yaml";

const redirectsYaml = yaml.load(
  fs.readFileSync("./src/config/redirects.yaml", "utf8")
);

const redirects = {};

for (const r of redirectsYaml) {
  if (Array.isArray(r.from)) {
    r.from.forEach(f => redirects[f] = r.to);
  } else {
    redirects[r.from] = r.to;
  }
}

export default defineConfig({
  vite: {
    plugins: [tailwindcss()],
    optimizeDeps: {
      include: ["samengine"],
    },
    ssr: {
      noExternal: ["samengine"],
    },
  },
  // base: '/portfolio',
  base: '',
  integrations: [mdx(), sitemap()],
  site: 'https://shadowdara.github.io',

  redirects
});
