#ifndef _LegoView1_h
#define _LegoView1_h

#include "compat.h"
#include "decomp.h"
#include "tglsurface.h"

namespace Tgl
{
class Camera;
}

/////////////////////////////////////////////////////////////////////////////
// LegoView

// VTABLE: 0x100dc000
// SIZE 0x78
class LegoView : public TglSurface {
public:
	LegoView();
	virtual ~LegoView() override;

	BOOL Create(const CreateStruct&, Tgl::Renderer*);
	virtual void Destroy() override; // vtable+0x08

	Tgl::Group* GetScene() const;
	Tgl::Camera* GetCamera() const;

protected:
	virtual Tgl::View* CreateView(Tgl::Renderer*, Tgl::Device*); // vtable+0x10

private:
	Tgl::Group* m_pScene;   // 0x70
	Tgl::Camera* m_pCamera; // 0x74
};

/////////////////////////////////////////////////////////////////////////////
// LegoView implementation

inline Tgl::Group* LegoView::GetScene() const
{
	return m_pScene;
}

inline Tgl::Camera* LegoView::GetCamera() const
{
	return m_pCamera;
}

// SYNTHETIC: LEGO1 0x100ab580
// LegoView::`scalar deleting destructor'

/////////////////////////////////////////////////////////////////////////////
// LegoView1

// VTABLE: LEGO1 0x100dc018
// SIZE 0x88
class LegoView1 : public LegoView {
public:
	LegoView1();
	virtual ~LegoView1() override;

	BOOL AddLightsToViewport();
	BOOL Create(const TglSurface::CreateStruct&, Tgl::Renderer*);
	virtual void Destroy() override; // vtable+0x08

private:
	Tgl::Light* m_pSunLight;         // 0x78
	Tgl::Light* m_pDirectionalLight; // 0x7c
	Tgl::Light* m_pAmbientLight;     // 0x80
};

// SYNTHETIC: LEGO1 0x100ab7a0
// LegoView1::`scalar deleting destructor'

#endif /* _LegoView1_h */