# Welcome to Virtual Volumes View!

VVV is an application that catalogs the content of removable volumes like CD and DVD disks for off-line searching. Folders and files can also be arranged in a single, virtual file system. Each folder of this virtual file system can contain files from many disks so you can arrange your data in a simple and logical way.

VVV also stores metadata information from audio files: author, title, album and so on. Most audio formats are supported.

It is possible to share the same catalog, stored in a network server, among Windows, Linux and OSX computers. The network server is simply a computer running a database server program. [Click here for more info](SERVER.md).

## News for the current version (1.5)

- Now in the **File Information** and **Folder Information** windows it is possible to copy to the clipboard the content of a row  by pressing CTRL-C or by right-clicking with the mouse.
- Removed the **New root folder** context menu from the left pane in virtual mode. It is rarely used and it is still available from the main menu.
- Now the program remembers a search setting between **All physical volumes** and **Selected physical folder**. It does not remember the **Selected virtual folder** setting because at startup there is no selected virtual folder.
- Fixed a bug: the program crashed if the user cataloged a volume using an existing name.

# Translation

- [Looking for more translators](TRANSLATE.md). Translators are welcome for other languages: it is a matter of translating a number of sentences using a helper program. You can contact me if you are interested: contact info at the bottom of this page.
- Some translators are not available any more or they do not have free time, so I also need help for completing the translations to the following languages: Czech, German, Spanish, French, Croatian, Japanese, Polish, Russian, Serbian, Ukrainian. For these languages only a few sentences need to be translated, so this would take much less time than a full translation.

# Features

VVV is available for **Windows**, **Linux** and for **OS X** (Intel only). You can exchange catalogs between Windows, Linux and OS X computers, and you can connect Windows, Linux and OS X computers to the same (Windows,  Linux or OS X) server.

VVV is very fast, even with very large catalogs. Data are stored in a relational database, designed to handle millions of rows, so retrieving your information will always be a quick task.

VVV can show the content of your disks in three different views:

- The first is the physical view, [click here for a Windows screenshot](vvv-physical-windows.gif). This view shows the content of each disk, you can navigate in the folders structure and see the files contained in each folder.
- The second is the virtual view, [click here for a Linux screenshot](vvv-virtual-linux.gif). In this view everything is organized as a single virtual file system. You can create folders and you can assign physical volumes or folders to each virtual folder. You can assign the same file to more than one virtual folder, and each virtual folder can contain files that are stored in different disks. The virtual view is a powerful tool that will let you organize your data in a logical way: it will save you a lot of searches.
- The third is the search view, [click here for a Windows screenshot](vvv-search-windows.gif). In this view you can search the catalog looking for files that meet your specification.

VVV does not change your operating system in any way: everything is contained in the installation folder so you can be sure that it will not cause problems to other applications or to the operating system itself.

You can contact the [original author](mailto:fsenore@ica-net.it). Please make sure that the message subject contains "VVV" for faster processing, For example "Question about VVV".

Many thanks to Danny Muñiz for his help in designing the original web site.

