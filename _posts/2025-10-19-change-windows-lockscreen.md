---
layout: post
title: 'Change Windows Lockscreen'
publishedAt: '2025-10-19'
categories: blog
tag: WindowsStuff
author: Shadowdara
---

# Change Windows Lockscreen

You can change the background of the Windows lockscreen with this Powershell snippet. Via the search bar open a new Administrator Powershell Window and paste the Code down below or download it [here](https://raw.githubusercontent.com/ShadowDara/codefiles/refs/heads/main/change_windows_lockscreen.ps1).

**IMPORATNT**: you need to change the path to your Image !!!

```ps1
# Powershell code to change the LockScreen on Windows 10
# needs Admin rights

$imgPath = "C:\Users\schueler\Downloads\WhatsApp Bild 2025-10-17 um 13.03.03_78d12b26.jpg"
$code = @"
using System.Runtime.InteropServices;

public class LockScreen {
    [DllImport("user32.dll", SetLastError = true)]
    public static extern bool SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);
}
"@

Add-Type $code

$RegPath = "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\PersonalizationCSP"
New-Item -Path $RegPath -Force | Out-Null
Set-ItemProperty -Path $RegPath -Name "LockScreenImagePath" -Value $imgPath
```

---

*Please give credit for republishing*
