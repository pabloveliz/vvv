/////////////////////////////////////////////////////////////////////////////
// Name:        dlg_file_information.h
// Purpose:     
// Author:      
// Modified by: 
// Created:     13/10/2011 10:24:01
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLG_FILE_INFORMATION_H_
#define _DLG_FILE_INFORMATION_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dlg_file_information.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/listctrl.h"
////@end includes

#include "window_position.h"
#include "mylistitemdata.h"
#include "mytreeitemdata.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define SYMBOL_CFILEINFORMATIONDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_CFILEINFORMATIONDIALOG_TITLE _("File information")
#define SYMBOL_CFILEINFORMATIONDIALOG_IDNAME ID_CFILEINFORMATIONDIALOG
#define SYMBOL_CFILEINFORMATIONDIALOG_SIZE wxSize(100, 100)
#define SYMBOL_CFILEINFORMATIONDIALOG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * CFileInformationDialog class declaration
 */

class CFileInformationDialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( CFileInformationDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    CFileInformationDialog();
    CFileInformationDialog( wxWindow* parent, wxWindowID id = SYMBOL_CFILEINFORMATIONDIALOG_IDNAME, const wxString& caption = SYMBOL_CFILEINFORMATIONDIALOG_TITLE, const wxPoint& pos = SYMBOL_CFILEINFORMATIONDIALOG_POSITION, const wxSize& size = SYMBOL_CFILEINFORMATIONDIALOG_SIZE, long style = SYMBOL_CFILEINFORMATIONDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_CFILEINFORMATIONDIALOG_IDNAME, const wxString& caption = SYMBOL_CFILEINFORMATIONDIALOG_TITLE, const wxPoint& pos = SYMBOL_CFILEINFORMATIONDIALOG_POSITION, const wxSize& size = SYMBOL_CFILEINFORMATIONDIALOG_SIZE, long style = SYMBOL_CFILEINFORMATIONDIALOG_STYLE );

    /// Destructor
    ~CFileInformationDialog();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin CFileInformationDialog event handler declarations

    /// wxEVT_INIT_DIALOG event handler for ID_CFILEINFORMATIONDIALOG
    void OnInitDialog( wxInitDialogEvent& event );

    /// wxEVT_SIZE event handler for ID_CFILEINFORMATIONDIALOG
    void OnSize( wxSizeEvent& event );

    /// wxEVT_CONTEXT_MENU event handler for ID_LISTCTRL
    void OnListControlContextMenu( wxContextMenuEvent& event );

    /// wxEVT_CHAR event handler for ID_LISTCTRL
    void OnListControlChar( wxKeyEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end CFileInformationDialog event handler declarations

////@begin CFileInformationDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end CFileInformationDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

	// set the volume description
	void SetDescription( const wxString& descr );

	// get the description
	wxString GetDescription( void );

	void SetItemData( MyListItemData* itemData ) { m_ItemData = itemData; }
	void SetItemData( MyTreeItemData* itemData ) { m_TreeItemData = itemData; }

////@begin CFileInformationDialog member variables
    wxListCtrl* m_ListCtrl;
    wxTextCtrl* m_TextCtrl;
    /// Control identifiers
    enum {
        ID_CFILEINFORMATIONDIALOG = 10076,
        ID_LISTCTRL = 10077,
        ID_TEXTCTRL = 10093
    };
////@end CFileInformationDialog member variables

protected:

	// create the list control headers
	void CreateLCHeaders();

	// fill the dialog with data about the current file
	void ShowFileData();

	// fill the dialog with data about the current folder
	void ShowFolderData();

	// add a row to the list control
	// return the index of the inserted row
	int AddLCRow( wxString col0, wxString col1 );

	// set the columns size to a reasonable value
	void ResizeLCColumns();

    // copy a row to the clipboard
    void OnMenuCopyRow( wxCommandEvent& event );    // menu interface
    void DoCopyRow();
    
    // data about the file to be shown
	MyListItemData* m_ItemData;

    // if this dialog is called from the tree control this variable contains data about the selected element
    MyTreeItemData* m_TreeItemData;

	CWindowPosition m_WindowPosition;

};

#endif
    // _DLG_FILE_INFORMATION_H_
