#include "Game.h"

Game::Game()  //Some basic game objects are initialized in constructor
{
    player = new Unit(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);//storing the player plane
    health = new Health(&gSpriteSheetTexture, 730, 550);
    bulletIcon = new Icon(&Alienstexture,750,500);
    scoreIcon = new Icon(&Alienstexture,0,539);
    background = new Background(&Backgroud, 0, 0);
    background1 = new Background1(&Backgroud, 0, -599);
}

Game::~Game()
{

}

void Game::RandomUnitsGenerator(int random, int random2)  //Generates three main enemies of game
{
    enemy= new Enemy(&gSpriteSheetTexture, random, 0);
    enemies.Enqueue(enemy);
    obstacle= new Obstacles(&gSpriteSheetTexture, random, 0);
    obstacles.Enqueue(obstacle);
    if(fuel%200==0)
    {
    aliens = new Bolster(&Alienstexture,random2,0);
    bolsters.Enqueue(aliens);
    }

}

bool Game::loadMedia(SDL_Renderer* gRenderer)
{
    //cout<<"Loading success flag 1"<<endl;
    bool success = true;

    //Load sprite sheet texture
    if( !gSpriteSheetTexture.LoadFromFile( "Images/1948.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !MenuSheet.LoadFromFile( "Images/gameover.png", gRenderer ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !buttonsSheet.LoadFromFile( "Images/splash1.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !MenuTexture.LoadFromFile( "Images/MENU.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !shadeSheet.LoadFromFile( "Images/shade.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !Backgroud.LoadFromFile( "Images/background.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !Alienstexture.LoadFromFile( "Images/second.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    if( !SplashSheet.LoadFromFile( "Images/s1.png", gRenderer  ) )
    {
        printf( "Failed to s111!\n" );
        success = false;
    }

    if( !BUTTONsheet.LoadFromFile( "Images/buttons.png", gRenderer  ) )
    {
        printf( "Failed to s111!\n" );
        success = false;
    }

    if( !FontSprite.LoadFromFile( "Images/fontSprite.png", gRenderer  ) )
    {
        printf( "Failed to s111!\n" );
        success = false;
    }

    //Load music
    gMenu_s = Mix_LoadMUS( "Sounds/Menu.wav" );
    if( gMenu_s == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gGame_s = Mix_LoadMUS( "Sounds/game.wav" );
    if( gGame_s == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gSplash_s = Mix_LoadMUS( "Sounds/invas.wav" );
    if( gSplash_s == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gBegin_s = Mix_LoadMUS( "Sounds/begin.wav" );
    if( gBegin_s == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
//
//    //Load sound effects
//    gClick_s = Mix_LoadWAV( "Sounds/click.wav" );
//    if( gClick_s == NULL )
//    {
//        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//        success = false;
//    }
    gBullet2_s = Mix_LoadWAV( "Sounds/Fire2.wav" );
    if( gBullet2_s == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gBullet1_s = Mix_LoadWAV( "Sounds/Fire1.wav" );
    if( gBullet1_s == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gBlast1_s = Mix_LoadWAV( "Sounds/blast3.wav" );
    if( gBlast1_s == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gBlast2_s = Mix_LoadWAV( "Sounds/blast2.wav" );
    if( gBlast2_s == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
//    gBlast3_s = Mix_LoadWAV( "Sounds/blast3.wav" );
//    if( gBlast3_s == NULL )
//    {
//        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//        success = false;
//    }
//    gBlastP_s = Mix_LoadWAV( "Sounds/playerblaast.wav" );
//    if( gBlastP_s == NULL )
//    {
//        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
//        success = false;
//    }
    gBoost_s = Mix_LoadWAV( "Sounds/boost.wav" );
    if( gBoost_s == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
    gFuel_s = Mix_LoadWAV( "Sounds/fuel.wav" );
    if( gFuel_s == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    return success;
}


void Game::ClearQueues()
{
    bullets.Clear();
    enemies.Clear();
    obstacles.Clear();
    bolsters.Clear();
    powerUps.Clear();
    Mbullets.Clear();
    delete player;

}

void Game::CleanObjects()
{
    bullets.Dequeues();
    enemies.Dequeues();
    obstacles.Dequeues();
    bolsters.Dequeues();
    powerUps.Dequeues();
    Mbullets.Dequeues();
    Rbullets.Dequeues();

}

void Game::ClearScreens()
{
    delete startScreen;
    startScreen = NULL;
    delete Menu;
    Menu = NULL;
    delete PauseScreen;
    PauseScreen = NULL;
    delete SPLASH;
    SPLASH = NULL;
}


void Game::saveGame()
{
    ofstream editfile;  //file i/o
    editfile.open("savedGame.txt");
    editfile<<player->get_x()<<endl; //writing x and y pos of player in file
    editfile<<player->get_y()<<endl;
    editfile<<player->myHealth<<endl; //writing health integer for player
    editfile<<scores<<endl;  //writing scores
    editfile<<M_bullets<<endl;  //writing bullets quantity
    editfile<<"D"<<endl;  //for indication of enemies positions
    if(enemies.length()!=0)
    {
    Node* s= enemies.head;
    while(s)
    {
        if(s->unit->get_alive()){
        editfile<<s->unit->get_x()<<endl;  //writing pos x and y of each enemy in list
        editfile<<s->unit->get_y()<<endl;
        }
        s=s->prev;
    }
    }
    editfile<<"E"<<endl;
    if(obstacles.length()!=0)
    {
    Node* s= obstacles.head;
    while(s)
    {
        if(s->unit->get_alive()){
        editfile<<s->unit->get_x()<<endl;  //writing x and y pos of each obstacle from list of obstacles
        editfile<<s->unit->get_y()<<endl;}
        s=s->prev;
    }
    }
    editfile<<"F"<<endl;
    if(bolsters.length()!=0)
    {
    Node* s= bolsters.head;
    while(s)
    {
        if(s->unit->get_alive()){
        editfile<<s->unit->get_x()<<endl;  //writing x and y pos of each bolster from list of bolsters
        editfile<<s->unit->get_y()<<endl;}
        s=s->prev;
    }
    }

    editfile<<"G"<<endl;  //ending file

}
void Game::continueGame()
{
    ifstream readfile;  //file i/o
    string content;  //to read lines in saved file
    readfile.open("savedGame.txt");
    if(readfile.is_open()){




    getline(readfile,content);  //get each line one by one and save it to content
    player->set_x(atof(content.c_str()));  //setting player positions correspondingly
    getline(readfile,content);
    player->set_y(atof(content.c_str()));
    getline(readfile,content);
    player->set_health(atoi(content.c_str()));   //setting other attributes of plane and game
    getline(readfile,content);
    scores = (atoi(content.c_str()));
    getline(readfile,content);
    M_bullets = atoi(content.c_str());
    getline(readfile,content);
    getline(readfile,content);
    while(content!="E")  //indication that positions for enemies are there
    {
        //cout<<"setting"<<endl;
        enemy= new Enemy(&gSpriteSheetTexture, 0, 0);
        enemy->set_x(atoi(content.c_str()));
        getline(readfile,content);
        enemy->set_y(atoi(content.c_str()));
        enemies.Enqueue(enemy);
        getline(readfile,content);
    }
    getline(readfile,content);
    while(content!="F")   //indication that positions for obstacles are there
    {
        obstacle= new Obstacles(&gSpriteSheetTexture, 0, 0);
        obstacle->set_x(atoi(content.c_str()));
        getline(readfile,content);
        obstacle->set_y(atoi(content.c_str()));
        obstacles.Enqueue(obstacle);
        getline(readfile,content);
    }
    getline(readfile,content);
    while(content!="G")   //indication that positions for bolsters are there
    {
        aliens= new Bolster(&Alienstexture, 0, 0);
        aliens->set_x(atoi(content.c_str()));
        getline(readfile,content);
        aliens->set_y(atoi(content.c_str()));
        bolsters.Enqueue(aliens);
        getline(readfile,content);
    }
    readfile.close();
    }
    else
        play = true;
}


void Game::MenuScreenGenerator(SDL_Renderer* gRenderer)
{
    startScreen = new MainMenu(&MenuTexture,0,0);
    startScreen->Render(gRenderer);
    Start = new Button(&BUTTONsheet,300,212);
    Start->Render(0,gRenderer);
    _Start = new Word(&FontSprite,378,258,"START");
    _Start->Render(gRenderer);
    Continue = new Button(&BUTTONsheet,300,293);
    Continue->Render(0,gRenderer);
    _Continue = new Word(&FontSprite,378,335,"SAVED");
    _Continue->Render(gRenderer);
    Exit = new Button(&BUTTONsheet,300,374);
    Exit->Render(0,gRenderer);
    _Exit = new Word(&FontSprite,388,420,"EXIT");
    _Exit->Render(gRenderer);

}

void Game::PauseScreenGenerator(SDL_Renderer* gRenderer)
{
    PauseScreen = new Pause(&buttonsSheet,0,0);
    PauseScreen->Render(gRenderer);
    Resume = new Button(&BUTTONsheet,300,131);
    Resume->Render(0,gRenderer);
     _Resume = new Word(&FontSprite,395,175,"RESUME");
    _Resume->Render(gRenderer);
    Restart = new Button(&BUTTONsheet,300,212);
    Restart->Render(0,gRenderer);
     _Restart = new Word(&FontSprite,378,258,"RESTART");
    _Restart->Render(gRenderer);
    Save = new Button(&BUTTONsheet,300,293);
    Save->Render(0,gRenderer);
    _Save = new Word(&FontSprite,385,335,"SAVE");
    _Save->Render(gRenderer);
    e_xit = new Button(&BUTTONsheet,300,374);
    e_xit->Render(0,gRenderer);
    _exit = new Word(&FontSprite,388,420,"EXIT");
    _exit->Render(gRenderer);

}

void Game::GameoverScreenGenerator(SDL_Renderer* gRenderer,long int frame)
{
    Menu = new GameOver(&MenuSheet,0,0);
    Menu->Render(gRenderer);
     _gameOver = new Word(&FontSprite,382,330,"GAMEOVER");
    _gameOver->Render(gRenderer);
     _Points = new Word(&FontSprite,382,375,"SCORE");
    _Points->Render(gRenderer);
    stringstream showpoints;  //for rendering game score in game over screen
    showpoints<<scores;
    SCORE->set_x(380);
    SCORE->set_y(400);
    SCORE->Render(showpoints.str(),frame ,gRenderer);

}

void Game::RandomAllUnitsGenerator(long int frame)  //randomly generates power ups with specific intervals
{

                if(frame%100== 0)
                {
                    random = rand() % SCREEN_WIDTH;
                    random2= rand() % SCREEN_WIDTH;
                    RandomUnitsGenerator(random,random2);

                }
                if(fuel%600==0)
                {
                    random1 = rand() % SCREEN_WIDTH;
                    powerUp = new Fuel(&gSpriteSheetTexture, random1, 0);
                    powerUps.Enqueue(powerUp);
                }
                if(fuel%600==0)
                {
                    random3 = rand() % SCREEN_WIDTH;
                    boostUp = new Boost(&Alienstexture, random3, 0);
                    boostbullets.Enqueue(boostUp);
                }


}


void Game::RenderingObjects(long int frame,SDL_Renderer* gRenderer)
{
                if(bullets.length()>0)
                {
                    bullets.Render(frame, gRenderer);
                    bullets.Move();
                }

                if(Mbullets.length()>0)
                {
                    Mbullets.Render(frame, gRenderer);
                    Mbullets.Move();
                }
                if(enemies.length()>0)
                {
                    enemies.Render(frame, gRenderer);
                    enemies.Move(player);//enemies move relative to player
                    check.collision(0,player,&enemies);//check collision between player and enemies with decreasing health
                    check.collision(&bullets,&enemies);//check collision between bullets and enemies
                    check.collision(&Mbullets,&enemies);//check collision between Mbullets and enemies
                }
                if(obstacles.length()>0)
                {
                    obstacles.Render(frame, gRenderer);
                    obstacles.Move();
                    check.collision(1, player,&obstacles); //check collision  between player and obstacles with decreasing health
                }
                if(bolsters.length()>0)
                {
                    bolsters.Render(frame, gRenderer);
                    bolsters.Move();
                    check.collision(1, player,&bolsters); //check collision  between player and bolsters with decreasing health
                    check.collision(&Mbullets,&bolsters);//check collision between Mbullets and bolsters
                    Node* s= bolsters.head;
                    while(s)  //For generating Rbullets when bolster reaches specific height
                    {
                    if(s->unit->get_y()==80 && s->unit->get_alive())
                    {
                        bullet2 = new RBullet(&Alienstexture,s->unit);
                        Rbullets.Enqueue(bullet2);
                    }
                    s=s->prev;
                    }
                }
                if(Rbullets.length()>0)
                {
                    Rbullets.Render(frame, gRenderer);
                    Rbullets.Move();
                    check.collision(1, player,&Rbullets); //check collision  between player and Rbullets with decreasing health
                    check.collision(&Mbullets,&Rbullets);//check collision between Mbullets and Rbullets
                }

                if(powerUps.length()>0)
                {
                    powerUps.Render(frame, gRenderer);
                    powerUps.Move();
                    check.collision(true, player,&powerUps); //increases health on collision
                }

                if(boostbullets.length()>0)
                {
                    boostbullets.Render(frame, gRenderer);
                    boostbullets.Move();
                    check.collision(0, M_bullets, player,&boostbullets); //brings Mbullets back on collision
                }
}

void Game::Buttoneffect(int x,int y,int z,SDL_Renderer* gRenderer) //takes SDL_Mouse state as argument
{
    if(z==0)  //for Pause screen
    {
                    if((x> 306) && (x<500) && (y<222) && (y>150))
                        Resume->selected = true;

                    else if((x> 306) && (x<500) && (y<286) && (y>222))
                        Restart->selected = true;

                    else if((x> 306) && (x<500) && (y<371) && (y>300))
                        Save->selected = true;

                    else if((x> 306) && (x<500) && (y<453) && (y>385))
                        e_xit->selected = true;

                    else
                    {
                        Resume->selected = false;
                        Restart->selected = false;
                        Save->selected = false;
                        e_xit->selected = false;

                    }
                    if(Resume->selected)
                    {
                        Resume->Render(1,gRenderer);
                        _Resume->Render(gRenderer);
                    }
                    if(Restart->selected)
                    {
                        Restart->Render(1,gRenderer);
                        _Restart->Render(gRenderer);
                    }
                    if(Save->selected)
                    {
                        Save->Render(1,gRenderer);
                        _Save->Render(gRenderer);
                    }
                    if(e_xit->selected)
                    {
                        e_xit->Render(1,gRenderer);
                        _exit->Render(gRenderer);
                    }
    }
    if(z==1)    //for Main Menu
    {
                    if((x> 306) && (x<500) && (y<286) && (y>222))
                        Start->selected = true;

                    else if((x> 306) && (x<500) && (y<371) && (y>300))
                        Continue->selected = true;

                    else if((x> 306) && (x<500) && (y<453) && (y>385))
                        Exit->selected = true;

                    else
                    {
                        Start->selected = false;
                        Continue->selected = false;
                        Exit->selected = false;

                    }
                    if(Start->selected)
                    {
                        Start->Render(1,gRenderer);
                        _Start->Render(gRenderer);
                    }
                    if(Continue->selected)
                    {
                        Continue->Render(1,gRenderer);
                        _Continue->Render(gRenderer);
                    }
                    if(Exit->selected)
                    {
                        Exit->Render(1,gRenderer);
                        _Exit->Render(gRenderer);
                    }
    }


}

void Game::ButtonClick(int x,int y,int z,SDL_Renderer* gRenderer)  //button click events and reactions
{
    if(z==0) //for Main Menu
    {
        if((x> 306) && (x<500) && (y<286) && (y>222))
                                {
                                    Start->setPressed(true);
                                    ClearQueues();  //initializing necessary objects
                                    player = new Unit(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
                                    player->set_alive(true);
                                    player->myHealth = 3;
                                    scores = 0;
                                    M_bullets = 0;
                                    play = true;
                                    pause = false;
                                    Mix_PlayMusic(gGame_s,-1);
                                }
                                if((x> 306) && (x<500) && (y<453) && (y>385))
                                {
                                    Exit->setPressed(true);
                                    quit = true;
                                    Mix_PlayMusic(gGame_s,-1);
                                }
                                if((x> 305) && (x<500) && (y<371) && (y>300))
                                {
                                    Continue->setPressed(true);
                                    play = true;
                                    pause = false;
                                    continueGame();
                                    Mix_PlayMusic(gGame_s,-1);
                                }
                                else
                                {
                                cout<<"..."<<endl;
                                }
    }
    if(z==1)  //for Pause screen
    {
        if((x> 304) && (x<500) && (y<205) && (y>138))
                                {
                                    Resume->setPressed(true);
                                    play = true;
                                    pause = false;
                                    Mix_PlayMusic(gGame_s,-1);
                                    //mouseClicked = false;
                                }
                                if((x> 304) && (x<500) && (y<453) && (y>385))
                                {
                                    Restart->setPressed(true);
                                    quit = true;
                                }
                                if((x> 302) && (x<500) && (y<367) && (y>302))
                                {
                                    Save->setPressed(true);
                                    saveGame();
                                    quit = true;
                                }


                                if((x> 304) && (x<500) && (y<290) && (y>222))
                                {
                                    e_xit->setPressed(true);
                                    pause = false;
                                    flag = 0;
                                    //mouseClicked = false;
                                }
                                else
                                {
                                cout<<"..."<<endl;
                                }
    }



}

void Game::RenderingBasicObjects(long int frame,SDL_Renderer* gRenderer)
{
    background->Render(player,frame,gRenderer);
    background->Move(player);
    background1->Render(player,frame,gRenderer);
    background1->Move(player);
    player->Render(frame, gRenderer);
    player->Move();
    health->Render(player,frame,gRenderer);
    bulletIcon->Render(player,M_bullets,frame,gRenderer);
    scoreIcon->Render(player,200,frame,gRenderer);
}

void Game::HealthChecker()
{
    static int checker = player->myHealth;  //save health for once call will not call again
    if(player->myHealth < checker)  //if health decreases
    {
        Mix_PlayChannel(-1,gBlast2_s,0);
        checker = player->myHealth;
        if(scores>100)
        scores -= 100;
    }
    else if(player->myHealth > checker)  //if health increases
    {
        Mix_PlayChannel(-1,gFuel_s,0);
        checker = player->myHealth;
    }
}

void Game::textureFree()
{
         gSpriteSheetTexture.Free();
         Backgroud.Free();
         Alienstexture.Free();
         MenuSheet.Free();
         MenuTexture.Free();
         BUTTONsheet.Free();
         buttonsSheet.Free();
         shadeSheet.Free();
         SplashSheet.Free();
         FontSprite.Free();
}

void Game::MusicFree()
{
    Mix_FreeMusic( gMenu_s );
    gMenu_s = NULL;
    Mix_FreeMusic( gSplash_s );
    gSplash_s = NULL;
    Mix_FreeMusic( gBegin_s );
    gBegin_s = NULL;
    Mix_FreeMusic( gGame_s );
    gGame_s = NULL;
    Mix_FreeChunk( gBullet1_s );
    Mix_FreeChunk( gBullet2_s );
    Mix_FreeChunk( gBoost_s );
    Mix_FreeChunk( gFuel_s );
    gBullet1_s = NULL;
    gBullet2_s = NULL;
    gBoost_s = NULL;
    gFuel_s = NULL;
}
