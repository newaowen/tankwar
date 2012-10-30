#include "GameApp.h"
#include "Tank.h"

#include "SDL/SDL_image.h"

    GLuint texture;         // This is a handle to our texture object
void SDL_Surface2Texture() {
    SDL_Surface *surface;   // This surface will tell us the details of the image
    GLenum texture_format;
    GLint  nOfColors;

    surface = IMG_Load("/home/aowen/gamedev/tankwar/resource/img/tanks.png");
    if ( surface ) { 
        // Check that the image's width is a power of 2
        if ( (surface->w & (surface->w - 1)) != 0 ) {
            printf("warning: image.bmp's width is not a power of 2\n");
        }
        //               
        //                  // Also check if the height is a power of 2
        if ( (surface->h & (surface->h - 1)) != 0 ) {
            printf("warning: image.bmp's height is not a power of 2\n");
        }

        nOfColors = surface->format->BytesPerPixel;
        if (nOfColors == 4)     // contains an alpha channel
        {
            if (surface->format->Rmask == 0x000000ff)
                texture_format = GL_RGBA;
            else
                texture_format = GL_BGRA;
        } else if (nOfColors == 3)     // no alpha channel
        {
            if (surface->format->Rmask == 0x000000ff)
                texture_format = GL_RGB;
            else
                texture_format = GL_BGR;
        } else {
            printf("warning: the image is not truecolor..  this will probably break\n");
            // this error should not go
            // unhandled
        }
        // Have OpenGL generate a texture object handle for us
        glGenTextures( 1, &texture );
        //     
        //        // Bind the texture object
        glBindTexture( GL_TEXTURE_2D, texture );
        //             
        //                // Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        //                                 
        //                                    // Edit the texture object's image data using the information SDL_Surface
        //                                    gives us
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);
    } else {
        printf("SDL could not load image.bmp: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }    
     
    // Free the SDL_Surface only if it was successfully created
    if ( surface ) { 
        SDL_FreeSurface( surface );
    }

    glBindTexture( GL_TEXTURE_2D, texture);
    glBegin( GL_QUADS );
    //Bottom-left vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex3f( 100.f, 100.f, 0.0f );

    //          //Bottom-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex3f( 228.f, 100.f, 0.f );
    //                   
    //                      //Top-right vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex3f( 228.f, 228.f, 0.f );
    //                               
    //                                  //Top-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex3f( 100.f, 228.f, 0.f );
    glEnd();

}

bool onStartNewGame(const CEGUI::EventArgs& args) {
    cout << "-- start new game --" << endl;

    GameApp* app = GameApp::getSingleton();
    WindowManager& winManager = *(app->winMgr);

    // 开始新场景
    System::getSingleton().setGUISheet(app->playWin); 
    DisplayObject* obj = new DisplayObject();
    obj->setDrawFunc(SDL_Surface2Texture);

	app->addDisplayObject(obj);
    //Tank* tank = new Tank();
}

bool onExitApp(const CEGUI::EventArgs& args) {
    // fire exit event
    cout << "-- exit app --" << endl;
}

int main( int argc, char *argv[]) {
    cout << " - starting CEGUI test" << endl;

    GameApp* app = GameApp::getSingleton();
    app->init("tankwar");
    WindowManager& winManager = *(app->winMgr);

    // gui add
    // push button
    PushButton* btn = static_cast<PushButton*>(winManager.createWindow("TaharezLook/Button","JumpPushButton"));
    btn->setPosition(CEGUI::UVector2(CEGUI::UDim(0.45,0),CEGUI::UDim(0.4,0)));
    btn->setSize(UVector2(UDim(0,100), UDim(0,40)));
    btn->setText("start");
    app->rootWin->addChildWindow(btn);

    // exit button
    PushButton* exitBtn = static_cast<PushButton*>(winManager.createWindow("TaharezLook/Button","exitPushButton"));
    exitBtn->setPosition(CEGUI::UVector2(CEGUI::UDim(0.45,0),CEGUI::UDim(0.5,0)));
    exitBtn->setSize(UVector2(UDim(0,100),UDim(0,40)));
    exitBtn->setText("exit");
    app->rootWin->addChildWindow(exitBtn);

    // 事件监听
    btn->subscribeEvent(PushButton::EventClicked, Event::Subscriber(&onStartNewGame)); 
    exitBtn->subscribeEvent(PushButton::EventClicked, Event::Subscriber(&onExitApp)); 

    // 创建登陆gui app->gameloop();
    app->gameLoop();

    /* 
    SDL_Surface & screen = init_SDL() ;
    WindowManager & winManager = init_CEGUI(screen);
    create_gui( winManager);
    */
    cout << " - ending CEGUI test" << endl;
}

