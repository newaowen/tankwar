#include "GameApp.h"
#include "Tank.h"

bool onStartNewGame(const CEGUI::EventArgs& args) {
    cout << "-- start new game --" << endl;

    GameApp* app = GameApp::getSingleton();
    WindowManager& winManager = *(app->winMgr);

    // 开始新场景
    System::getSingleton().setGUISheet(app->playWin); 

    //Tank* tank = new Tank();
    //tank->addEventListener
    //app->addDisplayer(tank);
    /*
        app->addDisplayer(); 
    */
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

