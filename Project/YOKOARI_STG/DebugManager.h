/***********************************************
* 作成者：杉山 涼
* 概要　：各クラスのデバッグを担うクラス
* その他：シングルトンクラス
************************************************/

#ifndef _DEBUGMANAGER_H_
#define _DEBUGMANAGER_H_

class DebugManager {

private:

	DebugManager();			//コンストラクタ
	bool GetEndFlag();		//ゲームの終了フラグの取得
	bool errorEndFlag;		//ゲーム終了を判断するフラグ

public:

	enum class SystemErrorType {	//システム系のエラーを管理

		FailedInitialize = -1,	//初期化エラー
	};

	enum class RenderErrorType {	//描画系のエラーを管理

		FailedLord = -10			//読み込みエラー
	};

	enum class SceneType {			//シーンの名前を管理

		null = 1,					//シーンなし
		Game,					//ゲームシーン
		Config,					//設定シーン
		Menu,					//メニューシーン
		Title,					//タイトルシーン
		Resoult,				//リザルト画面
	};

	~DebugManager() {};				//デストラクタ

	static DebugManager* Instance();	//他クラスから参照するときに使うポインタ関数

	void SystemErorr(SystemErrorType);	//システムエラーを表示する関数
	void RenderError(RenderErrorType);	//描画エラーを表示する関数
	void ReviewScene(SceneType);		//現在のシーンを通知する関数
};

#endif // !_DEBUGMANAGER_H_