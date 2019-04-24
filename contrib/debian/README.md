
Debian
====================
This directory contains files used to package pnyd/pny-qt
for Debian-based Linux systems. If you compile pnyd/pny-qt yourself, there are some useful files here.

## pny: URI support ##


pny-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install pny-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your pny-qt binary to `/usr/bin`
and the `../../share/pixmaps/pny128.png` to `/usr/share/pixmaps`

pny-qt.protocol (KDE)

