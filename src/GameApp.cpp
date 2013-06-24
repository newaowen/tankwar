#include "GameApp.h"

GameApp* GameApp::instance = NULL;

GameApp* GameApp::GetInstance() {
	if (instance == NULL) {
		instance = new GameApp();
	}
	return instance;
}

GameApp::GameApp(void) {
	screen = NULL;
}

GameApp::~GameApp(void) {

}

/**
 * 初始化游戏环境
 */
bool GameApp::init(string title, int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;
	this->title = title;

	this->fps = 30;
	this->frameDuration = 1000 / 30;

	initSDL();
	//initOpenGL();
	//init_CEGUI(*screen);

	status = RUN;

	return true;
}

void GameApp::initSDL() {
	Log::i("init SDL");

	atexit(SDL_Quit);
	// old: SDL_INIT_VIDEO
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		Log::e("unable to init SDL: %s", SDL_GetError());
		exit(0);
	}

	// for opengl
	// screen = SDL_SetVideoMode(this->width, this->height, 0, SDL_OPENGL);
	// for sdl
	screen = SDL_SetVideoMode(this->width, this->height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (screen == 0) {
		Log::e("unable to set OpenGL video mode", SDL_GetError());
		SDL_Quit();
		exit(0);
	}
	// 设置窗口标题
	SDL_WM_SetCaption(title.c_str(), NULL);

	/* for cegui
	SDL_ShowCursor();
	SDL_EnableUNICODE(1);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	*/
}

/*
 void GameApp::InitOpenGL() {
 glEnable(GL_TEXTURE_2D);
 glSet2D();
 }


 void GameApp::glSet2D() {
 GLint iViewport[4];

 // Get a copy of the viewport
 glGetIntegerv( GL_VIEWPORT, iViewport );
 glMatrixMode( GL_PROJECTION );
 glPushMatrix();
 glLoadIdentity();

 glOrtho( iViewport[0], iViewport[0]+iViewport[2], iViewport[1]+iViewport[3], iViewport[1], -1, 1 );
 glMatrixMode( GL_MODELVIEW );
 glPushMatrix();
 glLoadIdentity();

 glPushAttrib( GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT );
 glDisable( GL_DEPTH_TEST );
 glDisable( GL_LIGHTING );
 }
 */

/**
 * 添加显示物体
 */
void GameApp::addDisplayObject(DisplayObject* obj) {
	this->displayObjects.push_back(obj);
}

int GameApp::cleanup() {
	//Quit SDL
	SDL_Quit();
	return 0;
}

// from sdl to cegui   
void GameApp::onMouseDown(Uint8 button) {
	switch (button) {
	case SDL_BUTTON_LEFT:
		//CEGUI::System::getSingleton().injectMouseButtonDown( CEGUI::LeftButton ) ;
		break;

	case SDL_BUTTON_MIDDLE:
		//CEGUI::System::getSingleton().injectMouseButtonDown( CEGUI::MiddleButton ) ;
		break;

	case SDL_BUTTON_RIGHT:
		//CEGUI::System::getSingleton().injectMouseButtonDown( CEGUI::RightButton) ;
		break;

	case SDL_BUTTON_WHEELDOWN:
		//CEGUI::System::getSingleton().injectMouseWheelChange( -1 ) ;
		break;

	case SDL_BUTTON_WHEELUP:
		//CEGUI::System::getSingleton().injectMouseWheelChange( +1 ) ;
		break;

	default:
		cout << "handle_mouse_down ignored '" << static_cast<int>(button) << "'"
				<< endl;
		break;
	}
}

void GameApp::onMouseUp(Uint8 button) {
	switch (button) {
	case SDL_BUTTON_LEFT:
		//CEGUI::System::getSingleton().injectMouseButtonUp( CEGUI::LeftButton ) ;
		break;

	case SDL_BUTTON_MIDDLE:
		//CEGUI::System::getSingleton().injectMouseButtonUp( CEGUI::MiddleButton ) ;
		break;

	case SDL_BUTTON_RIGHT:
		//CEGUI::System::getSingleton().injectMouseButtonUp( CEGUI::RightButton ) ;
		break;

	case SDL_BUTTON_WHEELDOWN:
		break;

	case SDL_BUTTON_WHEELUP:
		break;

	default:
		cout << "handle_mouse_up ignored '" << static_cast<int>(button) << "'"
				<< endl;
		break;
	}
}

/*
 // sdl event loop
 void GameApp::inject_input( bool & must_quit ) {
 SDL_Event e ;

 // Go through all available events:
 while ( SDL_PollEvent( &e ) )
 {
 //Route according to the event type:
 switch( e.type )
 {

 //Mouse section:

 case SDL_MOUSEMOTION:
 //   We inject the mouse position directly here:
 // CEGUI::System::getSingleton().injectMousePosition( static_cast<float>( e.motion.x ),
 static_cast<float>( e.motion.y ) ) ;
 break ;

 case SDL_MOUSEBUTTONDOWN:
 handle_mouse_down( e.button.button ) ;
 break ;

 case SDL_MOUSEBUTTONUP:
 handle_mouse_up( e.button.button ) ;
 break ;

 // Keyboard section:

 case SDL_KEYDOWN:
 // CEGUI::System::getSingleton().injectKeyDown(e.key.keysym.scancode);
 if ( (e.key.keysym.unicode & 0xFF80) == 0 ) {
 CEGUI::System::getSingleton().injectChar( e.key.keysym.unicode & 0x7F ) ;
 }

 break ;

 case SDL_KEYUP:
 //CEGUI::System::getSingleton().injectKeyUp( e.key.keysym.scancode ) ;
 break ;

 //    A WM quit event occured:
 case SDL_QUIT:
 must_quit = true ;
 break ;

 case SDL_VIDEORESIZE:
 //CEGUI::System::getSingleton().notifyDisplaySizeChanged( CEGUI::Size( e.resize.w, e.resize.h ) ) ;
 break ;

 }

 }
 }


 void GameApp::inject_time_pulse( double & last_time_pulse) {
 // Get current "run-time" in seconds:
 double current_time_pulse = 0.001 * SDL_GetTicks() ;

 //   Inject the time that passed since the last call:
 //CEGUI::System::getSingleton().injectTimePulse(
 //        static_cast<float>( current_time_pulse - last_time_pulse)) ;

 //  Records the new time as the last time:
 last_time_pulse = current_time_pulse ;
 }
 */

