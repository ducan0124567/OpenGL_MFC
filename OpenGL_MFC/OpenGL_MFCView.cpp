
// OpenGL_MFCView.cpp : implementation of the COpenGL_MFCView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OpenGL_MFC.h"
#endif

#include "OpenGL_MFCDoc.h"
#include "OpenGL_MFCView.h"
#include "RenderShapes.h"
#include "MaterialColor.h"
#include "TranslatefSettingDlg.h"
#include "RotateSettingDlg.h"


#include "GL/GL.H"
#include "GL/GLU.H"
#include "GL/glut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEG2RAD (3.14159f/180.0f)
// COpenGL_MFCView

IMPLEMENT_DYNCREATE(COpenGL_MFCView, CView)

BEGIN_MESSAGE_MAP(COpenGL_MFCView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_TEAPOT_SOLID, &COpenGL_MFCView::OnTeapotSolid)
	ON_UPDATE_COMMAND_UI(ID_TEAPOT_SOLID, &COpenGL_MFCView::OnUpdateTeapotSolid)
	ON_UPDATE_COMMAND_UI(ID_TEAPOT_WIRE, &COpenGL_MFCView::OnUpdateTeapotWire)
	ON_COMMAND(ID_TEAPOT_WIRE, &COpenGL_MFCView::OnTeapotWire)
	ON_COMMAND(ID_TORUS_SOLID, &COpenGL_MFCView::OnTorusSolid)
	ON_UPDATE_COMMAND_UI(ID_TORUS_SOLID, &COpenGL_MFCView::OnUpdateTorusSolid)
	ON_COMMAND(ID_TORUS_WIRE, &COpenGL_MFCView::OnTorusWire)
	ON_UPDATE_COMMAND_UI(ID_TORUS_WIRE, &COpenGL_MFCView::OnUpdateTorusWire)
	ON_COMMAND(ID_CUBE_SOLID, &COpenGL_MFCView::OnCubeSolid)
	ON_COMMAND(ID_CUBE_LINE, &COpenGL_MFCView::OnCubeLine)
	ON_COMMAND(ID_CUBE_POINT, &COpenGL_MFCView::OnCubePoint)
	ON_COMMAND(ID_BOX_SOLID, &COpenGL_MFCView::OnBoxSolid)
	ON_COMMAND(ID_BOX_LINES, &COpenGL_MFCView::OnBoxLines)
	ON_COMMAND(ID_BOX_POINT, &COpenGL_MFCView::OnBoxPoint)
	ON_COMMAND(ID_SPHERE_SOLID, &COpenGL_MFCView::OnSphereSolid)
	ON_COMMAND(ID_SPHERE_WIRE, &COpenGL_MFCView::OnSphereWire)
	ON_COMMAND(ID_CYLINDER_SOLID, &COpenGL_MFCView::OnCylinderSolid)
	ON_COMMAND(ID_TRUNCATEDCONE_SOLID, &COpenGL_MFCView::OnTruncatedconeSolid)
	ON_COMMAND(ID_CONE_SOLID, &COpenGL_MFCView::OnConeSolid)
	ON_COMMAND(ID_PYRAMID_SOLID, &COpenGL_MFCView::OnPyramidSolid)
	ON_COMMAND(ID_PYRAMID_LINES, &COpenGL_MFCView::OnPyramidLines)
	ON_COMMAND(ID_PYRAMID_POINT, &COpenGL_MFCView::OnPyramidPoint)
	ON_COMMAND(ID_FRUSTUM_SOLID, &COpenGL_MFCView::OnFrustumSolid)
	ON_COMMAND(ID_FRUSTUM_LINES, &COpenGL_MFCView::OnFrustumLines)
	ON_COMMAND(ID_FRUSTUM_POINT, &COpenGL_MFCView::OnFrustumPoint)
	ON_UPDATE_COMMAND_UI(ID_CUBE_SOLID, &COpenGL_MFCView::OnUpdateCubeSolid)
	ON_UPDATE_COMMAND_UI(ID_CUBE_LINE, &COpenGL_MFCView::OnUpdateCubeLine)
	ON_UPDATE_COMMAND_UI(ID_CUBE_POINT, &COpenGL_MFCView::OnUpdateCubePoint)
	ON_UPDATE_COMMAND_UI(ID_BOX_SOLID, &COpenGL_MFCView::OnUpdateBoxSolid)
	ON_UPDATE_COMMAND_UI(ID_BOX_LINES, &COpenGL_MFCView::OnUpdateBoxLines)
	ON_UPDATE_COMMAND_UI(ID_BOX_POINT, &COpenGL_MFCView::OnUpdateBoxPoint)
	ON_UPDATE_COMMAND_UI(ID_SPHERE_SOLID, &COpenGL_MFCView::OnUpdateSphereSolid)
	ON_UPDATE_COMMAND_UI(ID_SPHERE_WIRE, &COpenGL_MFCView::OnUpdateSphereWire)
	ON_UPDATE_COMMAND_UI(ID_CYLINDER_SOLID, &COpenGL_MFCView::OnUpdateCylinderSolid)
	ON_UPDATE_COMMAND_UI(ID_TRUNCATEDCONE_SOLID, &COpenGL_MFCView::OnUpdateTruncatedconeSolid)
	ON_UPDATE_COMMAND_UI(ID_CONE_SOLID, &COpenGL_MFCView::OnUpdateConeSolid)
	ON_UPDATE_COMMAND_UI(ID_PYRAMID_SOLID, &COpenGL_MFCView::OnUpdatePyramidSolid)
	ON_UPDATE_COMMAND_UI(ID_PYRAMID_LINES, &COpenGL_MFCView::OnUpdatePyramidLines)
	ON_UPDATE_COMMAND_UI(ID_PYRAMID_POINT, &COpenGL_MFCView::OnUpdatePyramidPoint)
	ON_UPDATE_COMMAND_UI(ID_FRUSTUM_SOLID, &COpenGL_MFCView::OnUpdateFrustumSolid)
	ON_UPDATE_COMMAND_UI(ID_FRUSTUM_LINES, &COpenGL_MFCView::OnUpdateFrustumLines)
	ON_UPDATE_COMMAND_UI(ID_FRUSTUM_POINT, &COpenGL_MFCView::OnUpdateFrustumPoint)
	ON_COMMAND(ID_AFFINE_TRANSLATEF, &COpenGL_MFCView::OnAffineTranslatef)
	ON_UPDATE_COMMAND_UI(ID_AFFINE_TRANSLATEF, &COpenGL_MFCView::OnUpdateAffineTranslatef)
	ON_COMMAND(ID_AFFINE_ROTATEF32804, &COpenGL_MFCView::OnAffineRotatef)
