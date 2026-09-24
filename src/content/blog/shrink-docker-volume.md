---
title: "Shrink Docker Volume"
pubDate: "September 24 2026"
author: Shadowdara
description: "alittle cool windows script which looks hacky"
---

# How to Completely Shrink the Docker Desktop Data Disk on Windows

This guide explains how to reduce the size of the Docker Desktop data disk on Windows when Docker is using the **WSL 2 backend**.

Docker Desktop stores its Linux filesystem inside a virtual hard disk file, usually called:

```text
ext4.vhdx
```

The file can become very large over time because Docker images, containers, volumes, build cache, and deleted files may leave unused space inside the virtual disk.

> **Important:** There are two different things involved:
>
> 1. Free space **inside** the Docker Linux filesystem.
> 2. The physical size of the `ext4.vhdx` file on Windows.
>
> Running `docker system prune` only frees space inside Docker. To reduce the actual `.vhdx` file on Windows, the virtual disk must also be compacted.

---

## 1. Check the Current Size

First, check how large the Docker data disk is.

The file is commonly located somewhere similar to:

```text
%LOCALAPPDATA%\Docker\wsl\disk\ext4.vhdx
```

You can open the directory with:

```powershell
explorer "$env:LOCALAPPDATA\Docker\wsl\disk"
```

You should see something similar to:

```text
ext4.vhdx
```

Check its size:

```powershell
Get-Item "$env:LOCALAPPDATA\Docker\wsl\disk\ext4.vhdx" |
    Select-Object Name, Length
```

To display the size in GB:

```powershell
$disk = Get-Item "$env:LOCALAPPDATA\Docker\wsl\disk\ext4.vhdx"
"{0:N2} GB" -f ($disk.Length / 1GB)
```

---

# 2. Clean Up Docker

Before compacting the virtual disk, remove everything that Docker no longer needs.

> **Warning:** The following commands can delete unused Docker resources. Make sure you do not need unused images, stopped containers, networks, or volumes before proceeding.

Start with:

```powershell
docker system df
```

This shows how much space Docker is currently using.

Example:

```text
TYPE            TOTAL     ACTIVE    SIZE      RECLAIMABLE
Images          20        3         15GB      10GB
Containers      10        2         2GB       1GB
Local Volumes   15        5         20GB      12GB
Build Cache     ...                 ...       ...
```

---

## 3. Remove Unused Docker Resources

### Remove stopped containers

```powershell
docker container prune
```

### Remove unused networks

```powershell
docker network prune
```

### Remove unused images

To remove dangling images:

```powershell
docker image prune
```

To remove all images that are not currently used by a container:

```powershell
docker image prune -a
```

### Remove unused volumes

Be careful with this command:

```powershell
docker volume prune
```

Volumes can contain important application data.

Only remove them if you are certain that the data is no longer required.

---

# 4. Clean Everything at Once

If you are certain that all unused Docker resources can be deleted, you can use:

```powershell
docker system prune -a --volumes
```

This removes:

- stopped containers
- unused networks
- unused images
- build cache
- unused volumes

Docker will ask for confirmation.

```text
WARNING! This will remove:
...
Are you sure you want to continue? [y/N]
```

Enter:

```text
y
```

Afterwards, check the result:

```powershell
docker system df
```

---

# 5. Stop Docker Desktop Completely

Docker must not be using the virtual disk while it is being compacted.

First quit Docker Desktop.

You can do this from the Docker Desktop tray icon:

```text
Docker Desktop
    -> Quit Docker Desktop
```

Then make sure Docker Desktop is no longer running.

You can also check:

```powershell
Get-Process *docker* -ErrorAction SilentlyContinue
```

Ideally, no Docker Desktop processes should still be running.

---

# 6. Shut Down WSL Completely

Even after Docker Desktop has been closed, WSL may still have running distributions.

Run:

```powershell
wsl --shutdown
```

