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

#ifndef __WXMSW__
#include<errno.h>
#endif

#include "utils.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/filefn.h>

#include <iostream>

wxString CUtils::applicationName = wxT("VVV");
wxString CUtils::applicationVersion = wxT("1.5.0.0");
int CUtils::expectedDatabaseVersion = 23;
int CUtils::firstUnicodeDatabaseVersion = 14;
wxString CUtils::strucUpdateDbName = wxT("vvv-struct-update.fdb");

// will be changed to the correct value by the first function call
wxChar CUtils::m_thousandsSeparator = 'x';

//-----------------------------------------------------------------------------
//! converts wxString to std::string
std::string CUtils::wx2std(const wxString& input, wxMBConv* conv)
{
    if (input.empty())
        return "";
    if (!conv)
        conv = wxConvCurrent;
    const wxWX2MBbuf buf(input.mb_str(*conv));
    // conversion may fail and return 0, which isn't a safe value to pass 
    // to std:string constructor
    if (!buf)
        return "";
    return std::string(buf);
}
//-----------------------------------------------------------------------------
//! converts std:string to wxString
wxString CUtils::std2wx(const std::string& input, wxMBConv* conv)
{
    if (input.empty())
        return wxEmptyString;
    if (!conv)
        conv = wxConvCurrent;
    return wxString(input.c_str(), *conv);
}


// string conversion for database access
// the database uses UTF8 encoding
std::string CUtils::DBwx2std( const wxString& input ) {
	std::string s = wx2std( input, &wxConvUTF8 );
	return wx2std( input, &wxConvUTF8 );
}
wxString CUtils::DBstd2wx( const std::string& input ) {
	return std2wx( input, &wxConvUTF8 );
}


wxString CUtils::UTF162wx( const char *strUTF16 ) {
	wxString retVal;
#if SIZEOF_WCHAR_T == 2
	wxString s( (wxChar*) strUTF16 );
	retVal = s;
#else
	wxMBConvUTF16 converter ;
	wchar_t *uniChars = new wchar_t[1024];
	int n = converter.MB2WC( uniChars, (const char *) strUTF16, 1000 );
	wxString s( (wxChar*) uniChars );
	retVal = s;
	delete uniChars;
#endif
	return retVal;
}


void CUtils::MsgErr( wxString errMsg ){
	wxMessageDialog dialog( NULL, errMsg, applicationName, wxOK|wxICON_ERROR );
	dialog.ShowModal();
}

void CUtils::MsgStderr( wxString errMsg ){
#ifdef __WXMSW__
	MsgErr( errMsg );
#else
	std::cerr << wx2std( errMsg ) << "\n";
#endif
}

void CUtils::MsgInfo( wxString infoMsg ){
	wxMessageDialog dialog( NULL, infoMsg, applicationName, wxOK|wxICON_INFORMATION );
	dialog.ShowModal();
}

bool CUtils::MsgAskNo( wxString msg ){
	wxMessageDialog dialog( NULL, msg, applicationName, wxYES_NO|wxNO_DEFAULT|wxICON_EXCLAMATION );
	return dialog.ShowModal() == wxID_YES;
}

bool CUtils::MsgAskYes( wxString msg ){
	wxMessageDialog dialog( NULL, msg, applicationName, wxYES_NO|wxYES_DEFAULT|wxICON_EXCLAMATION );
	return dialog.ShowModal() == wxID_YES;
}

wxString CUtils::HumanReadableFileSize( wxLongLong size ) {
	wxString retVal;

	if( size > 1024*1024 ) {
		size = size / (1024*1024);
		retVal = AddThousandsSeparators(size.ToString()) + wxT(" MB");
	}
	else {
		if( size > 1024 ) {
			size = size / 1024;
			retVal = AddThousandsSeparators(size.ToString()) + wxT(" KB");
		}
		else {
			retVal = AddThousandsSeparators(size.ToString());
		}
	}

	return retVal;
}


wxString CUtils::GetApplicationName(void) {
	return applicationName;
}

wxString CUtils::GetApplicationVersion(void) {
	return applicationVersion;
}

int CUtils::GetExpectedDatabaseVersion(void) {
	return expectedDatabaseVersion;
}

int CUtils::GetFirstUnicodeDatabaseVersion(void) {
	return firstUnicodeDatabaseVersion;
}

wxString CUtils::GetStructUpdateDbName(void) {
	wxString appPath = wxStandardPaths::Get().GetExecutablePath();
	wxFileName fn( appPath );
	fn.SetFullName( strucUpdateDbName );
	wxString fullName = fn.GetFullPath();
	return fullName;
}


