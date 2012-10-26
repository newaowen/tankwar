#include "SDLWrapper.h"

static GameApp* getSingleton() {
    if (GameApp::single == null) {
        single = new GameApp();
    }
    return single;
}

SDLWrapper::SDLWrapper(void) {
	runFlag = true;
	surface = NULL;
}

SDLWrapper::~SDLWrapper(void) {
}

// ���ڳ�ʼ��
bool SDLWrapper::init(string title, int width, int height) {
    this->width = width;
    this->height = height;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
	if((surface = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}
    //Set the window caption
    SDL_WM_SetCaption(title.c_str(), NULL );

	return true;
}

// ���display����
void SDLWrapper::addDisplayer(void(*f)()) {
    this->displayers.push_back(f);
}

// sdl �¼�����ѭ��(��windows�µ���Ϣ����ѭ������)
int SDLWrapper::run() {
	SDL_Event event;

    vector<Displayer>::iterator iter;
	while(runFlag) {
		while(SDL_PollEvent(&event)) {
			eventHandler(&event);
		}

        for (iter = this->displayers.begin(); iter != this->displayers.end(); iter ++) {
            (*iter)();
        }
		SDL_Delay(30);
	}

	return 0;
}

void SDLWrapper::eventHandler(SDL_Event* event) {
	if(event->type == SDL_QUIT) {
		runFlag = false;
	}
}

int SDLWrapper::cleanup() {
	//Quit SDL
    SDL_Quit();
	return 0;
}
