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

#include "paths.h"

CPaths::CPaths(void) {
	PathName = wxEmptyString;
	PathDescription = wxEmptyString;
}

CPaths::CPaths( long pathID ) {
	DBStartMultiRowQuery( wxT("SELECT * FROM PATHS WHERE PATH_ID = ") + CUtils::long2string(pathID), true );
	while( !IsEOF() ) {
		// this query should return only one row
		DBNextRow();
	}
	// at this point "this" should contain the volume's data
}

CPaths::~CPaths(void) {
}


void CPaths::DBStartQueryListPaths( long VolID, CNullableLong FathID ) {
	wxString sql;

	if( FathID.IsNull() )
		sql = wxT("SELECT * FROM PATHS WHERE VOLUME_ID = ") + CUtils::long2string(VolID) + wxT(" AND FATHER_ID IS NULL ORDER BY UPPER(PATH_NAME)");
	else
		sql = wxT("SELECT * FROM PATHS WHERE VOLUME_ID = ") + CUtils::long2string(VolID) + wxT(" AND FATHER_ID = ") + CUtils::long2string(FathID) + wxT(" ORDER BY UPPER(PATH_NAME)");

	DBStartMultiRowQuery( sql, true );
}


wxString CPaths::GetFullPath( long PathID ) {
	wxString retVal = wxEmptyString;

	switch( DatabaseType ) {
		case dbtFirebird:
			retVal = FB_GetFullPath( PathID );
			break;
	}

	return retVal;
}

void CPaths::UpdateDescription( long PathID, const wxString& descr ) {

	switch( DatabaseType ) {
		case dbtFirebird:
			FB_UpdateDescription( PathID, descr );
			break;
	}
}

wxLongLong CPaths::GetFullSize( long PathID ) {
	wxLongLong retVal = 0;

	switch( DatabaseType ) {
		case dbtFirebird:
			retVal = FB_GetFullSize( PathID );
			break;
	}

	return retVal;
}