// converts a long to a string
wxString CUtils::long2string( long val ) {
	wxString retVal;
	retVal.Printf( wxT("%ld"), val );
	return retVal;
}



wxString CUtils::Encrypt( wxString s ) {
	wxString key = "w2m5t7i0g4ndnra5s4lfdpvlyrepfjemwksdjfrpwuanrtogbjentruglk60947235128";
	wxString sout( ' ', s.Len() );
	size_t k;

	for( k = 0; k < s.Len(); k++ ) {
		char ch = static_cast<char>(s[k]) ^ static_cast<char>(key[k % key.Len()]);
		sout[k] = ch;
	}

	return sout;
}

wxString CUtils::GetHelpFileName(void) {
	wxString appPath = wxStandardPaths::Get().GetExecutablePath();
	wxFileName fn( appPath );
	fn.SetFullName( wxT("vvv") );
	wxString fullName = fn.GetFullPath();
	return fullName;
}

bool CUtils::FileIsLink( wxString fileName ) {
#ifdef __WXMSW__
	// Windows does not have symlinks
	return false;
#else
	wxStructStat buf;

	// remove trailing path separator if any
	wxString sep( wxFileName::GetPathSeparator() );
	if( fileName.EndsWith(sep) ) {
		fileName = fileName.Left( fileName.Len() - 1 );
	}

	if( wxLstat(fileName, &buf) == 0 ) {
		bool r = S_ISLNK(buf.st_mode);
		return r;
	}
	else
		return false;
#endif
}

wxBitmap CUtils::EnlargeBitmap( wxBitmap bmpIn, int w, int h )
{
	wxImage img = bmpIn.ConvertToImage();
	int wOrg = img.GetWidth();
	int hOrg = img.GetHeight();

	wxASSERT( w > wOrg );
	wxASSERT( h > hOrg );

	wxSize size( w, h );
	wxPoint pos( (w - wOrg)/2, (h - hOrg)/2 );	// center original bitmap in the new image
	img.Resize( size, pos );
	return wxBitmap( img );
}

wxString CUtils::ExpandSingleQuotes( wxString txt ) {
	// doubles single-quote characters in a string, used to create SQL statements

	txt.Replace( wxT("'"), wxT("''"), true );
	return txt;
}

wxString CUtils::ConvertSecondsToTimeString( int seconds )
{
	int h, m, s;
	h = m = 0;
	s = seconds;
	while( s >= 60 ) {
		s -= 60;
		m++;
	}
	while( m >= 60 ) {
		m -= 60;
		h++;
	}
	wxDateTime dt( h, m, s );
	wxString sl = dt.FormatTime();
	wxString stmp;
	if( sl.StartsWith(wxT("0.0"), &stmp) )
		sl = stmp;
	else {
		if( sl.StartsWith(wxT("0."), &stmp) )
			sl = stmp;
	}
	return sl;
}

wxIcon CUtils::GetIconForPane( const char *xpm[], const wxArtID &id )
{
    wxIcon r;
    wxIcon icoProv = wxArtProvider::GetIcon( id, wxART_OTHER, wxSize(16, 16) );
    if( icoProv.IsOk() ) {
    	r = icoProv;
    }
    else {
	    wxIcon ico( xpm );
	    r = ico;
    }
    return r;
}

void CUtils::SetThousandsSeparators()
{
    if( m_thousandsSeparator == 'x' )
    {
        // discover the right decimal separator for this computer's settings
        wxChar m_decimalSeparator;
        wxString stmp = wxString::Format( wxT("%.1f"), 1.2 );
        m_decimalSeparator = stmp[1];
        // set the thousands separator (hope this way is right)
        if( m_decimalSeparator == '.' )
            m_thousandsSeparator = ',';
        else
            m_thousandsSeparator = '.';
    }
}

wxString CUtils::AddThousandsSeparators( const wxString &s )
{
    SetThousandsSeparators();

    wxString intPart = s;
    int n3 = 0;
    wxString intPartNew = wxEmptyString;
    int minIdx = 0;
    if( intPart[0] == '-' ) minIdx = 1;
    for( int k = intPart.Len() - 1; k >= minIdx; k-- )
    {
        intPartNew = intPart[k] + intPartNew;
        n3++;
        if( n3 == 3 )
        {
            if( k > minIdx )
                intPartNew = m_thousandsSeparator + intPartNew;
            n3 = 0;
        }
    }
    if( minIdx == 1 ) intPartNew = intPart[0] + intPartNew;

    return intPartNew;
}


