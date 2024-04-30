#pragma once
#include <map>
#include "../TaskSystem/Task.h"
#include"../TaskSystem/TaskManeger.h"
class DebugTimer;

// �������Ԍv���p�̃f�o�b�O�N���X
class DebugProfiler : public Task
{
private:
	static DebugProfiler* ms_instance;
	std::map<std::string, DebugTimer*> m_timers;

	// �R���X�g���N�^
	DebugProfiler();
	// �C���X�^���X�擾
	static DebugProfiler* Instance();

public:
	// �f�X�g���N�^
	~DebugProfiler();

	// ���Ԍv���J�n
	static void StartTimer(std::string name);
	// ���Ԍv���I��
	static void EndTimer(std::string name);

	// �v�����ʂ�`��
	static void Print();
};

class DebugTimer
{
private:
	LARGE_INTEGER freq;
	LARGE_INTEGER startCount;
	LARGE_INTEGER endCount;
	bool isEnd;

public:
	DebugTimer();

	void Start();
	void End();
	float Get() const;
	bool IsEnd() const;
};