This shuts down all running WSL 2 instances.

You can verify the state with:

```powershell
wsl --list --verbose
```

The distributions should not be running.

For example:

```text
  NAME              STATE           VERSION
* docker-desktop    Stopped         2
```

---

# 7. Make a Backup of `ext4.vhdx`

Before modifying the virtual disk, create a backup.

For example:

```powershell
Copy-Item `
    "$env:LOCALAPPDATA\Docker\wsl\disk\ext4.vhdx" `
    "$env:USERPROFILE\Desktop\ext4-docker-backup.vhdx"
```

Depending on the size of the Docker disk, this can take a while.

Do not continue until the copy has completed successfully.

---

# 8. Compact the VHDX

There are multiple ways to compact the Docker VHDX.

The preferred Windows tool is `diskpart`.

Open **PowerShell or Command Prompt as Administrator**.

Start DiskPart:

```powershell
diskpart
```

You should see:

```text
Microsoft DiskPart version ...

DISKPART>
```

---

## 9. Select the Docker VHDX

Inside DiskPart, use:

```text
select vdisk file="C:\Users\<USERNAME>\AppData\Local\Docker\wsl\disk\ext4.vhdx"
```

Replace:

```text
<USERNAME>
```

with your Windows username.

For example:

```text
select vdisk file="C:\Users\John\AppData\Local\Docker\wsl\disk\ext4.vhdx"
```

If your Windows installation is on another drive, use the corresponding path.

---

# 10. Compact the Virtual Disk

Once the VHDX has been selected, run:

```text
compact vdisk
```

DiskPart should report something similar to:

```text
100 percent completed

DiskPart successfully compacted the virtual disk file.
```

Then exit:

```text
exit
```

---

# 11. Check the Result

Check the file size again:

```powershell
$disk = Get-Item "$env:LOCALAPPDATA\Docker\wsl\disk\ext4.vhdx"
"{0:N2} GB" -f ($disk.Length / 1GB)
```

You can also check it in Explorer:

```powershell
explorer "$env:LOCALAPPDATA\Docker\wsl\disk"
```

For example, before cleanup:

```text
ext4.vhdx
Size: 80 GB
```

After cleanup and compaction:

```text
ext4.vhdx
Size: 25 GB
```

The exact result depends on how much data was actually removed.

---

# 12. Start Docker Desktop Again

Start Docker Desktop normally.

Wait until Docker reports that it is running.

Then test:

```powershell
docker version
```

And:

```powershell
docker ps
```

Your containers, images, and volumes that were not removed should still be available.

---

# 13. Verify Docker Storage

Run:

```powershell
docker system df
```

This lets you verify how much Docker is actually using.

You can also check the VHDX again:

```powershell
$disk = Get-Item "$env:LOCALAPPDATA\Docker\wsl\disk\ext4.vhdx"
"{0:N2} GB" -f ($disk.Length / 1GB)
```

---

# 14. Optional: Check the VHDX Before and After

A convenient way to document the result is:

```powershell
$disk = Get-Item "$env:LOCALAPPDATA\Docker\wsl\disk\ext4.vhdx"

[PSCustomObject]@{
    File = $disk.FullName
    SizeGB = [math]::Round($disk.Length / 1GB, 2)
}
```

Example output:

```text
File                                                   SizeGB
----                                                   ------
C:\Users\John\AppData\Local\Docker\wsl\disk\ext4.vhdx  24.73
```

---

# 15. Complete Procedure

If you want the process as a short checklist:

```text
1. Check current ext4.vhdx size
2. Check Docker storage
3. Remove unused Docker resources
4. Quit Docker Desktop
5. Run: wsl --shutdown
6. Back up ext4.vhdx
7. Start DiskPart as Administrator
8. select vdisk file="...\ext4.vhdx"
9. compact vdisk
10. exit
11. Start Docker Desktop
12. Verify Docker
13. Check the new ext4.vhdx size
```

