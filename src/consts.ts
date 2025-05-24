// Place any global data in this file.
// You can import this data from anywhere in your site by using the `import` keyword.

// Base Path
import defineConfig from "../astro.config.mjs";
export const b = "" //defineConfig.base;

// Page Data
export const p = {
    SITE_TITLE: 'Shadowdara - Portfolio',
    SITE_DESCRIPTION: "Welcome to Shadowdara's Personal Portfolio Page!",

    SITE_TITLE_404: '404',
    SITE_DESCRIPTION_404: 'Requested Website not found!',

    SITE_TITLE_blog: "Shadowdara's Blog",
    SITE_DESCRIPTION_blog: "Shadowdara's Personal Blog",
}

// Links for mainpage
export const main_links = [
    {
        name: "Github",
        link: "https://github.com/shadowdara",
        blanc: true
    },
    {
        name: "Modrinth",
        link: "https://modrinth.com/user/shadowdara",
        blanc: true
    },
    {
        name: "Discord",
        link: "https://discord.gg/9Jh8B8pkJa",
        blanc: true
    },
    {
        name: "Reddit",
        link: "https://reddit.com/u/shadowdara",
        blanc: true
    },
    {
        name: "Linktree",
        link: "https://linktr.ee/shadowdara",
        blanc: true
    },
    /*
    {
        name: "Blog",
        link: `${b}/blog`,
        blanc: false
    }
    */
]
