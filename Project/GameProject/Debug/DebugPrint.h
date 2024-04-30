#pragma once
#include <vector>
#include <string>
#include "../TaskSystem/Task.h"
#include "../TaskSystem/TaskManeger.h"

//�e�L�X�g�f�o�b�O�\���N���X
class DebugPrint :public Task {
private:
	//�C���X�^���X
	static DebugPrint* ms_instance;
	//�e�L�X�g�`��p�t�H���g
	CFont* m_font;
	//�\�����镶����̃��X�g
	std::vector<std::string> m_printStrList;

	//�R���X�g���N�^
	DebugPrint();
	//�C���X�^���X�擾
	static DebugPrint* Instance();
	//�\�����镶��������X�g�ɒǉ�
	void AddStr(std::string str);

public:
	//�f�X�g���N�^
	~DebugPrint();

	//�f�o�b�O��������v�����g
	static void Print(const char* format, ...);

	//�X�V
	void Update();
	//�`��
	void Render();
};