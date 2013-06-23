#ifndef _GAME_APP_
#define _GAME_APP_

#include <SDL/SDL.h>
#include <iostream>
#include <string>
#include <vector>

//#include "CEGUI.h"
//#include <RendererModules/OpenGL/CEGUIOpenGLRenderer.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "DisplayObject.h"
#include "Log.h"

using namespace std;
using namespace Tengine;

enum GameStatus {START, RUN, PAUSE, EXIT};

class GameApp {
private:
	// 运行状态
	enum GameStatus status;

    int width;
    int height;
    string title;
    SDL_Surface* screen;

    float fps;
    int frameDuration;

    //string CEGUIInstallBasePath;
    vector<DisplayObject*> displayObjects;
	GameApp();

public:
    //DefaultWindow* rootWin;
    //DefaultWindow* playWin;
    //WindowManager* winMgr;
	 ~GameApp();

    static GameApp* instance; 
    static GameApp* GetInstance();

    inline SDL_Surface* getScreen() { return screen; }

    // 初始化窗口 , sdl, cegui等
	bool init(string title, int width = 640, int height = 480);
	void initSDL();
    //void initOpenGL();
    //void glSet2D();
    //void init_CEGUI(SDL_Surface & surface);
    //void set_CEGUI_paths();

    // sdl and cegui inter operation
    void onMouseDown(Uint8 button);
    void onMouseUp(Uint8 button);
    //void inject_input (bool & must_quit);
    //void inject_time_pulse(double& last_time_pulse);
    void gameLoop();
    void eventLoop();
    void eventHandler(SDL_Event event);

    // 实际的渲染函数
    void render();
    void addDisplayObject(DisplayObject* obj);

	// void eventHandler(SDL_Event* event);
	int cleanup();
};

#endif
