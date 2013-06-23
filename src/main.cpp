#include "GameApp.h"
#include "Tank.h"

#include "SDL/SDL_image.h"

bool createGame() {
	Log::i("create game scene");

	GameApp* app = GameApp::GetInstance();
	// 加载主贴图
	Tengine::Texture* tex = new Tengine::Texture();
	tex->load("../resource/img/tanks.png");


	SDL_Rect rect = {50, 150, 20, 20};
	Sprite* spr = new Sprite(rect, tex);
	// 精灵和DisplayObject区别？
	DisplayObject* obj = new DisplayObject(spr);

	//obj->setDrawFunc(SDL_Surface2Texture);
	//Tank* tank = new Tank();
	//tank->addEventListener
	app->addDisplayObject(obj);

	return true;
}

/*
bool onExitApp(const CEGUI::EventArgs& args) {
	// fire exit event
	cout << "[exit]" << endl;
	return true;
}
*/

int main(int argc, char *argv[]) {
	GameApp* app = GameApp::GetInstance();
	app->init("tankwar");

	// 初始化
	createGame();
	app->gameLoop();
	Log::i("end app");

	//WindowManager& winManager = *(app->winMgr);

	// gui add
	// push button
	/*
	PushButton* btn = static_cast<PushButton*>(winManager.createWindow(
			"TaharezLook/Button", "JumpPushButton"));
	btn->setPosition(
			CEGUI::UVector2(CEGUI::UDim(0.45, 0), CEGUI::UDim(0.4, 0)));
	btn->setSize(UVector2(UDim(0, 100), UDim(0, 40)));
	btn->setText("start");
	app->rootWin->addChildWindow(btn);

	// exit button
	PushButton* exitBtn = static_cast<PushButton*>(winManager.createWindow(
			"TaharezLook/Button", "exitPushButton"));
	exitBtn->setPosition(
			CEGUI::UVector2(CEGUI::UDim(0.45, 0), CEGUI::UDim(0.5, 0)));
	exitBtn->setSize(UVector2(UDim(0, 100), UDim(0, 40)));
	exitBtn->setText("exit");
	app->rootWin->addChildWindow(exitBtn);

	// 事件监听
	btn->subscribeEvent(PushButton::EventClicked,
			Event::Subscriber(&onStartNewGame));
	exitBtn->subscribeEvent(PushButton::EventClicked,
			Event::Subscriber(&onExitApp));
	*/
	// 创建登陆gui
	// app->gameloop();
}

