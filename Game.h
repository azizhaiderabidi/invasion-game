#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Collision.h"
#include "Queue.h"
#include "Unit.h"
#include "Enemy.h"
#include "Obstacles.h"
#include "Fuel.h"
#include "Boost.h"
#include "Health.h"
#include "Background.h"
#include <SDL_mixer.h>
#include "Bolster.h"
#include "Bullet.h"
#include "MBullet.h"
#include "Rect.h"
#include "Screen.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "Pause.h"
#include "Button.h"
#include "Word.h"
#include "Icon.h"
#include "Background1.h"
#include "RBullet.h"

class Game  //this class is controlling different game events and decreases amount of code implemented in int main
{
    public:
        Game(); //constructor
        virtual ~Game(); //destructor
        const int SCREEN_WIDTH = 800;  //window dimension
        const int SCREEN_HEIGHT = 600;
        //bools for controlling screen switching
        bool quit = false;  //to quit screen
        bool play = false;  //for play screen || Main game
        bool pause = false; //for pause screen
        bool over = false;  //for game over screen
        bool spl = true;  //for splash screens
        //loop and conditional flags used in switching screen as well
        int flag = 0;
        int flag2 = 0;
        int M_bullets; //for Mbullets
        int scores;  //game score
        int fuel = 0;  //integer for loop executing while game is playing
         //random integers for random generation of game objects
        int random = 0;
        int random1 = 0;
        int random2 = 0;
        int random3 = 0;
        //Ltextures for different images loading
        LTexture gSpriteSheetTexture;
        LTexture Backgroud;
        LTexture Alienstexture;
        LTexture MenuSheet;
        LTexture MenuTexture;
        LTexture BUTTONsheet;
        LTexture buttonsSheet;
        LTexture shadeSheet;
        LTexture SplashSheet;
        LTexture FontSprite;
        //Screens pointer for games
        Screen* startScreen;
        Screen* Menu;
        Screen* PauseScreen;
        Screen* Shade;
        Screen* SPLASH;
        //Buttons pointer with their respective words
        Button* Start;
        Word* _Start;
        Button* Continue;
        Word* _Continue;
        Button* Exit;
        Word* _Exit;
        Button* Resume;
        Word* _Resume;
        Button* Save;
        Word* _Save;
        Button* Restart;
        Word* _Restart;
        Button* e_xit;
        Word* _exit;
        Word* _gameOver;
        Word* _Points;
        //collision class object to check collision between objects
        Collisions check;
        //lists for each game object
        Queue obstacles;
        Queue bolsters;
        Queue boostbullets;
        Queue powerUps;
        Queue enemies;
        Queue bullets;
        Queue Mbullets;
        Queue Rbullets;
        //All game objects made from base class Unit pointer
        Unit* player; //Main contoller plain
        Unit* health;
        Unit* background;
        Unit* background1;
        Unit* obstacle=NULL;
        Unit* aliens = NULL;
        Unit* powerUp = NULL;
        Unit* boostUp = NULL;
        Unit* enemy= NULL;
        Unit* bullet = NULL;
        Unit* bullet1 = NULL;
        Unit* SCORE = NULL;
        Unit* bulletIcon = NULL;
        Unit* scoreIcon = NULL;
        Unit*bullet2 = NULL;
        //The music that will be played
        Mix_Music *gMenu_s = NULL;
        Mix_Music *gGame_s = NULL;
        Mix_Music *gSplash_s = NULL;
        Mix_Music *gBegin_s = NULL;
        //The sound effects that will be used
        Mix_Chunk *gBlink_s = NULL;
        Mix_Chunk *gClick_s = NULL;
        Mix_Chunk *gBullet1_s = NULL;
        Mix_Chunk *gBullet2_s = NULL;
        Mix_Chunk *gBlast1_s = NULL;
        Mix_Chunk *gBlast2_s = NULL;
        Mix_Chunk *gBlast3_s = NULL;
        Mix_Chunk *gBlastP_s = NULL;
        Mix_Chunk *gBoost_s = NULL;
        Mix_Chunk *gFuel_s = NULL;
        //functions
        void RandomAllUnitsGenerator(long int); //generates game objects randomly
        bool loadMedia(SDL_Renderer* gRenderer); //load all images, sounds
        void RandomUnitsGenerator(int,int); //Some basic objects generator calls in RandomAllUnitsGenerator
        void continueGame();  //to reload saved game
        void saveGame();  //saving current game and quit
        void MenuScreenGenerator(SDL_Renderer*);  //Make MENU Screen
        void GameoverScreenGenerator(SDL_Renderer*,long int); //Make GAMEOVER Screen
        void PauseScreenGenerator(SDL_Renderer* gRenderer); //Make Pause Screen
        void RenderingObjects(long int frame, SDL_Renderer* gRenderer); //render other game objects from lists of each
        void RenderingBasicObjects(long int frame, SDL_Renderer* gRenderer); //Render basic objects of game
        void Buttoneffect(int,int,int,SDL_Renderer* gRenderer); //Button effect when mouse appears on button
        void ButtonClick(int,int,int,SDL_Renderer* gRenderer); //Reacts on mouse click on button
        void HealthChecker();
        void ClearQueues();  //clear all queues used in game
        void CleanObjects(); //for cleaning objects
        void ClearScreens(); // clean screens
        void textureFree();  //free all textures included in game
        void MusicFree();  //free all musics and chunks used in game
        friend class Collisions;  //giving access to collision for this class


};

#endif // GAME_H

