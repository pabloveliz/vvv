It is possible to translate VVV to different languages: it is simply a matter of translating a number of sentences from English to another language. A custom program makes this task very simple. The translated strings are saved in a file and then VVV will be available in that language.

This is a work that needs to be done only once, then the translation will be available to all users. From time to time there will be some new sentences to translate, but they will be few, and only the new sentences will need translation.

Here are some instructions for volunteers interested in translating VVV.

Copy [vvv.po](/translations/empty .po file/vvv.po) the file that contains the sentences to be translated.

Then download and install the [Poedit program](http://www.poedit.net/).

To translate the program open the **vvv.po** file with Poedit; in Windows the simplest way is to double-click **vvv.po**.

Open the **File/Preferences** menu and enter you name and e-mail in the **Personalize** tab for future reference.

Open the **Catalog/Settings** menu and enter your language.

Now you are ready to start the translation. Click a sentence in the upper part of the program window: in the lower part you will see the English sentence and you will be able to type the translated one in the very lower part of the window. Once you have typed a translated sentence you can press CTRL-UP-ARROW or CTRL-DOWN-ARROW in the keyboard to quickly move to another sentence.

When you have translated some sentences you can save the file and exit Poedit. You can read the online help to learn more about Poedit.

When you save, Poedit will create a ***vvv.mo** file. To test your translation create a subfolder in the **languages** folder inside the folder where VVV has been installed. For example, create a folder named `languages\fr` for a French translation or `languages\nl` for a Dutch translation.

Put a copy of **vvv.mo** in that folder and start VVV. You should be able to test VVV in your language.