END_MESSAGE_MAP()

// COpenGL_MFCView construction/destruction

COpenGL_MFCView::COpenGL_MFCView() noexcept
{
	// TODO: add construction code here

}

COpenGL_MFCView::~COpenGL_MFCView()
{
}

BOOL COpenGL_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= (WS_CLIPCHILDREN |
		WS_CLIPSIBLINGS | CS_OWNDC);
	return CView::PreCreateWindow(cs);
}

void COpenGL_MFCView::SetupOpenGL()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0,0,0,0,0,0,0,0,0,0,0,0,0,
		16,
		0,0,0,0,0,0,0,
	};
	HDC hdc = GetDC()->m_hDC;

	int nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, nPixelFormat, &pfd);

	m_hRC = wglCreateContext(hdc);
	wglMakeCurrent(hdc, m_hRC);

}

void COpenGL_MFCView::RemoveOpenGL()
{
	if (wglGetCurrentContext() != NULL)
		wglMakeCurrent(NULL, NULL);

	if (m_hRC != NULL)
	{
		wglDeleteContext(m_hRC);
		m_hRC = NULL;
	}
}

// Init
void COpenGL_MFCView::InitOpenGL(void) 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 0.8, 0.8, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.8, 0.8, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	//Base
	g_Base = MakeBase();

	//Teapot
	g_SolidTeapot = MakeSolidTeapot(3.0);
	g_WireTeapot = MakeWireTeapot(3.0);

	//Torus
	g_SolidTorus = MakeSolidTorus(1.0f, 3.00f, 32, 32);
	g_WireTorus = MakeWireTorus(1.0f, 3.00f, 32, 32);

	//Cube
	g_SolidCube = MakeSolidCube(3.0);
	g_LinesCube = MakeLinesCube(3.0);
	g_PointCube = MakePointCube(3.0);

	//Box
	g_SolidBox = MakeSolidBox(5.0, 2.0, 4.0);
	g_LinesBox = MakeLinesBox(5.0, 2.0, 4.0);
	g_PointBox = MakePointBox(5.0, 2.0, 4.0);

	//Sphere
	g_SolidSphere = MakeSolidSphere(4.0);
	g_WireSphere = MakeWireSphere(4.0);

	//Cylinder
	g_SolidCylinder = MakeSolidCylinder(4.0, 5.0);

	//TruncatedCone
	g_SolidTruncatedCone = MakeSolidTruncatedCone(3.0, 1.0, 5.0);

	//Cone
	g_SolidCone = MakeSolidCone(2.0, 8.0);

	//Pyramid
	g_SolidPyramid = MakeSolidPyramid(3.0, 5.0);
	g_LinesPyramid = MakeLinesPyramid(3.0, 5.0);
	g_PointPyramid = MakePointPyramid(3.0, 5.0);
	
	//Frustum
	g_SolidFrustum = MakeSolidFrustumShape(5.0, 3.0, 6.0);
	g_LinesFrustum = MakeLinesFrustumShape(5.0, 3.0, 6.0);
	g_PointFrustum = MakePointFrustumShape(5.0, 3.0, 6.0);

}

