# Picture Mode Maker

[Use here](https://shadowdara.github.io/html/picture-mode-maker/)

HTML for creating Pictures for both ligth and Darkmode

The Website will help you to create this template, add the links for normal, dark and light mode!

(normal can be light or dark mode, because i prefer darkmode, i am using dark mode as normal)

```
<picture>
  <source
    srcset="https://github-readme-stats.vercel.app/api?username=Shadowdara&theme=midnight-purple&show_icons=true"
    media="(prefers-color-scheme: dark)"
  />
  <source
    srcset="https://github-readme-stats.vercel.app/api?username=Shadowdara&theme=midnight-purple&show_icons=true&bg_color=FFE1FA&text_color=000000&title_color=FF00D8"
    media="(prefers-color-scheme: light), (prefers-color-scheme: no-preference)"
  />
  <img height=200 src="https://github-readme-stats.vercel.app/api?username=Shadowdara&theme=midnight-purple&show_icons=true" />
</picture>
```

<picture>
  <source
    srcset="https://github-readme-stats.vercel.app/api?username=Shadowdara&theme=midnight-purple&show_icons=true"
    media="(prefers-color-scheme: dark)"
  />
  <source
    srcset="https://github-readme-stats.vercel.app/api?username=Shadowdara&theme=midnight-purple&show_icons=true&bg_color=FFE1FA&text_color=000000&title_color=FF00D8"
    media="(prefers-color-scheme: light), (prefers-color-scheme: no-preference)"
  />
  <img height=200 src="https://github-readme-stats.vercel.app/api?username=Shadowdara&theme=midnight-purple&show_icons=true" />
</picture>