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

#include "virtual_paths.h"

CVirtualPaths::CVirtualPaths(void) {
	PathName = wxEmptyString;
}

CVirtualPaths::~CVirtualPaths(void) {
}


void CVirtualPaths::DBStartQueryListPaths( CNullableLong FathID ) {
	wxString sql;

	if( FathID.IsNull() )
		sql = wxT("SELECT * FROM VIRTUAL_PATHS WHERE FATHER_ID IS NULL ORDER BY UPPER(PATH)");
	else
		sql = wxT("SELECT * FROM VIRTUAL_PATHS WHERE FATHER_ID = ") + CUtils::long2string(FathID) + wxT(" ORDER BY UPPER(PATH)");

	DBStartMultiRowQuery( sql, true );
}

void CVirtualPaths::AppendPhysicalPath( long PhysicalPathID, long VirtualPathID ) {
	switch( DatabaseType ) {
		case dbtFirebird:
			FB_AppendPhysicalPath( PhysicalPathID, VirtualPathID );
			break;
	}
}


void CVirtualPaths::AppendVolume( long VolumeID, long PhysicalPathID, long VirtualPathID ) {
	switch( DatabaseType ) {
		case dbtFirebird:
			FB_AppendVolume( VolumeID, PhysicalPathID, VirtualPathID );
			break;
	}
}

void CVirtualPaths::Rename( long VirtualPathID, wxString newName ) {
	switch( DatabaseType ) {
		case dbtFirebird:
			FB_Rename( VirtualPathID, newName );
			break;
	}
}

void CVirtualPaths::AddPhysicalFile( long PhysicalFileID, long VirtualPathID ) {
	switch( DatabaseType ) {
		case dbtFirebird:
			FB_AddPhysicalFile( PhysicalFileID, VirtualPathID );
			break;
	}
}

wxString CVirtualPaths::GetFullPath( long PathID ) {
	wxString retVal = wxEmptyString;

	switch( DatabaseType ) {
		case dbtFirebird:
			retVal = FB_GetFullPath( PathID );
			break;
	}

	return retVal;
}


