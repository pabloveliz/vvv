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

// a class to store long values with a possible NULL state

#ifndef __DB_NULL_H__
#define __DB_NULL_H__

class CNullableLong {

protected:

	long value;
	bool is_null;

public:

	CNullableLong(void) { is_null = true; }
	CNullableLong(long value) { is_null = false; this->value = value; }

	void SetNull( bool isNull ) { is_null = isNull; }
	bool IsNull(void) { return is_null; }

	operator long&() { return value; }

};


#endif
