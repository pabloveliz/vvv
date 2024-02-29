/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_file_information.cpp
// Purpose:     
// Author:      
// Modified by: 
// Created:     13/10/2011 10:24:01
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dlg_file_information.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/mstream.h"
#include "wx/imaglist.h"
////@end includes

#include <wx/clipbrd.h>

#include "dlg_file_information.h"
#include "paths.h"
#include "files.h"
#include "virtual_files.h"
#include "virtual_paths.h"
#include "audio_metadata.h"
#include "vvv.h"

#include <vector>

////@begin XPM images
////@end XPM images


/*!
 * CFileInformationDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( CFileInformationDialog, wxDialog )


/*!
 * CFileInformationDialog event table definition
 */

BEGIN_EVENT_TABLE( CFileInformationDialog, wxDialog )

////@begin CFileInformationDialog event table entries
    EVT_INIT_DIALOG( CFileInformationDialog::OnInitDialog )
    EVT_SIZE( CFileInformationDialog::OnSize )
    EVT_BUTTON( wxID_OK, CFileInformationDialog::OnOkClick )
    EVT_BUTTON( wxID_HELP, CFileInformationDialog::OnHelpClick )
////@end CFileInformationDialog event table entries

    EVT_MENU( wxID_COPY, CFileInformationDialog::OnMenuCopyRow )
END_EVENT_TABLE()


/*!
 * CFileInformationDialog constructors
 */

CFileInformationDialog::CFileInformationDialog()
{
    Init();
}

CFileInformationDialog::CFileInformationDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*!
 * CFileInformationDialog creator
 */

bool CFileInformationDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CFileInformationDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end CFileInformationDialog creation

	m_WindowPosition.SetWindow( this );
	m_WindowPosition.RestorePosition();
	
	return true;
}


/*!
 * CFileInformationDialog destructor
 */

CFileInformationDialog::~CFileInformationDialog()
{
////@begin CFileInformationDialog destruction
////@end CFileInformationDialog destruction

	m_WindowPosition.SavePosition();
}


/*!
 * Member initialisation
 */

void CFileInformationDialog::Init()
{
////@begin CFileInformationDialog member initialisation
    m_ListCtrl = NULL;
    m_TextCtrl = NULL;
////@end CFileInformationDialog member initialisation

	m_ItemData = NULL;
    m_TreeItemData = NULL;
}


/*!
 * Control creation for CFileInformationDialog
 */

void CFileInformationDialog::CreateControls()
{    
////@begin CFileInformationDialog content construction
    CFileInformationDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_ListCtrl = new wxListCtrl( itemDialog1, ID_LISTCTRL, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxSUNKEN_BORDER );
    itemBoxSizer2->Add(m_ListCtrl, 3, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_LEFT|wxALL, 5);

    m_TextCtrl = new wxTextCtrl( itemDialog1, ID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
    itemBoxSizer2->Add(m_TextCtrl, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer6 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer6, 0, wxGROW|wxALL, 10);
    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton7);

    wxButton* itemButton8 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton8);

    wxButton* itemButton9 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton9);

    itemStdDialogButtonSizer6->Realize();

    // Connect events and objects
    m_ListCtrl->Connect(ID_LISTCTRL, wxEVT_CONTEXT_MENU, wxContextMenuEventHandler(CFileInformationDialog::OnListControlContextMenu), NULL, this);
    m_ListCtrl->Connect(ID_LISTCTRL, wxEVT_CHAR, wxKeyEventHandler(CFileInformationDialog::OnListControlChar), NULL, this);
////@end CFileInformationDialog content construction
}


/*!
 * wxEVT_SIZE event handler for ID_CFILEINFORMATIONDIALOG
 */

void CFileInformationDialog::OnSize( wxSizeEvent& event )
{
	event.Skip();
	ResizeLCColumns();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void CFileInformationDialog::OnOkClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in CFileInformationDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in CFileInformationDialog. 
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void CFileInformationDialog::OnHelpClick( wxCommandEvent& event )
{
	wxGetApp().GetHelpController()->DisplaySection( wxT("file_information.htm") );
}


/*!
 * Should we show tooltips?
 */

bool CFileInformationDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CFileInformationDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin CFileInformationDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end CFileInformationDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CFileInformationDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin CFileInformationDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end CFileInformationDialog icon retrieval
}

