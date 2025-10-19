---
layout: post
title: 'Bypass Admin'
publishedAt: '2025-10-15'
categories: blog
---

# Bypass Admin

## Info

Code to run a bat File with by passing Admin Rights, which means
suppressing them, does not guranteed work!

Copy Code or [Download File](https://raw.githubusercontent.com/ShadowDara/codefiles/refs/heads/main/bypass_admin.bat)

```cmd
@echo off

@rem Run without Admin Rights
@rem
@rem A Batch Script which allows to run a programm with
@rem bypassing administrator rights

set __COMPAT_LAYER=RunAsInvoker

@rem IMPORTANT: Change the path to your binary here
start steamsetup.exes

echo Binary executed without admin rights.
@pause
```

---

*Please give credit for republishing*
