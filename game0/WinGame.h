#ifndef __WinLevel__
#define __WinLevel__

#include "Music.h"
#include "ViewObject.h"
#include "Board.h"
class WinGame : public df::ViewObject {
    private:
        df::Music *p_music;
        void start();
    public:
        WinGame();
        int eventHandler(const df::Event *p_e) override;
        int draw() override;
        //void playMusic();
        virtual ~Menu();
};

#endif