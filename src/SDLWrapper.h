#ifndef _SDLWRAPPER_
#define _SDLWRAPPER_

#include <SDL/SDL.h>
#include <string>
#include <vector>

using namespace std;

typedef void (*Displayer) ();

class SDLWrapper {
private:
	bool runFlag;
	SDL_Surface* surface;
    int width;
    int height;
    vector<Displayer> displayers;
    
public:
	SDLWrapper();
	~SDLWrapper();

	bool init(string title, int width = 640, int height = 480);
	void eventHandler(SDL_Event* event);
    void addDisplayer(void(*f)());
	int run();
	int cleanup();
};

#endif

