---
layout: post
title: 'Edittime to Filename'
publishedAt: '2025-10-21'
categories: blog
tag: WindowsStuff
---

# edittime to filename

a Powershell script to add the edit time in front of a filename to all
files in the running directory. Edit time will NOT be added multiple times

**Format: YYYY-MM-DD**

Download Code [here](https://raw.githubusercontent.com/ShadowDara/codefiles/refs/heads/main/edititme-to-filename.ps1) or copy it

<br>
```ps1
# PowerShell-Skript: Rename files to include edit time (LastWriteTime) as prefix
#
# Credit Shadowdara
# /blog/2025/10/19/edittime-to-filename

$folderPath = Split-Path -Parent $MyInvocation.MyCommand.Definition
Set-Location $folderPath

# Regex-Muster für Datum im Format yyyy.MM.dd
$regex = '^\d{4}\.\d{2}\.\d{2} '

# Alle Dateien im aktuellen Ordner durchgehen
Get-ChildItem -File | ForEach-Object {
    $file = $_

    # Wenn der Name schon mit einem Datum beginnt, überspringen
    if ($file.Name -match $regex) {
        Write-Host "skipping (already has a date): $($file.Name)"
        return
    }

    $editDate = $file.LastWriteTime.ToString("yyyy.MM.dd")
    
    # Neuen Dateinamen zusammensetzen
    $newName = "$editDate $($file.Name)"
    
    # Wenn der neue Name bereits existiert, nicht umbenennen
    if (-not (Test-Path -LiteralPath $newName)) {
        Rename-Item -LiteralPath $file.FullName -NewName $newName
        Write-Host "Renamed: $($file.Name) -> $newName"
    } else {
        Write-Warning "File exists already: $newName - skipping"
    }
}

Write-Host "*******************************************************"
Write-Host "*                                                     *"
Write-Host "*                     Finished!                       *"
Write-Host "*                                                     *"
Write-Host "*******************************************************"

Read-Host
```

<br>

Run the File with Powershell in same Folder as the files you want to rename!
