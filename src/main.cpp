#include "GameApp.h"
#include "Tank.h"
 
void drawTest() {
    static float angle = 0.0f;

    static GLfloat v0[] = { -1.0f, -1.0f,  1.0f };
    static GLfloat v1[] = {  1.0f, -1.0f,  1.0f };
    static GLfloat v2[] = {  1.0f,  1.0f,  1.0f };
    static GLfloat v3[] = { -1.0f,  1.0f,  1.0f };
    static GLfloat v4[] = { -1.0f, -1.0f, -1.0f };
    static GLfloat v5[] = {  1.0f, -1.0f, -1.0f };
    static GLfloat v6[] = {  1.0f,  1.0f, -1.0f };
    static GLfloat v7[] = { -1.0f,  1.0f, -1.0f };
    static GLubyte red[]    = { 255,   0,   0, 255 };
    static GLubyte green[]  = {   0, 255,   0, 255 };
    static GLubyte blue[]   = {   0,   0, 255, 255 };
    static GLubyte white[]  = { 255, 255, 255, 255 };
    static GLubyte yellow[] = {   0, 255, 255, 255 };
    static GLubyte black[]  = {   0,   0,   0, 255 };
    static GLubyte orange[] = { 255, 255,   0, 255 };
    static GLubyte purple[] = { 255,   0, 255,   0 };

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    /*  We don't want to modify the projection matrix. */
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    /*  Move down the z-axis. */
    glTranslatef( 0.0, 0.0, -5.0 );

    /*  Rotate. */
    glRotatef( angle, 0.0, 1.0, 0.0 ); 

    glBegin( GL_TRIANGLES );

    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( blue );
    glVertex3fv( v2 );

    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( blue );
    glVertex3fv( v2 );
    glColor4ubv( white );
    glVertex3fv( v3 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( orange );
    glVertex3fv( v6 );
    glColor4ubv( blue );
    glVertex3fv( v2 );

    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( purple );
    glVertex3fv( v7 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( white );
    glVertex3fv( v3 );

    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( blue );
    glVertex3fv( v2 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( orange );
    glVertex3fv( v6 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( black );
    glVertex3fv( v5 );

    glEnd( );

    cout << "draw test..." << endl;
}

bool onStartNewGame(const CEGUI::EventArgs& args) {
    cout << "-- start new game --" << endl;

    GameApp* app = GameApp::getSingleton();
    WindowManager& winManager = *(app->winMgr);

    // 开始新场景
    System::getSingleton().setGUISheet(app->playWin); 

    DisplayObject * obj = new DisplayObject();
    obj->setDrawer(drawTest);

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

