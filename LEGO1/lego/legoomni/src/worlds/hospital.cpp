#include "hospital.h"

#include "legocontrolmanager.h"
#include "legoinputmanager.h"
#include "legoutils.h"
#include "misc.h"
#include "mxmisc.h"
#include "mxnotificationmanager.h"

DECOMP_SIZE_ASSERT(Hospital, 0x12c)

// FUNCTION: LEGO1 0x100745e0
Hospital::Hospital()
{
	m_unk0xf8 = 0;
	m_unk0x100 = 0;
	m_hospitalState = NULL;
	m_unk0x108 = 0;
	m_destLocation = LegoGameState::e_undefined;
	m_unk0x10c = 0;
	m_unk0x110 = 0;
	m_unk0x114 = 0;
	m_unk0x118 = 0;
	m_unk0x11c = 0;
	m_unk0x120 = 0;
	m_unk0x128 = 0;
	NotificationManager()->Register(this);
}

// FUNCTION: LEGO1 0x100746a0
MxBool Hospital::VTable0x5c()
{
	return TRUE;
}

// STUB: LEGO1 0x100747f0
Hospital::~Hospital()
{
	// TODO
}

// FUNCTION: LEGO1 0x100748c0
MxResult Hospital::Create(MxDSAction& p_dsAction)
{
	MxResult result = LegoWorld::Create(p_dsAction);
	if (result == SUCCESS) {
		InputManager()->SetWorld(this);
		ControlManager()->Register(this);
	}

	SetIsWorldActive(FALSE);

	m_hospitalState = (HospitalState*) GameState()->GetState("HospitalState");
	if (!m_hospitalState) {
		m_hospitalState = (HospitalState*) GameState()->CreateState("HospitalState");
		m_hospitalState->m_unk0x08.m_unk0x00 = 1;
	}
	else if (m_hospitalState->m_unk0x08.m_unk0x00 == 4) {
		m_hospitalState->m_unk0x08.m_unk0x00 = 4;
	}
	else {
		m_hospitalState->m_unk0x08.m_unk0x00 = 3;
	}

	GameState()->SetCurrentArea(LegoGameState::e_hospital);
	GameState()->StopArea(LegoGameState::e_previousArea);

	InputManager()->Register(this);
	FUN_1003ef00(FALSE);

	return result;
}

// STUB: LEGO1 0x10074990
MxLong Hospital::Notify(MxParam& p_param)
{
	// TODO

	return 0;
}

// STUB: LEGO1 0x10074a60
void Hospital::ReadyWorld()
{
	// TODO
}

// STUB: LEGO1 0x10076220
void Hospital::Enable(MxBool p_enable)
{
	// TODO
}

// STUB: LEGO1 0x10076270
MxResult Hospital::Tickle()
{
	// TODO
	return SUCCESS;
}

// STUB: LEGO1 0x10076330
MxBool Hospital::VTable0x64()
{
	// TODO
	return FALSE;
}