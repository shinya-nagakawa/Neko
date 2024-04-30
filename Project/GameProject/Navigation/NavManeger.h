#pragma once
#include <list>
#include "NavNode.h"
#include "../TaskSystem/Task.h"
#include "../TaskSystem/TaskManeger.h"

//経路探索処理の管理クラス
class NavManeger : public Task {
private:
	static NavManeger* ms_instance;

	//探索用ノードのリスト
	std::list<NavNode*> m_nodes;

	//追加したノードの数
	int m_addNodeCount;
	//デバッグ用：描画するかどうか
	bool m_isRender;
	//デバッグ用：ルートの開始ノード
	NavNode* m_routeStartNode;

	//全ノードの状態をリセット
	void Reset();

public:
	static NavManeger* Instance();

	NavManeger();
	~NavManeger();

	//経路探索用のノードを追加
	void AddNode(NavNode* node);
	//経路探索用のノードを取り除く
	void RemoveNode(NavNode* node);

	//指定したノードからノードまでの経路を探索
	NavNode* Navigate(NavNode* start, NavNode* goal);

	//指定された座標に一番近いノードを取得
	NavNode* GetNearNavNode(const CVector3D& pos);
	//指定されたノードに一番近いノードを取得
	NavNode* GetNearNavNode(NavNode* node);

	//接続できるノードを検索
	//（間に遮蔽物があるノードには接続できない）
	int FindConnectNavNodes(NavNode* node, float distance);

	//全ノードを描画
	void Render();
};