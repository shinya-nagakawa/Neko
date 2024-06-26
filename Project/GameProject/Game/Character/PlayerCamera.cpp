#include "PlayerCamera.h"
#include "Player.h"
#include "../Camera/FieldCamera.h"
#include "../Camera/EventCamera.h"
#include "../Stage/Stage.h"

PlayerCamera::PlayerCamera() :Task(TaskType::eCamera) {
	cam_at = CVector3D(0, 0, 0);
	cam_pos = CVector3D(0, 0, 0);
	mp_player = TaskManeger::FindObject(TaskType::ePlayer);
}

PlayerCamera::~PlayerCamera()
{
	CCamera::GetCamera()->LookAt(CVector3D(0, 0, 10),
		CVector3D(0, 0, 0),
		CVector3D(0.0, 1.0, 0.0));
}

void PlayerCamera::Update() {

}

void PlayerCamera::Render() {
	if (EventCamera::eventrendring)return;
	if (FieldCamera::rendring)return;
	if (CShadow::GetInstance()->GetState() == CShadow::eShadow)return;
	//_ÜÅĖŖ
	//static float cam_dist = 3.0f;
	static float cam_dist = 1.5f;
	//ņ]ŦxW
	float cam_speed = 0.002f;
	//}EXĖÚŽĘ
	CVector2D mouse_vec = CInput::GetMouseVec();
	//}EXÚŽY¨X˛ņ](ãē)
	//}EXÚŽX¨Y˛ņ](ļE)
	m_rot += CVector3D(mouse_vec.y, -mouse_vec.x, 0) * cam_speed;
	//ãēp§Ā
	m_rot.x = min(DtoR(45), max(DtoR(-45), m_rot.x));
	//-180`180ÉŗKģ
	m_rot.y = Utility::NormalizeAngle(m_rot.y);

	//Ŗ§Ā
	//cam_dist = min(10.0f, max(2.0f, cam_dist - CInput::GetMouseWheel()));
	//ĘuÆ_đŨč
	//cam_at = mp_player->m_pos + CVector3D(0, 1.5, 0);
	//cam_at = mp_player->m_pos + CVector3D(0, 0.75f, 0);
	cam_at = mp_player->m_pos + CVector3D(0, 0.65f, 0);
	//cam_pos = cam_at + CMatrix::MRotation(m_rot).GetFront() * -cam_dist;
	cam_pos = cam_at + CMatrix::MRotation(m_rot).GetFront() * -cam_dist;

	CCamera::GetCurrent()->LookAt(cam_pos, cam_at, CVector3D(0, 1, 0));

}

void PlayerCamera::Collision(Task* b) {
	switch (b->GetType()) {
	case TaskType::eField:
	{
		//JßŨņđ
		CVector3D cross, normal;
		if (b->GetModel()->CollisionRay(&cross, &normal, cam_at, cam_pos)) {
			cam_pos = cross;
		}
		
	}
	break;
	}
}