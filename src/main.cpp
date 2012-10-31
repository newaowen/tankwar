#include "GameApp.h"
#include "Tank.h"
 
#include "SDL/SDL_image.h"

/*
void SDL_Surface2Texture() {
    surface = IMG_Load("../resource/img/tanks.png");
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

*/
bool onStartNewGame(const CEGUI::EventArgs& args) {
    cout << "-- start new game --" << endl;

    GameApp* app = GameApp::getSingleton();
    WindowManager& winManager = *(app->winMgr);

    // 开始新场景
    System::getSingleton().setGUISheet(app->playWin); 

    Tengine::Texture* tex = new Tengine::Texture();

    tex->load("/home/aowen/gamedev/tankwar/resource/img/tanks.png");

    SDL_Rect rect = {0, 0, 20, 20};
    Sprite* spr = new Sprite(rect, tex);
    DisplayObject* obj = new DisplayObject(spr);

    //obj->setDrawFunc(SDL_Surface2Texture);
    //Tank* tank = new Tank();
    //tank->addEventListener
    app->addDisplayObject(obj);

    return true;
}

bool onExitApp(const CEGUI::EventArgs& args) {
    // fire exit event
    cout << "-- exit app --" << endl;
    return true;
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