void COpenGL_MFCView::DrawCoordinate()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

void COpenGL_MFCView::Select_Shape_Render()
{
	
	switch (SelectShape)
	{
	default:
		break;
	case 1:
	{
		if (SelectRender == 1)
			//glCallList(g_SolidTeapot);
		{
			glCallList(g_SolidTeapot);
			
		}
		if (SelectRender == 2)
			glCallList(g_WireTeapot);
		break;
	}
	case 2:
	{
		if (SelectRender == 1)
			glCallList(g_SolidTorus);
		if (SelectRender == 2)
			glCallList(g_WireTorus);
		break;
	}
	case 3:
	{
		if (SelectRender == 1)
			glCallList(g_SolidCube);
		if (SelectRender == 2)
			glCallList(g_LinesCube);
		if (SelectRender == 3)
			glCallList(g_PointCube);
		break;
	}
	case 4:
	{
		if (SelectRender == 1)
			glCallList(g_SolidBox);
		if (SelectRender == 2)
			glCallList(g_LinesBox);
		if (SelectRender == 3)
			glCallList(g_PointBox);
		break;
	}
	case 5:
	{
		if (SelectRender == 1)
			glCallList(g_SolidSphere);
		if (SelectRender == 2)
			glCallList(g_WireSphere);
		break;
	}
	case 6:
	{
		glCallList(g_SolidCylinder);
		break;
	}
	case 7:
	{
		glCallList(g_SolidTruncatedCone);
		break;
	}
	case 8:
	{
		glCallList(g_SolidCone);
		break;
	}
	case 9:
	{
		if (SelectRender == 1)
			glCallList(g_SolidPyramid);
		if (SelectRender == 2)
			glCallList(g_LinesPyramid);
		if (SelectRender == 3)
			glCallList(g_PointPyramid);
		break;
	}
	case 10:
	{
		if (SelectRender == 1)
			glCallList(g_SolidFrustum);
		if (SelectRender == 2)
			glCallList(g_LinesFrustum);
		if (SelectRender == 3)
			glCallList(g_PointFrustum);
		break;
	}
	}
}

// COpenGL_MFCView drawing


void COpenGL_MFCView::OnDraw(CDC* /*pDC*/)
{
	COpenGL_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void COpenGL_MFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COpenGL_MFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COpenGL_MFCView diagnostics

#ifdef _DEBUG
void COpenGL_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGL_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGL_MFCDoc* COpenGL_MFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGL_MFCDoc)));
	return (COpenGL_MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenGL_MFCView message handlers


int COpenGL_MFCView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_hTimer = SetTimer(1, 100, NULL);
	SetupOpenGL();
	InitOpenGL();
	//InitShadow();
	return 0;
}

//Reshape Function
void COpenGL_MFCView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	CRect rect;
	GetClientRect(rect);
	//int size = min(rect.Width(), rect.Height());
	glViewport(0, 0, rect.Width(), rect.Height());
	//glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)rect.Width() / (float)rect.Height();
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void COpenGL_MFCView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnTimer(nIDEvent);

	m_angle += 10.0f;
	if (m_angle > 360)
		m_angle = m_angle - 360.0f;

	InvalidateRect(NULL, false);
}



//RenderScene
void COpenGL_MFCView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
	//glCallList(g_Base);
	glPushMatrix();
	DrawCoordinate();

	//glCallList(g_Base);

	//TranslateF
	glTranslatef(xTr, yTr, zTr);
	//RotateF
	glRotatef(angleRo, xRo, yRo, zRo);
	//Select Shape and Render
	Select_Shape_Render();

	glPopMatrix();


	glFlush();
	SwapBuffers(dc.m_ps.hdc);

}


