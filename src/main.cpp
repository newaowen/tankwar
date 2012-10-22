#include "SDLWrapper.h"

int main(int argc, char* args[]) {
	SDLWrapper sdl;
    
    string title("tankwar");
	sdl.init(title);
	sdl.run();
	return 0;
}
