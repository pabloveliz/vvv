/*
	This file is part of VVV (Virtual Volumes View)

	Copyright (C) 2007, the VVV Development team

	Author: Fulvio Senore

    VVV is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    VVV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with VVV; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __AUDIO_METADATA_H__
#define __AUDIO_METADATA_H__

#include <wx/string.h>
#include <wx/arrstr.h>
#include "data_interface/files_audio_metadata.h"

class CAudioMetadata
{
public:

	// reads the metadata from an audio file and stores them in a CFilesAudioMetadata object
	// returns true if it has found some metadata, false if it didn't find any metadata
	static bool ReadAudioMetadata( wxString fileName, CFilesAudioMetadata& metaData );

	// returns true if the extension is one of the handled audio file types
	static bool IsAudioExtension( const wxString &ext );

protected:

	// it will contain the list of handled audio file extensions
	static wxArrayString m_AudioExtensions;
};


#endif

