#include <bangtal.h>
#include <stdio.h>

SceneID scene, scene1;
// step1. 슈퍼마리오
ObjectID mario, building, building1, building2, bomb;
ObjectID startbutton, gameover;
ObjectID coin1, coin2, coin3, coin4, coin5, coin6, coin7, coin8, coin9;
ObjectID mario1, mariologo, mariologo1;
ObjectID mush1, mush2, mush3, mush4, mush5, mush6, mush7, mush8, mush9;
ObjectID parking1, parking2, parking3;




int x = 109, y = 350;
int dx = 0, dy = 0;

TimerID timer1;


#define ANIMATION_TIME		0.01f
#define ANIMATION_STEP		7


void keyboardCallback(KeyCode code, KeyState state)
{
	if (code == KeyCode::KEY_UP_ARROW) {			// UP
		dy += (state == KeyState::KEY_PRESSED ? ANIMATION_STEP : -ANIMATION_STEP);
	}
	else if (code == KeyCode::KEY_DOWN_ARROW) {		// DOWN
		dy -= (state == KeyState::KEY_PRESSED ? ANIMATION_STEP : -ANIMATION_STEP);
	}
	else if (code == KeyCode::KEY_RIGHT_ARROW) {		// RIGHT
		dx += (state == KeyState::KEY_PRESSED ? ANIMATION_STEP : -ANIMATION_STEP);
	}
	else if (code == KeyCode::KEY_LEFT_ARROW) {		// LEFT
		dx -= (state == KeyState::KEY_PRESSED ? ANIMATION_STEP : -ANIMATION_STEP);
	}
}


void startGame() {
	hideObject(startbutton);
	showObject(mario);
	showObject(building);
	showObject(building1);
	showObject(building2);
	showObject(bomb);
	showObject(coin1);
	showObject(coin2);
	showObject(coin3);
	showObject(coin4);
	showObject(coin5);
	showObject(coin6);
	showObject(coin7);
	showObject(coin8);
	showObject(coin9);
	showObject(mariologo);
	showObject(mariologo1);
	showMessage(" 모든 장애물을 피해서 공주를 구하라! ");

	showObject(mario1);

}


void endGame(bool success) {
	if (success) {
		enterScene(scene1);
		setTimer(timer1, 35.f);
		startTimer(timer1);
		showMessage("공주를 구하기 위한 다음 레벨로 가자!!!");

	}
	else {
		showObject(gameover);

	}

}



void timerCallback(TimerID timer)
{
	x += dx; y += dy;
	locateObject(mario, scene, x, y);
	locateObject(mario1, scene1, x, y);

	if (y > 840 || y < 300) {
		endGame(false);
	}
	else if (x < 40) {
		endGame(false);
	}

	// 충돌 조건
	if (x > 248 && x < 398 && y > 687) {     // 대포랑 부딪히는 경우
		endGame(false);
	}
	if (x > 350 && x < 413 && y < 385) {    // 초코송이랑 부딪히는 경우
		endGame(false);
	}
	if (x > 638 && x < 778 && y < 510) {
		endGame(false);
	}
	if (x > 960 && x < 1045 && y > 350 && y < 710) {
		endGame(false);
	}
	else if (x > 1117 && x < 1148 && y > 300 && y < 365) {
		endGame(true);
	}

	// 코인 
	if (x > 260 && x < 290 && y > 442 && y < 515) {
		hideObject(coin1);
	
	}

	if (x > 348 && x < 380 && y > 494 && y < 565) {
		hideObject(coin2);
		
	}

	if (x > 420 && x < 470 && y > 462 && y < 515) {
		hideObject(coin3);
		
	}

	if (x > 580 && x < 628 && y > 670 && y < 753) {
		hideObject(coin4);
	
	}

	if (x > 606 && x < 709 && y > 745 && y < 810) {
		hideObject(coin5);
		
	}

	if (x > 750 && x < 794 && y > 670 && y < 753) {
		hideObject(coin6);
		
	}

	if (x > 862 && x < 905 && y > 310 && y < 389) {
		hideObject(coin7);

	}

	if (x > 1030 && x < 1080 && y > 760 && y < 829) {
		hideObject(coin8);
	
	}

	if (x > 1130 && x < 1168 && y > 349 && y < 389) {
		hideObject(coin9);
		
	}
	setTimer(timer, ANIMATION_TIME);
	startTimer(timer);

	// 버섯 충돌
	if (x > 750 && x < 800 && y < 40) {  // 버섯1
		hideObject(mush1);
	}

	if (x > 340 && x < 383 && y < 40) {
		hideObject(mush2);
	}

	if (x > 120 && x < 187 && y > 345 && y < 400) {
		hideObject(mush3);
	}

	if (x > 540 && x < 607 && y > 120 && y < 159) {  // 독버섯
		stopTimer(timer1);
		hideObject(mush4);
		
	}

	if (x > 580 && x < 675 && y > 560 && y < 596) {
		stopTimer(timer1);
		hideObject(mush5);
		
	}

	if (x > 240 && x < 306 && y > 250 && y < 320) {
		stopTimer(timer1);
		hideObject(mush6);
		
	}

	if (x > 1045 && x < 1105 && y > 357 && y < 400) {
		stopTimer(timer1);
		hideObject(mush7);
		
	}

	if (x > 840 && x < 905 && y > 343 && y < 400) {
		hideObject(mush8);
	}

	if (x < 28 && y > 470 && y < 508) {
		stopTimer(timer1);
		hideObject(mush9);
		
	}

	// 주차 완료
	if (x > 940 && x < 1100 && y > 620 && y < 650) {
		stopTimer(timer1);
		

	}

	if (x > 970 && x < 1100 && y > 410 && y < 450) {
		stopTimer(timer1);
		

	}

	if (x > 1087 && x < 1140 && y > 520 && y < 539) {
		stopTimer(timer1);
		

	}

	// 잔디 통행 금지
	if (x > 840 && x < 1080 && y > 65 && y < 200) {     // 오른쪽 아래 잔디 통행 금지
		stopTimer(timer1);
		
	}

	if (x > 420 && x < 770 && y > 120 && y < 270) {     // 왼쪽 아래 잔디 통행 금지
		stopTimer(timer1);
		
	}

	if (x > 730 && x < 920 && y > 420) {
		stopTimer(timer1);
		
	}


	




}



