#ifndef _SDLWRAPPER_
#define _SDLWRAPPER_

#include <SDL/SDL.h>
#include <string>
#include <vector>

#include <CEGUI.h>
#include <RendererModules/OpenGL/CEGUIOpenGLRenderer.h>

#include <GL/gl.h>
#include <GL/glu.h>


using namespace std;

typedef void (*Displayer) ();

class GameApp {
private:
	bool runFlag;
	SDL_Surface* surface;
    int width;
    int height;
    vector<Displayer> displayers;
    GameApp *single; 
	GameApp();
public:
    static GameApp* getSingleton();

    void handle_mouse_down(Uint8 button)
    void handle_mouse_up(Uint8 button)
    void inject_input (bool & must_quit) 
    void inject_time_pulse(double& last_time_pulse)
    void gameLoop ();
    void render()
    void addDisplayer(void(*f)());
	bool init(string title, int width = 640, int height = 480);
	void eventHandler(SDL_Event* event);
	int cleanup();
};

#endif

