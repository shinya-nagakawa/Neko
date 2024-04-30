#include "DebugPrint.h"
#include <stdarg.h>

DebugPrint* DebugPrint::ms_instance = nullptr;

//�R���X�g���N�^
DebugPrint::DebugPrint() :Task(TaskType::eDebug, true) {

	m_font = FONT("DebugPrint");
}

//�f�X�g���N�^
DebugPrint::~DebugPrint()
{
	ms_instance = nullptr;
}

//�C���X�^���X�擾
DebugPrint* DebugPrint::Instance()
{
	if (ms_instance == nullptr) {
		ms_instance = new DebugPrint();
	}
	return ms_instance;
}

//�f�o�b�O��������v�����g
void DebugPrint::Print(const char* format, ...)
{
	char buf[512];
	va_list ap;
	va_start(ap, format);
	vsprintf_s(buf, format, ap);
	va_end(ap);

	Instance()->AddStr(buf);
}

//�\�����镶��������X�g�ɒǉ�
void DebugPrint::AddStr(std::string str)
{
	m_printStrList.push_back(str);
}

//�X�V
void DebugPrint::Update()
{
}

//�`��
void DebugPrint::Render()
{
	//1�s�̕�
	float rowSize = m_font->GetFontSize();
	//Y���J�n�ʒu
	float startPosY = rowSize * 2.0f;
	//���X�g���̕������S�ĕ`��
	for (int i = 0; i < m_printStrList.size(); i++) {
		//������`��
		m_font->Draw
		(
			0, (int)(startPosY + rowSize * i),
			1.0f, 0.0f, 0.0f,
			m_printStrList[i].c_str()
		);
	}
	//���X�g���N���A
	m_printStrList.clear();
}
