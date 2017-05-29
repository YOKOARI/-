#pragma once

#include "CharacterTask.h"
#include "IBullet.h"
class BossEnemy :public CharacterTask {
public:
	BossEnemy(int id);	//コンストラクタで敵のIDを設定し管理
	~BossEnemy();

	virtual void Initialize() override;	//CharacterTask::Initialize()をオーバーライド（書き換え）
	virtual void Update() override;		//CharacterTask::Update()をオーバーライド（書き換え）
	virtual void Move() override;		//CharacterTask::Move()をオーバーライド（書き換え）
	virtual void Render() override;		//CharacterTask::Render()をオーバーライド（書き換え）
	virtual void Finalize() override;	//CharacterTask::Finalize()をオーバーライド（書き換え）

private:
	bool endShotFlag;		//弾を発射したかを管理するフラグ
	int moveX;				//最終的な移動座標
	int moveY;				//最終的な移動座標
	int i;					//配列の管理
	int hp;					//敵のHP
	bool bulletFlag;		//弾を発射できるかを管理するフラグ
	int bulletFlagCount;	//

	int thisId;				//自身のID
	int hitCount;			//プレイヤーの弾が何度ヒットしたか
	IBullet* mBullet[20];	//弾のオブジェクトを格納する配列
	void ShotUpdate();		//弾の更新処理
	void ShotRender();		//弾の描画処理
	int moveFlag;			//移動するかを管理するフラグ
	int cnt;				//移動した回数をカウントする変数
	int bulletCnt;			//弾を打った後のインターバルをカウントする変数
};

