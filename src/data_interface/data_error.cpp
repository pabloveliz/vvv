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

#include "data_error.h"
#include "../utils.h"

CDataErrorException::CDataErrorException( wxString errMsg, ErrorCause ec ) : runtime_error( CUtils::wx2std(errMsg) ) {

	m_ErrorCode = ec;
}

CDataErrorException::CDataErrorException( const char *errMsg, ErrorCause ec ) : runtime_error( errMsg ) {

	m_ErrorCode = ec;
}

CDataErrorException::ErrorCause CDataErrorException::GetErrorCause() {
	return m_ErrorCode;
}

bool CDataErrorException::ConvertFirebirdError( long gdscode, ErrorCause& ec ) {

	bool retVal = false;

	switch( gdscode ) {
		case 335544558:
			ec = ecCheck;
			retVal = true;
			break;
		case 335544665:
			ec = ecUnique;
			retVal = true;
			break;
		case 335544466:
			ec = ecReferentialIntegrity;
			retVal = true;
			break;
		case 335544721:
			ec = ecServerNotFound;
			retVal = true;
			break;
		case 335544344:
			ec = ecDatabaseNotFound;
			retVal = true;
			break;
		case 335544472:
			ec = ecWrongUsernameOrPassword;
			retVal = true;
			break;
	}

	return retVal;
}