---

# 16. Recommended Commands

The complete command sequence is approximately:

```powershell
# Check Docker usage
docker system df

# Optional cleanup
docker system prune -a --volumes

# Shut down WSL
wsl --shutdown
```

Then, from an **Administrator PowerShell/CMD**:

```text
diskpart
```

Inside DiskPart:

```text
select vdisk file="C:\Users\<USERNAME>\AppData\Local\Docker\wsl\disk\ext4.vhdx"
compact vdisk
exit
```

Then start Docker Desktop again.

---

# 17. Important: `docker system prune` Is Not Enough

A common misconception is that:

```powershell
docker system prune -a --volumes
```

will automatically make the `ext4.vhdx` file smaller.

It usually does **not**.

For example:

```text
Before cleanup:

ext4.vhdx = 100 GB

Docker uses:
30 GB

Unused space:
70 GB
```

After Docker cleanup:

```text
Docker uses:
30 GB

Unused space:
70 GB

ext4.vhdx:
still approximately 100 GB
```

After compacting the VHDX:

```text
Docker uses:
30 GB

ext4.vhdx:
approximately 30–40 GB
```

The exact size depends on the filesystem layout and how much unused space can be reclaimed.

---

# 18. If `compact vdisk` Does Not Reduce the Size

If `compact vdisk` reports success but the file barely gets smaller, there may still be allocated blocks inside the Linux filesystem.

In that situation, first make sure Docker resources have actually been removed:

```powershell
docker system df
```

Then shut everything down again:

```powershell
wsl --shutdown
```

After that, retry:

```text
diskpart
select vdisk file="C:\Users\<USERNAME>\AppData\Local\Docker\wsl\disk\ext4.vhdx"
compact vdisk
exit
```

If the VHDX still does not shrink sufficiently, an additional filesystem-level optimization may be necessary.

---

# 19. Important Difference: Dynamic VHDX vs. Maximum Size

The `ext4.vhdx` file is normally a dynamically expanding virtual disk.

This means:

```text
Virtual disk capacity
        !=
Physical file size
```

For example:

```text
Virtual capacity:    1 TB
Physical file size:  40 GB
```

does not mean that 1 TB is actually consuming 1 TB on your Windows drive.

The important value for Windows disk usage is the **physical file size**.

---

# 20. Do Not Delete `ext4.vhdx` Manually

Do **not** simply delete:

```text
ext4.vhdx
```

unless you intentionally want to destroy the Docker Desktop WSL data.

Deleting the file can remove:

- Docker images
- Docker containers
- Docker volumes
- container filesystem data
- Docker build cache
- other Docker Desktop data

If you only want to reclaim disk space, use cleanup + VHDX compaction instead.

---

# 21. Recommended Safe Workflow

For production or otherwise important Docker environments, use this workflow:

```text
                    ┌─────────────────────┐
                    │ Check Docker usage  │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Backup important    │
                    │ Docker volumes/data │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Remove unused Docker │
                    │ resources            │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Quit Docker Desktop │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ wsl --shutdown     │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Compact ext4.vhdx  │
                    │ with DiskPart      │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Start Docker       │
                    │ Desktop again      │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Verify containers  │
                    │ and volumes        │
                    └─────────────────────┘
```

---

# 22. One-Liner to Find the Docker VHDX

If you are unsure where the Docker VHDX is located, try:

```powershell
Get-ChildItem "$env:LOCALAPPDATA\Docker" -Filter *.vhdx -Recurse -ErrorAction SilentlyContinue |
    Select-Object FullName, Length
```

This searches the Docker directory for VHDX files.

---

# 23. Final Notes

The safest general approach is:

```text
Docker cleanup
      ↓
Docker Desktop shutdown
      ↓
WSL shutdown
      ↓
VHDX backup
      ↓
DiskPart compact
      ↓
Docker Desktop restart
      ↓
Verification
```
