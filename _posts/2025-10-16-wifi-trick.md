---
layout: post
title: 'Wifi Trick'
publishedAt: '2025-10-16'
categories: blog
---

# Wifi Trick

This is a simple trick to read the already saved / registrated wlan / wifi passwords from your computer

### How to do it

***Important***

- you need to have the password alrealy registered in your computer
- you need to know your SSID *(the name of the wifi / wlan, e.g. `FritzBox1`)*

You can although copy the code downbelow and safe it as a `.bat` file, after running, it will display all saved in the terminal, *but this is optional.*


**Now start**

1. open `cmd.exe` *(search it via the search bar)*

2. type in `netsh wlan show profile SSID key=clear`

3. replace `SSID` with your network name

4. scroll down to **security settings**

5. search for **Key Content**, this is the saved password

```bat
@echo off

@rem by Shadowdara
@rem a script to read all saved SSIDs

setlocal EnableDelayedExpansion

for /f "tokens=2 delims=:" %%A in ('netsh wlan show profiles ^| findstr "Profil"') do (
    set "profilename=%%A"
    set "profilename=!profilename:~1!"

    echo -----------------------------
    echo Profil: !profilename!
    netsh wlan show profile name="!profilename!" key=clear | findstr "Schlüsselinhalt"
)
echo -----------------------------

echo.
echo Script ended
echo.
```

---

*Please give credit for republishing*
