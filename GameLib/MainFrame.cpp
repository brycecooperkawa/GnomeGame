/**
 * @file MainFrame.cpp
 * @author Matthew Norris
 * @author Austin Stickney
 */

#include "pch.h"
#include "MainFrame.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Sparty Gnome",
           wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto gameView = new GameView();

    gameView->Initialize(this);

    mGameView = gameView;

    // Add it to the sizer
    sizer->Add(gameView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar();

    auto fileMenu = new wxMenu();
    auto levelMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(levelMenu, L"&Level");
    menuBar->Append(helpMenu, L"&Help");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    levelMenu->Append(IDM_LOADLEVEL0, "Load &Level0", L"Load level 0");
    levelMenu->Append(IDM_LOADLEVEL1, "Load &Level1", L"Load level 1");
    levelMenu->Append(IDM_LOADLEVEL2, "Load &Level2", L"Load level 2");
    levelMenu->Append(IDM_LOADLEVEL3, "Load &Level3", L"Load level 3");

    SetMenuBar( menuBar );
    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    mGameView->Stop();
    Close(true);
}

void MainFrame::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}

/**
 * Help menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Sparty Gnome is a platform game created by Matthew "
                 "Norris, Bryce Cooperkawa, Austin Stickney, Logan Gillis, and John Foss.",
            L"About the Sparty Gnome game:",
            wxOK,
            this);
}
