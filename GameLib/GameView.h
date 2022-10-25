/**
 * @file GameView.h
 * @author Matthew Norris
 * @author Austin Stickney
 */

#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"

/**
 * Class for the view of our game
 */
class GameView : public wxWindow {

private:
    void OnPaint(wxPaintEvent &event);

    /// An object that describes our game
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

public:
    void Initialize(wxFrame *parent);

    void OnKeyUp(wxKeyEvent &event);

    void OnKeyDown(wxKeyEvent &event);

    void OnTimer(wxTimerEvent &event);

    void OnOpenLevel0(wxCommandEvent& event);

    void OnOpenLevel1(wxCommandEvent& event);

    void OnOpenLevel2(wxCommandEvent& event);

    void OnOpenLevel3(wxCommandEvent& event);

    /**
    * Stop the timer so the window can close
    */
    void Stop() { mTimer.Stop(); }
};

#endif //PROJECT1_GAMEVIEW_H
