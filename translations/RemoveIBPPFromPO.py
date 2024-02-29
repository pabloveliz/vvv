# -*- coding: cp1252 -*-
# removes the IBPP lines from the .po files
# no need to translate IBPP messages

import os

def RemoveIBPP( poFile ):
    tmpFile = poFile + ".tmp"

    fin = open( poFile, "rt" )
    fout = open( tmpFile, "wt" )

    skip = False

    line = fin.readline()
    while line != "":

        if not skip:
            if line.find( "/ibpp/" ) >= 0:
                skip = True

        if not skip:
            fout.write( line )

        if skip:
            if line == "\n":
                skip = False

        line = fin.readline()

    fin.close()
    fout.close()

    os.remove( poFile )
    os.rename( tmpFile, poFile )

RemoveIBPP( "empty .po file/vvv.po" )
RemoveIBPP( "vvv-bg.po" )
RemoveIBPP( "vvv-cn.po" )
RemoveIBPP( "vvv-cs.po" )
RemoveIBPP( "vvv-de.po" )
RemoveIBPP( "vvv-es.po" )
RemoveIBPP( "vvv-fr.po" )
RemoveIBPP( "vvv-hr.po" )
RemoveIBPP( "vvv-hu.po" )
RemoveIBPP( "vvv-it.po" )
RemoveIBPP( "vvv-ja.po" )
RemoveIBPP( "vvv-nl.po" )
RemoveIBPP( "vvv-pl.po" )
RemoveIBPP( "vvv-pt.po" )
RemoveIBPP( "vvv-ro.po" )
RemoveIBPP( "vvv-ru.po" )
RemoveIBPP( "vvv-sr.po" )
RemoveIBPP( "vvv-sr@latin.po" )
RemoveIBPP( "vvv-uk.po" )

