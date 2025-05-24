// Astro Config
import { defineConfig } from 'astro/config';
import tailwindcss from '@tailwindcss/vite';
import mdx from '@astrojs/mdx';
import sitemap from '@astrojs/sitemap';

export default defineConfig({
  vite: {
    plugins: [tailwindcss()],
  },
  base: '/',
  integrations: [mdx(), sitemap()],
  site: 'https://shadowdara.github.io'
});
