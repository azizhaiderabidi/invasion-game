#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Queue.h"
#include "Unit.h"
#include "Enemy.h"
#include "Obstacles.h"
#include "Fuel.h"
#include "Boost.h"
#include "Health.h"
#include "Background.h"
#include "Bolster.h"
#include "Bullet.h"
#include "MBullet.h"
#include "Rect.h"
#include "Game.h"
#include "Screen.h"
//#include "Pause.h"
#include "Splash.h"
//#include "GameOver.h"
//#include "MainMenu.h"
#include "shade.h"
#include "Score.h"
//#include "Button.h"
#include "windows.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

/* A game type object controlling all game activities */
Game game;

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() ) //initializing SDL setup
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !game.loadMedia(gRenderer) ) //loading all images to Ltextures and sounds to MixMusics and MixChunks
        {
            printf( "Failed to load media!\n" );
        }
        else
        {

            SDL_Event e;                            //Event handler
            long int frame = 0;                   //Current animation frame
            /* initialize random seed: */
            srand (time(NULL));
            //integer to control game over screen
            int wait = 0;

            while( !game.quit )                          //While application is running
            {

                if(game.spl) //SPLASH SCREENS with intervals
                {
                    game.SPLASH = new Splash(&game.SplashSheet,0,0);
                    game.SPLASH->Render(0,gRenderer);
                    SDL_RenderPresent( gRenderer );   //Update screen every time
                    Sleep(2000);
                    game.SPLASH->Render(1,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(200);
                    game.SPLASH->Render(2,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(200);
                    Mix_PlayMusic(game.gSplash_s,-1);  //First Splash music
                    game.SPLASH->Render(3,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(2000);
                    game.SPLASH->Render(4,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(1000);
                    game.SPLASH->Render(3,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(1600);
                    Mix_PlayMusic(game.gBegin_s,-1);  //Second Splash music
                    game.SPLASH->Render(5,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(100);
                    game.SPLASH->Render(6,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(100);
                    game.SPLASH->Render(7,gRenderer);
                    SDL_RenderPresent( gRenderer );
                    Sleep(8000);
                    game.spl = false;
                    Mix_PauseMusic();  //Pausing Music
                }
                if(game.play==false && game.flag==0) //MAIN MENU SCREEN
                {
                    Mix_ResumeMusic();
                    if(Mix_PlayingMusic()==1 && game.flag2 == 0 )
                    {
                        Mix_PlayMusic(game.gMenu_s,-1);  //Menu Music
                        game.flag2 = 1;
                    }
                    if(Mix_PlayingMusic()==0)
                    {
                        Mix_PlayMusic(game.gMenu_s,-1);
                    }
                    game.over = false;  //Making game over screen off
                    game.MenuScreenGenerator(gRenderer); //Generates MAIN MENU

                    //Get mouse position
                    int x, y;
                    SDL_GetMouseState( &x, &y );
                    game.Buttoneffect(x,y,1,gRenderer); //For button effect when mouse reaches buttons
                    SDL_RenderPresent( gRenderer );

                    while( SDL_PollEvent( &e ) != 0 ){  //For Event Handling

                    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEWHEEL_NORMAL)
                    {

                    if(e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (e.button.button == SDL_BUTTON_LEFT)
                        {
                            game.ButtonClick(x,y,0,gRenderer);  //Check button clicks for 3 different buttons area

                        }
                    }
                }

                }
                }
                if(game.pause)  //PAUSE SCREEN
                {
                    game.PauseScreenGenerator(gRenderer); //Generates Pause screen
                    game.play = false;  //Making play screen off

                    int x, y;
                    SDL_GetMouseState( &x, &y );
                    game.Buttoneffect(x,y,0,gRenderer);
                    SDL_RenderPresent( gRenderer );

                    while( SDL_PollEvent( &e ) != 0 ){

                    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    {

                    if(e.type == SDL_MOUSEBUTTONDOWN)
                    {

                        if (e.button.button == SDL_BUTTON_LEFT)
                        {
                            game.ButtonClick(x,y,1,gRenderer);  //Check button clicks for 4 different buttons area

                        }
                    }
                }


                }
                }
                if(game.over)  //GAME OVER SCREEN
                {

                    game.GameoverScreenGenerator(gRenderer,frame); //Generates game over screen
                    SDL_RenderPresent( gRenderer );

                    Sleep(3000);
                    game.play = false;  //Making play screen off
                    game.over = false;  //Switching game over screen
                    game.flag = 0;      //towards Menu screen
//
                }

                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF ); //Screening
                SDL_RenderClear( gRenderer );   //Clear screen

                if(game.play)   //PLAY PHASE OR SCREEN || MAIN GAME
                {

                while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        game.quit = true;
                    }
                    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

                    //revive player on R press, reset game state
                    if(currentKeyStates[ SDL_SCANCODE_R ] && game.player->get_alive()==false)
                    {

                        game.ClearQueues();
                        game.player->set_alive(true);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_P ])  //Press P for pause
                    {
                        game.pause = true;  //making pause screen on
                        game.flag = 1;  //to avoid Menu screen during pause
                        Mix_PlayMusic(game.gMenu_s,-1);  //replaying Menu music

                    }

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ] || currentKeyStates[ SDL_SCANCODE_D ])
                    {
                        game.player->Move(RIGHT);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_LEFT ]|| currentKeyStates[ SDL_SCANCODE_A ])
                    {
                        game.player->Move(LEFT);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_UP ]|| currentKeyStates[ SDL_SCANCODE_W ])
                    {
                        game.player->Move(UP);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_DOWN ]|| currentKeyStates[ SDL_SCANCODE_S ])
                    {

                        game.player->Move(DOWN);

                    }
                    if(e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        if (e.button.button == SDL_BUTTON_LEFT)  //For fire attack 1
                        {
                            Mix_PlayChannel(-1,game.gBullet1_s,0);  //Bullet1 sound chunk
                            for(int i=0; i<2; i++)  //for two bullets at a time
                            {
                                game.bullet=game.player->Fire(); //calling fire function which initializes bullet
                                if(game.bullet)
                                    game.bullets.Enqueue(game.bullet); //adding bullet to list
                            }
                        }
                        if (e.button.button == SDL_BUTTON_RIGHT) //for Fire attack 2
                        {
                            if(game.M_bullets<50)
                            Mix_PlayChannel(-1,game.gBullet2_s,0); //bullet2 sound chunk

                            for(int i=0; i<2; i++)
                            {
                                game.bullet1=game.player->Fire2(&game.Alienstexture);
                                //50 bullets condition need power up boost to get it back
                                //integer M_Bullets control number of bullets
                                if(game.bullet1 && game.M_bullets<50)
                                {
                                    game.Mbullets.Enqueue(game.bullet1); //adding MBullet to list
                                    game.M_bullets++;
                                }
                            }
                        }
                    }


                }

                game.RandomAllUnitsGenerator(frame);  //Generates all game objects which are supposed to be generated randomly
                game.RenderingBasicObjects(frame,gRenderer); //For rendering basic play screen objects
                game.RenderingObjects(frame,gRenderer); //for rendering game objects

                ++frame; //for different frames
                ++game.fuel; //integer used for executing loops in play screen

                if(game.player->get_alive())  //checking in the end of loop for player status
                ++game.scores;  //Score increases with player sustaining alive in game

                stringstream points;   //To save score as string
                points<<game.scores;

                game.SCORE = new Score(&game.Alienstexture,18,550); //Generating score
                game.SCORE->Render(points.str(),frame ,gRenderer); //passing points as string

                game.HealthChecker(); //check health of player and react on it

                game.CleanObjects();

                SDL_RenderPresent( gRenderer );     //Updating screen in the end of game loop

                if(!game.player->get_alive())  //checking for game over status
                {
                    if(wait == 30)
                    {
                    game.over = true;  //making game over screen on
                    Mix_PlayMusic(game.gMenu_s,-1);  //replaying Menu music
                    wait = 0;
                    }
                    if(wait==1)
                        Mix_PlayChannel(-1,game.gBlast1_s,0);
                    wait++;
                }



                }

            }

            //delete game.player;
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

bool init()  //Initializing SDL
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO  ) < 0 )
    {

        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
                    success = false;
                }

//               Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}


void close()
{
    //Free loaded images
    game.textureFree();  //function free all textures used in game
    delete game.player;  //deleting main player
    game.ClearQueues();  //clearing all game object lists
    game.ClearScreens(); // clear screens
    //Free all the sound effects
    //and free all the music included in game
    game.MusicFree();


    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}