void COpenGL_MFCView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	RemoveOpenGL();

	if (m_hTimer > 0)
	{
		KillTimer(m_hTimer);
		m_hTimer = -1;
	}
}



//Select Shape and Render UI
void COpenGL_MFCView::OnTeapotSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 1;
	SelectRender = 1;
}

void COpenGL_MFCView::OnTeapotWire()
{
	// TODO: Add your command handler code here
	SelectShape = 1;
	SelectRender = 2;
}

void COpenGL_MFCView::OnTorusSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 2;
	SelectRender = 1;
}

void COpenGL_MFCView::OnTorusWire()
{
	// TODO: Add your command handler code here
	SelectShape = 2;
	SelectRender = 2;
}

void COpenGL_MFCView::OnCubeSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 3;
	SelectRender = 1;
}

void COpenGL_MFCView::OnCubeLine()
{
	// TODO: Add your command handler code here
	SelectShape = 3;
	SelectRender = 2;
}

void COpenGL_MFCView::OnCubePoint()
{
	// TODO: Add your command handler code here
	SelectShape = 3;
	SelectRender = 3;
}

void COpenGL_MFCView::OnBoxSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 4;
	SelectRender = 1;
}

void COpenGL_MFCView::OnBoxLines()
{
	// TODO: Add your command handler code here
	SelectShape = 4;
	SelectRender = 2;
}

void COpenGL_MFCView::OnBoxPoint()
{
	// TODO: Add your command handler code here
	SelectShape = 4;
	SelectRender = 3;
}

void COpenGL_MFCView::OnSphereSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 5;
	SelectRender = 1;
}

void COpenGL_MFCView::OnSphereWire()
{
	// TODO: Add your command handler code here
	SelectShape = 5;
	SelectRender = 2;
}

void COpenGL_MFCView::OnCylinderSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 6;
	SelectRender = 1;
}

void COpenGL_MFCView::OnTruncatedconeSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 7;
	SelectRender = 1;
}

void COpenGL_MFCView::OnConeSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 8;
	SelectRender = 1;
}

void COpenGL_MFCView::OnPyramidSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 9;
	SelectRender = 1;
}

void COpenGL_MFCView::OnPyramidLines()
{
	// TODO: Add your command handler code here
	SelectShape = 9;
	SelectRender = 2;
}

void COpenGL_MFCView::OnPyramidPoint()
{
	// TODO: Add your command handler code here
	SelectShape = 9;
	SelectRender = 3;
}

void COpenGL_MFCView::OnFrustumSolid()
{
	// TODO: Add your command handler code here
	SelectShape = 10;
	SelectRender = 1;
}

void COpenGL_MFCView::OnFrustumLines()
{
	// TODO: Add your command handler code here
	SelectShape = 10;
	SelectRender = 2;
}

void COpenGL_MFCView::OnFrustumPoint()
{
	// TODO: Add your command handler code here
	SelectShape = 10;
	SelectRender = 3;
}

void COpenGL_MFCView::OnUpdateTeapotSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 1 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateTeapotWire(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 1 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateTorusSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 2 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateTorusWire(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 2 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateCubeSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 3 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateCubeLine(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 3 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateCubePoint(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 3 && SelectRender == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateBoxSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 4 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateBoxLines(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 4 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateBoxPoint(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 4 && SelectRender == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateSphereSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 5 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateSphereWire(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 5 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateCylinderSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 6 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateTruncatedconeSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 7 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateConeSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 8 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdatePyramidSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 9 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdatePyramidLines(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 9 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdatePyramidPoint(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 9 && SelectRender == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateFrustumSolid(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 10 && SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateFrustumLines(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 10 && SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnUpdateFrustumPoint(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectShape == 10 && SelectRender == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnAffineTranslatef()
{

	TranslatefSettingDlg dlg;
	dlg.DoModal();
	xTr = dlg.GetAdjustXtr();
	yTr = dlg.GetAdjustYtr();
	zTr = dlg.GetAdjustZtr();
}


void COpenGL_MFCView::OnUpdateAffineTranslatef(CCmdUI* pCmdUI)
{

}


void COpenGL_MFCView::OnAffineRotatef()
{
	// TODO: Add your command handler code here
	RotateSettingDlg dlg;
	dlg.DoModal();
	angleRo = dlg.GetAdjustAro();
	xRo = dlg.GetAdjustXro();
	yRo = dlg.GetAdjustYro();
	zRo = dlg.GetAdjustZro();
}
