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

#ifndef __MYTREEITEMDATA_H__
#define __MYTREEITEMDATA_H__

// this class implements a custom ItemData class to store information about tree control items

#include "wx/treectrl.h"
#include "data_interface/db_null.h"

class MyTreeItemData : public wxTreeItemData {
public:
	// constructor used for physical folders tree
	MyTreeItemData( const wxString& desc, long VolumeID, long PathID, bool IsVolume, wxString ObjectDescription, const wxString PhysicalPath = "", const wxDateTime &CatalogDate = wxInvalidDateTime, const wxDateTime &LastUpdateDate = wxInvalidDateTime ) : 
	                m_desc(desc), m_VolumeID(VolumeID), m_PathID(PathID), m_IsVolume(IsVolume), m_AlreadyOpened(false), m_ObjectDescription(ObjectDescription), m_PhysicalPath(PhysicalPath), m_CatalogDate(CatalogDate), m_LastUpdateDate(LastUpdateDate) {}
	// constructor used for virtual folders tree
	MyTreeItemData( const wxString& desc, long PathID, CNullableLong PhysicalPathID ) : 
	                m_desc(desc), m_VolumeID(0), m_PathID(PathID), m_PhysPathID(PhysicalPathID), m_IsVolume(false), m_AlreadyOpened(false) {}
	const wxString& GetDesc() const { return m_desc; }
	void SetDesc( const wxString& Descr ) { m_desc = Descr; }
	long GetVolumeID(void) { return m_VolumeID; }
	long GetPathID(void) { return m_PathID; }
	bool IsVolume(void) { return m_IsVolume; }
	bool AlreadyOpened(void) { return m_AlreadyOpened; }
	void SetAlreadyOpened(void) { m_AlreadyOpened = true; }
	CNullableLong& GetPhysPathID(void) { return m_PhysPathID; }
	const wxString& GetObjectDescription() const { return m_ObjectDescription; }
	void SetObjectDescription( const wxString& ObjDescr ) { m_ObjectDescription = ObjDescr; }
    const wxString &GetPhysicalPath() const { return m_PhysicalPath; }
    void SetPhysicalPath( const wxString &path ) { m_PhysicalPath = path; }
    const wxDateTime GetCatalogDate() const { return m_CatalogDate; }
    const wxDateTime GetLastUpdateDate() const { return m_LastUpdateDate; }
private:
	wxString m_desc;
	long m_VolumeID, m_PathID;	// m_VolumeID is not used for the virtual folders tree
	CNullableLong m_PhysPathID;	// only used for the virtual folders tree
	bool m_IsVolume;	// true if this node is a volume and not a folder (only for physical view)
	bool m_AlreadyOpened;	// true if this node has already been opened
	wxString m_ObjectDescription;	// object description
    wxString m_PhysicalPath;        // only used for volumes, it is the physical path of the volume in the file system
    wxDateTime m_CatalogDate, m_LastUpdateDate;
};

#endif
