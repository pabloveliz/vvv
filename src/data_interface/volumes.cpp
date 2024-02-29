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

#include "volumes.h"

CVolumes::CVolumes(void) {
	VolumeName = wxEmptyString;
	VolumeDescription = wxEmptyString;
    PhysicalPath = wxEmptyString;
    CatalogDate = wxInvalidDateTime;
    LastUpdateDate = wxInvalidDateTime;
}

CVolumes::CVolumes( long volumeID ) {
	DBStartMultiRowQuery( wxT("SELECT * FROM VOLUMES WHERE VOLUME_ID = ") + CUtils::long2string(volumeID), true );
	while( !IsEOF() ) {
		// this query should return only one row
		DBNextRow();
	}
	// at this point "this" should contain the volume's data
}

CVolumes::~CVolumes(void) {
}


bool CVolumes::NameExists(void) {
	bool retVal = true;

	switch( DatabaseType ) {
		case dbtFirebird:
			retVal = FB_NameExists();
			break;
	}

	return retVal;
}

long CVolumes::GetIDFromName() {
	long retVal = -1;

	DBStartMultiRowQuery( wxT("SELECT * FROM VOLUMES WHERE VOLUME_NAME = '") + ExpandSingleQuotes(VolumeName) + wxT("'"), true );
	while( !IsEOF() ) {
		// this query should return only one row
		DBNextRow();
		retVal = VolumeID;
	}
	// at this point "this" should contain the volume's data

	return retVal;
}

void CVolumes::DBStartQueryListVolumes(void) {
	DBStartMultiRowQuery( wxT("SELECT * FROM VOLUMES ORDER BY UPPER(VOLUME_NAME)"), true );
}