void CFileInformationDialog::CreateLCHeaders() {
	wxListItem itemCol;
	int i = 0;

	itemCol.SetText( _("Name") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	m_ListCtrl->InsertColumn( i++, itemCol );

	itemCol.SetText( _("Value") );
	itemCol.SetAlign( wxLIST_FORMAT_LEFT );
	m_ListCtrl->InsertColumn( i++, itemCol );
}

int CFileInformationDialog::AddLCRow( wxString col0, wxString col1 ) 
{
  	int i = m_ListCtrl->InsertItem( 0, "" );

    // this code is used to set the item's mask
	wxListItem item;
	item.SetId( i );
	m_ListCtrl->GetItem( item );
	item.SetMask( wxLIST_MASK_STATE|wxLIST_MASK_TEXT|wxLIST_MASK_WIDTH );
	m_ListCtrl->SetItem( item );

	m_ListCtrl->SetItem( i, 0, col0 );
	m_ListCtrl->SetItem( i, 1, col1 );
	return i;
}

void CFileInformationDialog::ResizeLCColumns() {
	int x, y;
	int firstColumnWidth = 120;

    if( m_ListCtrl == NULL ) return;

    m_ListCtrl->GetClientSize( &x, &y );
	m_ListCtrl->SetColumnWidth( 0, firstColumnWidth );
	m_ListCtrl->SetColumnWidth( 1, x - firstColumnWidth - 2 );
}

void CFileInformationDialog::SetDescription( const wxString& descr ) {
	m_TextCtrl->SetValue( descr );
}

wxString CFileInformationDialog::GetDescription( void ) {
	return m_TextCtrl->GetValue();
}

void CFileInformationDialog::ShowFileData()
{
	wxASSERT( m_ItemData != NULL );
	m_ListCtrl->DeleteAllItems();

	// each row is inserted at the top, so we add them in reverse order

	wxString s;

	if( CAudioMetadata::IsAudioExtension(m_ItemData->GetExt()) ) {
		if( m_ItemData->GetChannels() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetChannels());
		AddLCRow( _("Channels"), s );
		if( m_ItemData->GetSamplerate() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetSamplerate());
		AddLCRow( _("Sample rate"), s );
		if( m_ItemData->GetBitrate() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetBitrate());
		AddLCRow( _("Bitrate"), s );
		AddLCRow( _("Length"), CUtils::ConvertSecondsToTimeString(m_ItemData->GetLength()) );
		AddLCRow( _("Genre"), m_ItemData->GetGenre() );
		if( m_ItemData->GetNumber() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetNumber());
		AddLCRow( _("Number"), s );
		AddLCRow( _("Comment"), m_ItemData->GetComment() );
		if( m_ItemData->GetYear() == 0 ) s = wxEmptyString; else s = CUtils::long2string(m_ItemData->GetYear());
		AddLCRow( _("Year"), s );
		AddLCRow( _("Title"), m_ItemData->GetTitle() );
		AddLCRow( _("Album"), m_ItemData->GetAlbum() );
		AddLCRow( _("Artist"), m_ItemData->GetArtist() );

		AddLCRow( wxEmptyString, wxEmptyString );
	}

	AddLCRow( _("File date"), m_ItemData->GetDateTime().FormatDate() + wxT(" ") + m_ItemData->GetDateTime().FormatTime() );
    wxLongLong size = m_ItemData->GetSize();
    AddLCRow( _("File size"), CUtils::HumanReadableFileSize(size) + wxT(" (") + CUtils::AddThousandsSeparators(size.ToString()) + wxT(" ") + _("bytes") + wxT(")") );
	AddLCRow( _("File name"), m_ItemData->GetName() );

	AddLCRow( wxEmptyString, wxEmptyString );

	long id;
	std::vector<long> idList = CVirtualFiles::ListVirtualPathIDs( m_ItemData->GetPhysicalFileID() );
	for( size_t k = 0; k < idList.size(); k++ ) {
		id = idList[k];;
		AddLCRow( _("Virtual path"), CVirtualPaths::GetFullPath(id) );
	}

	id = CFiles::GetPathID( m_ItemData->GetPhysicalFileID() );
	AddLCRow( _("Physical path"), CPaths::GetFullPath(id) );
}

void CFileInformationDialog::ShowFolderData()
{
	m_ListCtrl->DeleteAllItems();

    if( m_ItemData != NULL ) {
        // we are showing data for a folder in the list control
    	// each row is inserted at the top, so we add them in reverse order
	    AddLCRow( _("Folder date"), m_ItemData->GetDateTime().FormatDate() + wxT(" ") + m_ItemData->GetDateTime().FormatTime() );
        wxLongLong size = CPaths::GetFullSize( m_ItemData->GetPathFileID() );
        AddLCRow( _("Folder size"), CUtils::HumanReadableFileSize(size) + wxT(" (") + CUtils::AddThousandsSeparators(size.ToString()) + wxT(" ") + _("bytes") + wxT(")") );
	    AddLCRow( _("Folder name"), m_ItemData->GetName() );

	    AddLCRow( wxEmptyString, wxEmptyString );

	    long id;
	    std::vector<long> idList = CVirtualFiles::ListVirtualPathIDs( m_ItemData->GetPhysicalFileID() );
	    for( size_t k = 0; k < idList.size(); k++ ) {
		    id = idList[k];;
		    AddLCRow( _("Virtual path"), CVirtualPaths::GetFullPath(id) );
	    }

	    id = CFiles::GetPathID( m_ItemData->GetPhysicalFileID() );
	    AddLCRow( _("Physical path"), CPaths::GetFullPath(id) );
    }
    else {
        // we are showing data for a folder in the tree control
        wxDateTime dateTime = wxInvalidDateTime;
        
        if( m_TreeItemData->IsVolume() ) {
            if( m_TreeItemData->GetLastUpdateDate().IsValid() ) {
                AddLCRow( _("Last updated"), m_TreeItemData->GetLastUpdateDate().FormatDate() + " " + m_TreeItemData->GetLastUpdateDate().FormatTime() );
            }
            if( m_TreeItemData->GetCatalogDate().IsValid() ) {
                AddLCRow( _("Cataloged"), m_TreeItemData->GetCatalogDate().FormatDate() + " " + m_TreeItemData->GetCatalogDate().FormatTime() );
            }
            wxLongLong size = CPaths::GetFullSize( m_TreeItemData->GetPathID() );
            AddLCRow( _("Volume size"), CUtils::HumanReadableFileSize(size) + wxT(" (") + CUtils::AddThousandsSeparators(size.ToString()) + wxT(" ") + _("bytes") + wxT(")") );
	        AddLCRow( _("Volume name"), m_TreeItemData->GetDesc() );

            // there is no way to get a list of the virtual paths that contain this volume
        }
        else {
            // get data for this folder from the corresponding FILES row
            wxString sql = "SELECT * FROM FILES WHERE PATH_FILE_ID = ";
            sql << m_TreeItemData->GetPathID();
            CFiles file;
            file.DBStartMultiRowQuery( sql, true );
            dateTime = file.DateTime;

	        AddLCRow( _("Folder date"), file.DateTime.FormatDate() + wxT(" ") + file.DateTime.FormatTime() );
            wxLongLong size = CPaths::GetFullSize( file.PathFileID );
            AddLCRow( _("Folder size"), CUtils::HumanReadableFileSize(size) + wxT(" (") + CUtils::AddThousandsSeparators(size.ToString()) + wxT(" ") + _("bytes") + wxT(")") );
	        AddLCRow( _("Folder name"), file.FileName );

	        AddLCRow( wxEmptyString, wxEmptyString );

	        long id;
	        std::vector<long> idList = CVirtualFiles::ListVirtualPathIDs( file.FileID );
	        for( size_t k = 0; k < idList.size(); k++ ) {
		        id = idList[k];;
		        AddLCRow( _("Virtual path"), CVirtualPaths::GetFullPath(id) );
	        }

	        id = m_TreeItemData->GetPathID();
	        AddLCRow( _("Physical path"), CPaths::GetFullPath(id) );
        }
    }



}


/*!
 * wxEVT_INIT_DIALOG event handler for ID_CFILEINFORMATIONDIALOG
 */

void CFileInformationDialog::OnInitDialog( wxInitDialogEvent& event )
{
    CreateLCHeaders();
    bool isFolder;
    if( m_ItemData == NULL ) {
        isFolder = true;
    }
    else {
        isFolder = m_ItemData->IsFolder();
    }
    if( isFolder ) {
        SetTitle( _("Folder information") );
        ShowFolderData();
    }
    else {
        SetTitle( _("File information") );
    	ShowFileData();
    }

	ResizeLCColumns();

    m_TextCtrl->SetFocus();
}

/*!
 * wxEVT_CONTEXT_MENU event handler for ID_LISTCTRL
 */

void CFileInformationDialog::OnListControlContextMenu( wxContextMenuEvent& event )
{
	if( m_ListCtrl->GetSelectedItemCount() <= 0 ) return;

	wxPoint point = event.GetPosition();
	// If from keyboard
	if (point.x == -1 && point.y == -1) {
		wxSize size = GetSize();
		point.x = size.x / 2;
		point.y = size.y / 2;
	} else {
		point = ScreenToClient(point);
	}

	wxMenu menu;
    menu.Append( wxID_COPY, _("Copy to clipboard\tCtrl+C") );
	PopupMenu( &menu, point );
}

void CFileInformationDialog::OnMenuCopyRow( wxCommandEvent& event )
{
    DoCopyRow();
}

void CFileInformationDialog::DoCopyRow()
{
    if( m_ListCtrl->GetSelectedItemCount() <= 0 ) return;

	long item = -1;
	item = m_ListCtrl->GetNextItem( item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    wxString s = m_ListCtrl->GetItemText( item, 1 );

    if( wxTheClipboard->Open() ) {
        wxTheClipboard->SetData( new wxTextDataObject(s) );
        wxTheClipboard->Close();
    }
}

/*!
 * wxEVT_CHAR event handler for ID_LISTCTRL
 */

void CFileInformationDialog::OnListControlChar( wxKeyEvent& event )
{
    if( event.GetKeyCode() == 3 ) {
        //  CTRL+C
        DoCopyRow();
    }
    else {
        event.Skip();
    }
}

