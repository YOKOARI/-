#ifndef _CONTRIL_H_
#define _CONTROL_H

enum ControlID {
	e_StageFirst = 1,	//ステージ1
	e_StageSecond,		//ステージ２
	e_StageThird,		//ステージ３
	e_YokoariBrue,		//ヨコアリくんブルー
	e_YokoariRed,		//ヨコアリくんレッド
	
};

namespace Control {
	static int charactorId = e_YokoariBrue;	//キャラクターのID
	static int StageId = e_StageFirst;		//ステージのID
}

#endif // !_CONTRIL_H_
