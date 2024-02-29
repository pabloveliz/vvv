# Windows

First you need to install the wxWidgets library. You can download the source code from http://www.wxwidgets.org/. VVV is currently using version 3.x.
Download the Windows installer and install the library source code. The `docs\msw\install.txt` file contains instructions about compiling the library. It is probably better to compile wxWidgets as a static library to avoid runtime dependencies. You MUST compile a **Unicode** version (it's the default in version 3.x).

VVV uses the TagLib library to read metadata tags from audio files. You can download it from http://developer.kde.org/~wheeler/taglib.html. You need to build it.

Unpack the VVV zip source file: you will have a root folder that contains all the downloaded files.

Now it is time to create the build files. VVV uses [CMake](http://www.cmake.org/) so you need to download it.

Create a folder where you will build the program: it can be inside the source code root folder or in another location.
Run CMake (cmake-gui) to show the user interface. Fill the first two text boxes:

- In **Where is the source code**: select the root folder of the downloaded source code.
- In **Where to build the binaries**: select the folder that you created to build the program.

Press the **Configure** button and chose your compiler from the list. CMake will work for some time, then you will see a list of name/value pairs colored in red. You need to set some of those values:

- Set **wxWidgets_CONFIGURATION** to **mswu*
- Set **wsWidgets_ROOT_DIR** to the path of your wxWidgets library. For example `E:/wxWidgets-3.0.2`
- Set **wxWidgets_LIB_DIR** to the path of the libraries. For example `E:/wxWidgets-3.0.2/lib/vc_lib`
- Select the **wxWidgets_USE_REL_AND_DBG** checkbox so you will create both a debug and release configuration.
- Do not care about **wxWidgets_wxrc_EXECUTABLE**: VVV does not use the setting.
- Set **TAGLIB_INCLUDE_PATH** to the folder that contains the TagLib include files. For example `E:/C_Prg/taglib-1.7/installed_output/include/taglib`.
- Set **TAGLIB_LIB_PATH_DEBUG** to the debug version of the library: this is a file, not a folder. For example `E:/C_Prg/taglib-1.7/installed_output/lib/tagd.lib`.
- Set **TAGLIB_LIB_PATHRELEASE** to the release version of the library: this is a file, not a folder. For example `E:/C_Prg/taglib-1.7/installed_output/lib/tag.lib`.

Click **Configure again**: you should not see red lines any more (if you see red lines correct the wrong values and configure again).
Press the **Generate** button.
CMake has created the build files (for example a Visual Studio solution) in the build folder. You can now open that files with your development system and build the program.

Now that you have built VVV, you need to run it. VVV uses the Firebird relational database (www.firebirdsql.org) to handle catalogs. You can install the full server or use the embedded version.

- If you are going to develop VVV it is simpler to install the full server. Choose the superserver (not classic) version 2.0.x. After installation (a very simple task) VVV will be able to handle catalogs.
- If you prefer not to install the full server you can use the embedded version which ships with the VVV executable. The VVV setup copies vvv.exe and many other files in the installation folder. Simply copy all those files (and subfolders) to the folder where the compiler will save and execute the compiled program. This can be tricky so I recommend installing the full server.


# Linux

## Build wxWidgets

First you need to install the wxWidgets library. You can download the source code from www.wxwidgets.org. VVV is currently using version 3.x.

You need to download the wxGTK source code and compile it. Expand the archive in a folder and read **install-gtk.txt** that contains compilation instructions.

Create two folders, one for a debug build and one for a release one. In each folder you will execute the configure script with different parameters.
Use **--enable-debug** for the debug build.
For the release build I use **--disable-shared** to statically link wxWidgets and reduce dependencies.
You must use **--enable-unicode** to create a Unicode build.

Configure will run and print a summary of the configuration: depending on your system it will use wxWidgets' version of many libraries or the one that is already installed. Using wxWidgets' own version of the libraries will reduce dependencies too.
For example you can run configure with **--with-expat=builtin** to force configure to use the wxWidgets' version of expat instead of the one already installed in your computer. Similar switches are available for other libraries too.

After building the library with make you do not need to install it, unless you prefer to do it.

## Build TagLib

VVV uses the TagLib library to read metadata tags from audio files. You can download it from http://developer.kde.org/~wheeler/taglib.html.

## Get Firebird

VVV uses the [Firebird](http://www.firebirdsql.org/) database to handle catalogs so it must be linked with the libfbembed.so file. VVV uses Firebird as an embedded database manager, so there is no need to install it. [More info here](http://accountingplusplus.blogspot.com/2010/06/firebird-embedded-linux.html).
In order to build VVV you need to prepare a folder containing the Firebird files as described in the link above. Just exclude "vvv" and "vvv-start.sh" that will be added at a second time.

You can obtain the Firebird files in different ways:

- Use the files contained in the VVV precompiled binary.
- Download the Firebird package for your Linux distribution. I build VVV with Firebird 2.0.x. Later versions should work but I have not tested them.
- Build Firebird from sources, it is not difficult. Download version 2.0.x source code and follow [these instructions](http://accountingplusplus.blogspot.com/2010/11/compiling-firebird-in-linux.html).

If you only want to develop VVV and you do not want to distribute the compiled program you can simply install the server using the available package. Then link with the installed libfbembed.so file. You can avoid specifying the folder that contains the Firebird runtime (more on this below) since it is only used to create the binary distribution.

## Get CMake

VVV uses [CMake](http://www.cmake.org/) to create the build files, so you need to install it. It is usually available as a package.
You will need al least version 2.6.

## Build VVV

Now it is finally possible to build VVV. Create a folder that will contain the build files for the release version. I usually create a "build_release" folder into the VVV root source code folder, but you can create it everywhere. I you want you can also create another folder for build files of a debug version.

Now start the CMake GUI: you will see the user interface. Fill the first two text boxes:

- In **Where is the source code**: select the root folder of the downloaded source code.
- In **Where to build the binaries**: select the folder that you created to build the program.

Press the **Configure** button and chose your build environment from the list. You can chose "makefiles" if you only want to build the program. CMake will work for some time, then you will get an error message and you will see a list of name/value pairs colored in red. The error means that CMake has not been able to find some of the needed software, so you need to set it manually in the list. After setting a value press **Configure** again: you will probably get another error, and you will need to set a new value by hand and to repeat the procedure until you do not get errors any more.

Here is a list of the variables that must be set:

- CMAKE_BUILD_TYPE: set to **Debug** or **Release**.
- wxWidgets_CONFIG_EXECUTABLE: it is the path of the wx-config file that matches the VVV build configuration. For example `/media/disco2/wxGTK-3.2.0/buildgtkud/wx-config`.
- FB_LIB: it is the path to libfbembed.so, and it will be used by the linker. For example `/media/disco2/firebird-2.0.6-embedded-runtime/firebird/libfbembed.so`.
- FB_EMBEDDED_PATH: it is the path to the folder that contains the runtime Firebird files as described above. For example `/media/disco2/firebird-2.0.6-embedded-runtime/`.
- TAGLIB_LIB: it is the path to the TagLib library, and it will be used by the linker. For example `/home/fulvio/taglib-1.7/installed/lib/libtag.a`.
- TAGLIB_INCLUDE_PATH: it is the path to the TagLib include files, for example `/home/fulvio/taglib-1.7/installed/include/taglib/`.
- CMAKE_INSTALL_PREFIX: it is the path to a folder that will contain the installed files, ready to be executed.

If some libraries are installed CMake might be able to find some of those paths by itself, otherwise you will have to set them by hand.

Once you do not get errors any more in the configuration stage press the **Generate** button: CMake will create the needed build files in the build folder.
You can use those files to build VVV with the tools that you selected.

Once you have successfully built VVV you can build the **INSTALL** target to create the binary distribution in the install folder, ready to be executed or distributed.


# OS X

Building VVV under OS X is very similar to building it under Linux, so you can read the Linux section for reference. Below you will find the differences from the Linux procedure.

There is one more CMake variable: CMAKE_OSX_ARCHITECTURES. You can set it to **i386**.

After generating the build files you can use them to build the VVV executable.

Once you have successfully built VVV you can build the **INSTALL** target to create the binary distribution in the install folder, ready to be executed.
If you build the PACKAGE target you will create a .dmg file ready for distribution. It will be located in the _CPack_Packages folder into the build folder.