void GameApp::eventLoop() {
	SDL_Event event;
	// sdl事件循环
	while (SDL_PollEvent(&event)) { //循环poll事件，直到事件队列为空
		eventHandler(event);
	}
}

void GameApp::eventHandler(SDL_Event event) {
	if (event.type == SDL_QUIT) { //退出事件
		status = EXIT;
		Log::i("catch exit event");
	}
}

void GameApp::gameLoop() {
	Log::i("begin game loop");

	//get "run-time" in seconds
	int startTs = SDL_GetTicks();
	while (status == RUN) {
		eventLoop();
		// 渲染
		render();

		// frame rate控制
		int ts = SDL_GetTicks();
		int leftTs = frameDuration - (ts - startTs);
		if (leftTs > 0) {
			SDL_Delay (leftTs);
		}
	}

	Log::i("leaving game loop");
}

void GameApp::render() {
	//Clears the colour buffer:
	//glClear(GL_COLOR_BUFFER_BIT);
	// draw scene
	int i = 0;
	for (i = 0; i < displayObjects.size(); i++) {
		displayObjects[i]->draw();
	}

	//[opengl]Updates the screen:
	//SDL_GL_SwapBuffers();

	// sdl flip
	if (SDL_Flip(screen) == -1) {
		Log::w("SDL flip screen fail: %s", SDL_GetError());
	}
}

/*
 void GameApp::set_CEGUI_paths() {
 //Initialises the required directories for the DefaultResourceProvider:
 CEGUI::DefaultResourceProvider & defaultResProvider = * static_cast<CEGUI::DefaultResourceProvider*> (CEGUI::System::getSingleton().getResourceProvider());
 const string CEGUIInstallSharePath = CEGUIInstallBasePath + "/share/CEGUI/" ;

 //For each resource type, sets a corresponding resource group directory:
 cout << "Using scheme directory '" << CEGUIInstallSharePath + "schemes/" << "'" << endl ;
 defaultResProvider.setResourceGroupDirectory( "schemes", CEGUIInstallSharePath + "schemes/") ;
 defaultResProvider.setResourceGroupDirectory( "imagesets", CEGUIInstallSharePath + "imagesets/") ;
 defaultResProvider.setResourceGroupDirectory( "fonts", CEGUIInstallSharePath + "fonts/") ;
 defaultResProvider.setResourceGroupDirectory( "layouts", CEGUIInstallSharePath + "layouts/") ;
 defaultResProvider.setResourceGroupDirectory( "looknfeels", CEGUIInstallSharePath + "looknfeel/") ;
 defaultResProvider.setResourceGroupDirectory( "lua_scripts", CEGUIInstallSharePath + "lua_scripts/") ;
 defaultResProvider.setResourceGroupDirectory( "schemas", CEGUIInstallSharePath + "xml_schemas/") ;
 defaultResProvider.setResourceGroupDirectory( "animations", CEGUIInstallSharePath + "animations/") ;

 //Sets the default resource groups to be used:
 CEGUI::Imageset::setDefaultResourceGroup( "imagesets") ;
 CEGUI::Font::setDefaultResourceGroup( "fonts") ;
 CEGUI::Scheme::setDefaultResourceGroup( "schemes") ;
 CEGUI::WidgetLookManager::setDefaultResourceGroup( "looknfeels") ;
 CEGUI::WindowManager::setDefaultResourceGroup( "layouts") ;
 CEGUI::ScriptModule::setDefaultResourceGroup( "lua_scripts") ;
 CEGUI::AnimationManager::setDefaultResourceGroup( "animations") ;

 //Set-up default group for validation schemas:
 CEGUI::XMLParser * parser = CEGUI::System::getSingleton().getXMLParser() ;
 if ( parser->isPropertyPresent( "SchemaDefaultResourceGroup"))
 parser->setProperty( "SchemaDefaultResourceGroup", "schemas") ;
 }

 void GameApp::init_CEGUI(SDL_Surface & surface) {
 cout << " - initializing CEGUI" << endl ;

 CEGUI::OpenGLRenderer::bootstrapSystem() ;

 this->CEGUIInstallBasePath = "/usr/local" ;
 set_CEGUI_paths() ;

 SchemeManager::getSingleton().create( "TaharezLook.scheme") ;
 System::getSingleton().setDefaultMouseCursor( "TaharezLook", "MouseArrow") ;

 this->winMgr = & WindowManager::getSingleton();

 cout << " - creating the GUI" << endl ;

 this->rootWin = static_cast<DefaultWindow*>( this->winMgr->createWindow( "DefaultWindow", "Root")) ;
 System::getSingleton().setGUISheet(rootWin) ;

 this->playWin = static_cast<DefaultWindow*>( this->winMgr->createWindow( "DefaultWindow", "PlayWin")) ;
 }
 */