void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	if (object == startbutton) {
		startGame();
	}
}


int main()
{
	setMouseCallback(mouseCallback);

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	setTimerCallback(timerCallback);
	setKeyboardCallback(keyboardCallback);

	scene = createScene("마리오 게임 레벨 1!!", "게임 배경.png");


	startbutton = createObject("시작 버튼.png");
	locateObject(startbutton, scene, 480, 500);
	showObject(startbutton);

	scene1 = createScene("마리오 게임 레벨 2!!", "카트 코스 배경.png");

	building = createObject("장애물.png");
	locateObject(building, scene, 620, 350);
	hideObject(building);

	building1 = createObject("초코송이.png");
	locateObject(building1, scene, 360, 347);
	hideObject(building1);

	building2 = createObject("초코송이 3단.png");
	locateObject(building2, scene, 960, 353);
	hideObject(building2);

	bomb = createObject("폭탄.png");
	locateObject(bomb, scene, 270, 730);
	hideObject(bomb);

	timer1 = createTimer(35.f);
	showTimer(timer1);

	mariologo = createObject("슈퍼마리오.png");
	locateObject(mariologo, scene, 570, 830);
	showObject(mariologo);

	coin1 = createObject("코인1.png");
	locateObject(coin1, scene, 290, 520);
	hideObject(coin1);

	coin2 = createObject("코인2.png");
	locateObject(coin2, scene, 376, 568);
	hideObject(coin2);

	coin3 = createObject("코인3.png");
	locateObject(coin3, scene, 468, 520);
	hideObject(coin3);

	coin4 = createObject("코인4.png");
	locateObject(coin4, scene, 620, 750);
	hideObject(coin4);

	coin5 = createObject("코인5.png");
	locateObject(coin5, scene, 706, 806);
	hideObject(coin5);

	coin6 = createObject("코인6.png");
	locateObject(coin6, scene, 790, 750);
	hideObject(coin6);

	coin7 = createObject("코인7.png");
	locateObject(coin7, scene, 899, 380);
	hideObject(coin7);

	coin8 = createObject("코인8.png");
	locateObject(coin8, scene, 1035, 820);
	hideObject(coin8);

	coin9 = createObject("코인9.png");
	locateObject(coin9, scene, 1160, 380);
	hideObject(coin9);

	mario = createObject("마리오.png");
	locateObject(mario, scene, x, y);
	hideObject(mario);


	gameover = createObject("게임 오바.png");
	locateObject(gameover, scene, 180, 320);
	hideObject(gameover);

	mush1 = createObject("버섯1.png");
	locateObject(mush1, scene1, 800, 30);
	showObject(mush1);

	mush2 = createObject("버섯2.png");
	locateObject(mush2, scene1, 380, 30);
	showObject(mush2);

	mush3 = createObject("버섯3.png");
	locateObject(mush3, scene1, 200, 395);
	showObject(mush3);

	mush4 = createObject("독버섯1.png");
	locateObject(mush4, scene1, 600, 150);
	showObject(mush4);

	mush5 = createObject("독버섯2.png");
	locateObject(mush5, scene1, 670, 590);
	showObject(mush5);

	mush6 = createObject("독버섯3.png");
	locateObject(mush6, scene1, 300, 315);
	showObject(mush6);

	mush7 = createObject("독버섯4.png");
	locateObject(mush7, scene1, 1110, 387);
	showObject(mush7); 

	mush8 = createObject("버섯4.png");
	locateObject(mush8, scene1, 900, 387);
	showObject(mush8);

	mush9 = createObject("독버섯5.png");
	locateObject(mush9, scene1, 20, 500);
	showObject(mush9);

	parking1 = createObject("주차 벽1.png");
	locateObject(parking1, scene1, 1060, 662);
	showObject(parking1);

	parking2 = createObject("주차 벽2.png");
	locateObject(parking2, scene1, 1068, 460);
	showObject(parking2);

	parking3 = createObject("주차 벽3.png");
	locateObject(parking3, scene1, 1157, 522);
	showObject(parking3);

	mario1 = createObject("마리오 카트.png");
	locateObject(mario1, scene1, x, y);
	hideObject(mario1);

	mariologo1 = createObject("슈퍼마리오1.png");
	locateObject(mariologo1, scene1, 300, 800);
	showObject(mariologo1);






	TimerID timer = createTimer(ANIMATION_TIME);
	startTimer(timer);

	startGame(scene);
}
