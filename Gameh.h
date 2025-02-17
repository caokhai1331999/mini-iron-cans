#if !defined(GAMEH_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Cao Khai(Casey's disciple) $
   $Notice: (C) Copyright 2024 by Cao Khai, Inc. All Rights Reserved. $
   ======================================================================== */

//Using SDL, SDL_image, standard IO, strings, and file streams
#include <string>
#include <cstring>
#include "SDL2/SDL_timer.h"
#include "Tile.h"
#include "xTank.h"
#include "GamePhysics.h"
#include "PlatformP.h"

global_variable real32 StartTime = 0.0f;
global_variable real32 EndTime = 0.0f;
global_variable real32 TimeElapsed = 0.0f;

global_variable uint8_t FPS = 0;

global_variable int frame[5] = {};
global_variable uint8_t Uframe = 0;
global_variable SDL_Rect camera;
const global_variable real32 StandardFPS = 60.0f;
const global_variable uint32 FRAME_DELAY = 1000/60;
char* Menu[] = {"NEW GAME", "RESUME", "OPTIONS", "EXIT"};

global_variable bool Ucollided = false;
global_variable bool Ecollided = false;


enum STATE{
    // NOTE: How to tell the new game state apart from the current one
    EMPTY, MENU_INIT, GAME_NEW, GAME_RELOADED, PAUSE
};

enum MENUCHOICE{
    NONE = static_cast<uint8_t>(0), NEW_GAME, RESUME, OPTIONS, EXIT
};


struct Game{    

    STATE state;
    float startTime = 0.0f;
    int k = 0;    
    uint8_t pointed_option;
    MENUCHOICE chosen_option;
    Tile* tileSet[TOTAL_TILES] = {};
    
    Position* TankPos = nullptr;    
    PlatformP* Platform = nullptr;
    TankInfo* userTank = nullptr;
    TankInfo* enemyTank = nullptr;
    Game(){
        Platform = new PlatformP;
        userTank = new TankInfo(true);
        enemyTank = new TankInfo[TOTAL_ENEMY_TANK];
        state = MENU_INIT;
        pointed_option = 0;
        chosen_option = NONE;
    };
};

void displayMenu(Game* g);
void get_Menu_choice(Game* g, KeyState* key);
void changeState(Game* g);
bool Start(Game* g);
void ProcessInput(Game* g);
void Update(Game* g, bool done);
void resetGame(Game* g);

// TODO: Complete this part
void runMainScene(Game* g);
void RenderMainScene(Game* g);
//===========================
void Render(Game* g);
void Close(Game* g);

#define GAME_H
#endif
