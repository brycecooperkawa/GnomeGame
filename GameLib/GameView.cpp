/**
 * @file GameView.cpp
 * @author Matthew Norris
 * @author Austin Stickney
 */

#include "pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include <wx/filefn.h>
#include <filesystem>
#include "ids.h"

using namespace std;

/// The framerate the game should attempt to run at
const int FrameTime = 30;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;

/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);

    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnOpenLevel0, this, IDM_LOADLEVEL0);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnOpenLevel1, this, IDM_LOADLEVEL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnOpenLevel2, this, IDM_LOADLEVEL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnOpenLevel3, this, IDM_LOADLEVEL3);

    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyDown, this);
    Bind(wxEVT_KEY_UP, &GameView::OnKeyUp, this);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameTime);

    mStopWatch.Start();
}

/**
 * Draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    // Update the game
    // prevents tunnelling
    while (elapsed > MaxElapsed)
    {
        mGame.Update(MaxElapsed);
        elapsed -= MaxElapsed;
    }

    // Update the game with any remaining time
    if (elapsed > 0)
    {
        mGame.Update(elapsed);
    }

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Virtual pixel stuff
    auto size = GetClientSize();
    auto graphics = shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());
}

void GameView::OnKeyDown(wxKeyEvent& event)
{
    mGame.OnKeyDown(event);
}


void GameView::OnKeyUp(wxKeyEvent& event)
{
    mGame.OnKeyUp(event);
}

/**
* Handle the frame rate of the window
* @param event
*/
void GameView::OnTimer(wxTimerEvent &event)
{
    Refresh();
}

/**
 * Level > Load level 0 menu event
 * @param event Menu event
 */
void GameView::OnOpenLevel0(wxCommandEvent& event)
{
    mGame.SetLevel(0);
}

/**
 * Level > Load level 1 menu event
 * @param event Menu event
 */
void GameView::OnOpenLevel1(wxCommandEvent& event)
{
    mGame.SetLevel(1);
}

/**
 * Level > Load level 2 menu event
 * @param event Menu event
 */
void GameView::OnOpenLevel2(wxCommandEvent& event)
{
    mGame.SetLevel(2);
}

/**
 * Level > Load level 3 menu event
 * @param event Menu event
 */
void GameView::OnOpenLevel3(wxCommandEvent& event)
{
    mGame.SetLevel(3);
}