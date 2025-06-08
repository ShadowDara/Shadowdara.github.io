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
    }
]

interface AllLinksItem {
    id: string; // Assuming item.id is always a string
    link: string;
    name: string;
    blanc: boolean;
}

interface LinkSortData {
    [key: string]: string[];
}

//Sorting for the links
export const link_sort: LinkSortData = {
    "main": [
        "home",
        "upptime",
    ],
    "socials": [
        "discord",
        "reddit",
    ],
    "coding": [
        "github",
        "modrinth",
        "itch_io",
    ],
    /*
    "projects": [],
    "more": [],
    */
    "startpage": [
        "github",
        "modrinth",
        "discord",
        "reddit",
        "linktree",
    ]
}


// Links for the Links Page
export const all_links: AllLinksItem[] = [
    {
        id: "home",
        name: "Home",
        link: `${b}/`,
        blanc: false
    },
    {
        id: "upptime",
        name: "Upptime",
        link: "https://shadowdara.github.io/upptime",
        blanc: true
    },

    {
        id: "github",
        name: "Github",
        link: "https://github.com/shadowdara",
        blanc: true
    },
    {
        id: "modrinth",
        name: "Modrinth",
        link: "https://modrinth.com/user/shadowdara",
        blanc: true
    },
    {
        id: "itch_io",
        name: "Itch.io Profile",
        link: "https://shadowdara.itch.io",
        blanc: true
    },
    {
        id: "discord",
        name: "Discord",
        link: "https://discord.gg/9Jh8B8pkJa",
        blanc: true
    },
    {
        id: "reddit",
        name: "Reddit",
        link: "https://reddit.com/u/shadowdara",
        blanc: true
    },
    {
        id: "linktree",
        name: "Linktree",
        link: "https://linktr.ee/shadowdara",
        blanc: true
    },

    {
        id: "2",
        name: "Fandom.com",
        link: "https://community.fandom.com/wiki/User:Shadowdara",
        blanc: true
    },
    {
        id: "3",
        name: "Lego-Ninjago.Fandom.com",
        link: "https://lego-ninjago.fandom.com/de/wiki/Benutzer:Shadowdara",
        blanc: true
    }
]
