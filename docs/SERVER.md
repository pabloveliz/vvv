# Network Usage

VVV uses a relational database to store its data. This adds a lot of power to the program because it can handle large amounts of data without problems. The database is available in two versions: embedded and full server.

Each copy of VVV contains the embedded version of the database. This version does not require installation and it is invisible to the user: it is the default version and it can only open catalogs stored in the local hard disks. It cannot open catalog stored in another computer in the network, for a series of good reasons.

Often, when many computers are connected by a network, users would like to share the same catalog among all the networked computers. With VVV this is possible, but you must install a full copy of the database server in a computer. That computer will store the catalogs and it will share them with other computers: we will call it the server. Other computers will connect to the server to access catalogs.


# How to install the database server

You will need to install the database server only if you want to share catalogs among many computers connected by a network. You do not need to install it if you only want to open catalogs stored in your computer.
VVV uses the [Firebird database server](http://www.firebirdsql.org/). It is a free, open source server available for Linux, OS X and Windows computers. You can install the server in a Windows, OS X or Linux computer and all the networked computers will be able to access the server. Windows computers can connect to a Linux server, and OS X computers can connect to a Windows server, for example. You will need version 2.x of the server: you can download it from the Firebird home page.


# Install the server in a Windows computer

The simplest way to install the server is to use the installer: [click here to go to the download page.](https://github.com/pabloveliz/vvv/releases)
VVV has been developed using the 2.0.x version: anyway a newer version should also work.

Installation is very simple: just execute the installer and follow the instructions. If you are not an experienced user it is advisable to accept all the default settings. The installer will ask if you want to run the server as a service or as an application. The simplest way is to run it as a service. It is better to let Firebird start automatically when you start the computer so you will be able to forget about having the server installed.

In order to connect to the server from VVV you will need a username and a password: after installation a Windows server will have a **SYSDBA** username with the password **masterkey**.


# Install the server in a Linux computer

There are different ways to install the server in a Linux computer. First it is better to check if a Firebird package is available for your distribution. If a package is available that is the simplest way to install the server. Be sure to install version 2. The server comes in different flavors: if you are in doubt try installing the classic server. After installation you might want to read the release notes from the link below.

If a package is not available for your distribution you can download the server from the [download page](https://github.com/pabloveliz/vvv/releases) of the official site. VVV has been developed using the 2.0.x version: anyway a newer version should also work.

There are many Linux versions: if you are in doubt download the **classic** one.
You can choose between a rpm package or a .tar.gz file for distributions that do not support rpm packages. You may want to read the release notes linked at the end of the download page for information about installing the server.

In order to connect to the server from VVV you will need a username and a password: after installation a Linux server will have a **SYSDBA** username, but it might have different passwords, depending on the used package. Some packages will ask for a SYSDBA password during installation, others will use a default **masterkey** password, others will create a file containing a random password (/opt/firebird/SYSDBA.password for the official package).


# How to configure VVV

You must change some settings to make VVV connect to the server. Select the **Tools/Options** menu to show the **Settings** window, then click the **Server** tab. Select the **Connect to a network server** checkbox and fill the **Server**, **Username** and **Password** text boxes. Username and Password contain, by default, "SYSDBA" and "masterkey", the default values for a Windows server and some Linux servers.
Enter the name of the server computer in the **Server** textbox. If the server is running in the same computer enter "localhost" (without quotes) instead of the computer name. This makes VVV a little friendlier when opening a catalog.

If you are connecting to a server, opening a catalog works in a slightly different way. When you chose the **Open** command a new window is displayed, asking for the path to the catalog file. Since the catalog is stored in the server, you must type the full path relative to the server, that is the path that you see when you work at the server computer.

So, if the server is a Windows computer, the path "C:\Catalogs\Catalog1.vvv" will point to the "C" disk of the server, not the "C" disk of the client. You must type a Windows path if the server is a Windows computer, even if you are connecting from a Linux computer, and vice versa.

Since usually a client cannot see the files stored in the server you must manually type the path for the first time that you use it. VVV cannot help you showing a "file open" dialog. Then you will be able to find the path in the **File** menu.

If you are using VVV in the server computer and you typed "localhost" in the settings window, VVV will show a browse button at the side of the catalog name to let you visually choose the catalog name. Since VVV is running in the server it can look at the stored files as usual.

Creating a new catalog works in a similar way, but you can do it only if VVV is running in the server computer. Clients usually cannot access files in the server, so they cannot create them.


# Security

These instructions have explained how to connect to a server using the SYSDBA username. This is the simplest way to connect to the server, but it is important to understand that it can cause security problems.

The SYSDBA user has full access to every database stored in the server, so anybody who knows the SYSDBA password can connect to another database, non only a VVV catalog. Then he can read data and even destroy them.

This is usually not a problem if the server only stores VVV catalogs, or if it stores other database containing similar, non-sensitive information. It can be a problem if the server also stores sensitive and important data like accounting or medical information.

It is usually not a problem in a home network where users are trusted, but it can be a problem in a large network where not all users are so trusted.

If security is a problem it is possible to create a new username and give it only the right to access VVV catalogs. People connecting with that username will not be able to access other databases.
If you already have sensitive data stored in the Firebird server you certainly have a server administrator that will be able to add and configure a new username for VVV users.


