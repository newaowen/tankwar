#ifndef _GAME_APP_
#define _GAME_APP_

#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include <vector>

#include "CEGUI.h"
#include <RendererModules/OpenGL/CEGUIOpenGLRenderer.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "DisplayObject.h"

using namespace std;
using namespace CEGUI;

class GameApp {
private:
	bool runFlag;
    int width;
    int height;
    string CEGUIInstallBasePath;
    vector<DisplayObject*> displayObjects;
	GameApp();

public:
    DefaultWindow* rootWin;
    DefaultWindow* playWin;
    WindowManager* winMgr;
	SDL_Surface* screen;

    static GameApp* instance; 
    static GameApp* getSingleton();

    ~GameApp();

    // 初始化窗口 , sdl, cegui等
	bool init(string title, int width = 640, int height = 480);
    void init_CEGUI(SDL_Surface & surface);
    void set_CEGUI_paths();

    // sdl and cegui inter operation
    void handle_mouse_down(Uint8 button);
    void handle_mouse_up(Uint8 button);
    void inject_input (bool & must_quit); 
    void inject_time_pulse(double& last_time_pulse);
    void gameLoop();

    // 实际的渲染函数
    void render();
    void addDisplayObject(DisplayObject* obj);

	// void eventHandler(SDL_Event* event);
	int cleanup();
};

#endif
