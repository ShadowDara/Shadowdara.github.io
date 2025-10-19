---
layout: post
title: 'Firewall and Container Ports'
publishedAt: '2025-10-20'
categories: blog
---

# Firewall and Container Ports

When using a Docker Container or a Server Ports are very important, here are some
Infos and commands to configure them

## Check used PORTS

Shell Command
```sh
sudo lsof -i -P -n | grep LISTEN
```

or on Fedorra
```sh
ss -tuln
``

## Configure the Firewall

Here are some commands to configure the Firewall on Linux

Check the Firewall
```sh
sudo systemctl status firewalld
```

Start the Firewall
```sh
sudo systemctl start firewalld
sudo systemctl enable firewalld
```

Add a PORT to the Firewall Exeption and Reload
```sh
sudo firewall-cmd --add-port=8000/tcp --permanent
sudo firewall-cmd --reload
```

Remove a PORT from the Firewall Exeption and Reload
```sh
sudo firewall-cmd --remove-port=8000/tcp --permanent
sudo firewall-cmd --reload
```

