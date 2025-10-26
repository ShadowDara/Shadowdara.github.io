---
layout: post
title: 'Tools'
publishedAt: '2025-10-22'
categories: blog
tag: WindowsStuff
author: Shadowdara
---

# Change File Extension


This is a file to change the file extensions of *(all)* files in the same folder.

- you need a powershell terminal installed for this! *(but on the windows it is usally installed)*

### How

- **Download the [`change_file_extension.ps1`](https://raw.githubusercontent.com/ShadowDara/codefiles/refs/heads/main/change-file-extension.ps1) file** or copy the Code down below!

- *copy it in the folder with the files you need to change the extension*

- then run the file with `Powershell` *(rightclick -> run with Powershell)*!

- first type the old extension, then the new one

- the script will rename every file with the old to the new extension.

```ps1
# script to change the file extension of multiple files

$old_extension = Read-Host "Old File extension: "
$new_extension = Read-Host "New File extension: "

Get-ChildItem *.$old_extension | ForEach-Object {
    Rename-Item $_.FullName -NewName ($_.BaseName + "." + $new_extension)
}

Write-Host "*******************************************************"
Write-Host "*                                                     *"
Write-Host "*                     Finished!                       *"
Write-Host "*                                                     *"
Write-Host "*******************************************************"

Read-Host
```

---

*Please give credit for republishing*
