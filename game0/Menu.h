#ifndef __MENU__
#define __MENU__

#include "Music.h"
#include "ViewObject.h"
#include "Board.h"
#include <string>

class Menu : public df::ViewObject {
    private:
        df::Music *p_music;
        void start();
        int hasStarted;
        Board* level;

    public:
        Menu();
        int eventHandler(const df::Event *p_e) override;
        int draw() override;
        //void playMusic();
        virtual ~Menu();
};
#endif 