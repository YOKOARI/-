#include "BossEnemy.h"
#include "DxLib.h"
#include "ControlGameInstance.h"
#include "NormalEnemyBullet.h"
#define BOSS_PIC "Image/EnemyUI/Boss１.png"
#define HP_BAR "Image/HPBar/HealthBarIn.png"
#define HP_BAR_AROUND "Image/HPBar/HealthBarOut.png"
#define SPOWN_X 350
#define SPOWN_Y -20

/****　BossEnemy(自身のID)　****/
BossEnemy::BossEnemy(int id){

	//生成時に設定されたIDを自身のIDとして格納
	thisId = id;
}


BossEnemy::~BossEnemy()
{
}

/****　初期化処理　****/
void BossEnemy::Initialize() {

	//配列の初期化
	for (i = 0; i < 20; i++) {
		mBullet[i] = NULL;
	}
	//以下、各変数の初期化
	bulletFlag = false;
	bulletFlagCount = 0;
	x = SPOWN_X;
	y = SPOWN_Y;
	i = 0;
	hp = 680;
	cnt = 0;
	bulletCnt = 0;
	interval = 6;
	cntBulletTime = 0;
	hitCount = 0;
	moveFlag = 0;
	mCharaGraphicHandle[0] = LoadGraph(BOSS_PIC);
	mCharaGraphicHandle[1] = LoadGraph(HP_BAR);
	mCharaGraphicHandle[2] = LoadGraph(HP_BAR_AROUND);
}

/****　更新処理　****/
void BossEnemy::Update() {
	
	//自身の座標更新
	Move();

	//自身の現在のｘ座標を、あたり判定を管理するクラスに登録
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointX(this->x);

	//自身の現在のｙ座標を、あたり判定を管理するクラスに登録
	ControlGameInstance::GetInstance()->SetNewbeiEnemyPointY(this->y);

	//弾の座標を更新
	ShotUpdate();

	//自身のあたり判定に使用する矩形をあたり判定を管理するクラスに登録
	ControlGameInstance::GetInstance()->SetEnemyHitAria(x + 20, y + 28, 16);

	//プレイヤーが発射したすべての弾において、そのいづれかが当たっているかどうかの処理
	for (int j = 0; j < 70; j++) {

		//プレイヤーの弾対自身のあたり判定を行う処理　TRUE：当たっている　FALSE：当たっていない
		if (ControlGameInstance::GetInstance()->PlayerBulletToEnemyHitTest(j) == true) {

			//デバッグ用　当たっていたら出力
			DrawString(0, 0, "hitP", GetColor(255, 255, 255));

			//自身のHPを減らす
			hp--;

			//もしHPが０になったら
			if(hp == 0)

				//自身が死んだことをあたり判定を管理するクラスの登録
				//SetEnemyDeadFlag(自身のID､TRUE)
				ControlGameInstance::GetInstance()->SetEnemyDeadFlag(thisId, true);
			}
		else {
			//ControlGameInstance::GetInstance()->SetEnemyHitFlag(thisId, j, false);
		}
	}

}

/****　描画処理　*****/
void BossEnemy::Render() {

	//HPバーの描画
	if (hp >= 0) {
		DrawExtendGraph(50, 50, 50 + hp, 50 + 40, mCharaGraphicHandle[1], TRUE);
		DrawExtendGraph(50, 50, 50 + 680, 50 + 40, mCharaGraphicHandle[2], TRUE);
	}

	//自身の描画
	DrawExtendGraph(x, y, x + 40, y + 56, mCharaGraphicHandle[0], TRUE);

	//弾の描画
	ShotRender();
}

/****　終了処理　****/
void BossEnemy::Finalize() {

	//画面外に座標を更新
	x = 3000;
	y = 3000;
}

void BossEnemy::Move() {

	//フラグで移動するモーションを変更
	if (moveFlag == 0) {
		y += 2;
		if (cnt > 100) moveFlag = 1;
	}
	else if (moveFlag == 1) {
		y -= 1;
		x += rand() % 3 - 1;
		if (cnt % 50 == 0) moveFlag = 2;
	}
	else if(moveFlag == 2){
		y += 1;
		x += rand() % 3 - 1;
		if (cnt % 50 == 0) moveFlag = 3;
	}

	//移動が終わったら弾を発射できるようにフラグをセット
	else {
		bulletFlag = true;
		//100フレーム後に移動開始
		if (cnt % 100 == 0) {
			moveFlag = 1;
			bulletFlag = false;
		}
	}
	cnt++;
}

/****　弾の更新処理　****/
void BossEnemy::ShotUpdate() {

	//配列にオブジェクトがある場合、更新処理をする
	for (int i = 0; i < 20; i++) {
		if (mBullet[i] != NULL) {
			mBullet[i]->Update();
		}
	}

	//インターバルが経過していてかつ移動が終わっていたら弾を発射
	if (interval < cntBulletTime && bulletFlag == true) {
		mBullet[bulletCnt] = new NormalEnemyBullet;
		mBullet[bulletCnt]->Initialize();
		cntBulletTime = 0;
	}
	cntBulletTime++;
	
	bulletCnt++;
	if (bulletCnt == 20) bulletCnt = 0;
}

/****　弾の描画処理　****/
void BossEnemy::ShotRender() {

	//配列にオブジェクトがある場合、描画処理をする
	for (int i = 0; i < 20; i++) {
		if (mBullet[i] != NULL) {
			mBullet[i]->Render();
		}
	}
}
