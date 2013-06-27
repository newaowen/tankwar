/*
 * 坦克大战入口
 *
 *  by zhanqu
 *  date 2013-6-22
 */
#include "GameApp.h"
#include "TankTexture.h"
#include "Tank.h"

#include "SDL/SDL_image.h"

#define SLICE_WIDTH  32
#define SLICE_HEIGHT  32
#define TANK_SPEED  0.2

// global
TankTexture* tankTexture;

TankTexture* createTexture() {
	TankTexture* tex = new TankTexture();
	tex->startX = 32;
	tex->startY = 32;
	tex->sliceWidth = SLICE_WIDTH;
	tex->sliceHeight = SLICE_HEIGHT;
	tex->load("../resource/img/tanks.png");
	return tex;
}

Tank* createTank(Texture* tex, StateFrameAnimator* anim) {
	// 构造坦克
	Tank* tank = new Tank();
	tank->texture = tex;
	tank->animator = anim;
	tank->speed = TANK_SPEED;
	tank->attachScreen(GameApp::GetInstance()->getScreen());
	return tank;
}

StateFrameAnimator* createAnimator() {
	// 元素贴图索引数组
	// 1型坦克
	int tankSeqLen = 14;
	int tankOneSeq[] = {
			//上
			15, 0, 16, 0, 17, 0, 18, 0, 19, 0, 20, 0, 21, 0,
			// 右
			15, 2, 15, 3, 15, 4, 15, 5, 15, 6, 15, 7, 15, 8,
			// 下
			15, 1, 16, 1, 17, 1, 18, 1, 19, 1, 21, 1, 21, 1,
			// 左
			16, 2, 16, 3, 16, 4, 16, 5, 16, 6, 16, 7, 16, 8, };
	// 动画控制器
	// 构造坦克使用的sprite
	StateFrameAnimator* animator = new StateFrameAnimator();
	animator->init();
	animator->frameTick = 100;
	animator->addStateFrame(UP, tankOneSeq, tankSeqLen);
	animator->addStateFrame(RIGHT, tankOneSeq + 14, tankSeqLen);
	animator->addStateFrame(DOWN, tankOneSeq + 14*2, tankSeqLen);
	animator->addStateFrame(LEFT, tankOneSeq + 14*3, tankSeqLen);
	animator->setState(UP);

	return animator;
}

/**
 * 事件处理
 */
void handleEvent(DisplayObject* target, SDL_Event event) {
	Tank* tank = (Tank*) target;
	Direction direction;
	GameApp* app = GameApp::GetInstance();
	Bullet* b;

	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			tank->move(UP);
			break;
		case SDLK_RIGHT:
			tank->move(RIGHT);
			break;
		case SDLK_DOWN:
			tank->move(DOWN);
			break;
		case SDLK_LEFT:
			tank->move(LEFT);
			break;
		case SDLK_SPACE:
			b = Bullet::create(tankTexture);
			Log::i("space catched, create bullet");
			tank->fireBullet(b);
			app->addDisplayObject(b);
			break;
		default:
			break;
		}
		break;

	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_UP:
		case SDLK_RIGHT:
		case SDLK_DOWN:
		case SDLK_LEFT:
			tank->stopMove();
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

bool createGame() {
	Log::i("create game scene");
	GameApp* app = GameApp::GetInstance();

	// 加载主贴图
	tankTexture = createTexture();
	StateFrameAnimator *animtor = createAnimator();

	// 2型坦克
	//obj->setDrawFunc(SDL_Surface2Texture);
	//Tank* tank = new Tank();
	//tank->addEventListener
	//app->addDisplayObject(obj);

	for (int i = 0; i < 1; i++) {
		Tank* tank = createTank(tankTexture, animtor);
		tank->w = SLICE_WIDTH;
		tank->h = SLICE_HEIGHT;
		tank->x = 10 + i * 40;
		tank->y = 20;
		// 增加1型坦克
		app->addDisplayObject(tank);
		tank->eventHandler = handleEvent;
	}

	return true;
}

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
