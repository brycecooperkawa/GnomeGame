/**
 * @file MainFrame.h
 * @author Matthew Norris
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_MAINFRAME_H
#define PROJECT1_MAINFRAME_H

#include "GameView.h"

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:
    GameView *mGameView;

public:
    void Initialize();

    void OnExit(wxCommandEvent& event);

    void OnClose(wxCloseEvent& event);

    void OnAbout(wxCommandEvent& event);
};


#endif //PROJECT1_MAINFRAME_H
