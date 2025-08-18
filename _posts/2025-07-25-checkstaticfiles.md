---
layout: post
title: 'Checkstaticfiles'
date: 2025-07-25
categories: blog
---
# Checkstaticfiles

When i tried to make a webserver, i ran into the Issue that i need
static HTML and CSS files for the Website when i distribute the
program.

Obviouly you could use an simple Installer for that!

#### BUT,
is there and Software Installer which works for every Platform?

I am not really sure to be honest.

#### BUT
with an installer thera would be although the problem that you
need to reinstall the full programm when you accidentally delete a
file so i dont this kind of solution

### I made
my own Idea, a package which saves the static files in the binary
and on software start, the program checks if the files are existant. When
they are missing, the program creates them automatically and starts then.

I will although add option that the package will check the file content too,
now it only checks if the file is existant.

[Source Code](https://github.com/shadowdara/checkstaticfiles)
