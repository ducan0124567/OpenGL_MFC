
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
	ON_COMMAND(ID_AFFINE_TRANSLATEF, &COpenGL_MFCView::OnAffineTranslatef)
	ON_UPDATE_COMMAND_UI(ID_AFFINE_TRANSLATEF, &COpenGL_MFCView::OnUpdateAffineTranslatef)
	ON_COMMAND(ID_AFFINE_ROTATEF32804, &COpenGL_MFCView::OnAffineRotatef)
	ON_COMMAND(ID_SELECTRENDER_SOLID, &COpenGL_MFCView::OnSelectrenderSolid)
	ON_COMMAND(ID_SELECTRENDER_LINES, &COpenGL_MFCView::OnSelectrenderLines)
	ON_COMMAND(ID_SELECTRENDER_POINT, &COpenGL_MFCView::OnSelectrenderPoint)
	ON_UPDATE_COMMAND_UI(ID_SELECTRENDER_SOLID, &COpenGL_MFCView::OnUpdateSelectrenderSolid)
	ON_UPDATE_COMMAND_UI(ID_SELECTRENDER_LINES, &COpenGL_MFCView::OnUpdateSelectrenderLines)
	ON_UPDATE_COMMAND_UI(ID_SELECTRENDER_POINT, &COpenGL_MFCView::OnUpdateSelectrenderPoint)
	ON_COMMAND(ID_SHAPES_TEAPOT32815, &COpenGL_MFCView::OnShapesTeapot)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_TEAPOT32815, &COpenGL_MFCView::OnUpdateShapesTeapot)
	ON_COMMAND(ID_SHAPES_TORUS32816, &COpenGL_MFCView::OnShapesTorus)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_TORUS32816, &COpenGL_MFCView::OnUpdateShapesTorus)
	ON_COMMAND(ID_SHAPES_CUBE32817, &COpenGL_MFCView::OnShapesCube)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_CUBE32817, &COpenGL_MFCView::OnUpdateShapesCube)
	ON_COMMAND(ID_SHAPES_BOX32818, &COpenGL_MFCView::OnShapesBox)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_BOX32818, &COpenGL_MFCView::OnUpdateShapesBox)
	ON_COMMAND(ID_SHAPES_SPHERE32819, &COpenGL_MFCView::OnShapesSphere)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_SPHERE32819, &COpenGL_MFCView::OnUpdateShapesSphere)
	ON_COMMAND(ID_SHAPES_CYLINDER32820, &COpenGL_MFCView::OnShapesCylinder)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_CYLINDER32820, &COpenGL_MFCView::OnUpdateShapesCylinder)
	ON_COMMAND(ID_SHAPES_TRUNCATEDCONE32821, &COpenGL_MFCView::OnShapesTruncatedcone)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_TRUNCATEDCONE32821, &COpenGL_MFCView::OnUpdateShapesTruncatedcone)
	ON_COMMAND(ID_SHAPES_CONE32822, &COpenGL_MFCView::OnShapesCone)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_CONE32822, &COpenGL_MFCView::OnUpdateShapesCone)
	ON_COMMAND(ID_SHAPES_PYRAMID32823, &COpenGL_MFCView::OnShapesPyramid)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_PYRAMID32823, &COpenGL_MFCView::OnUpdateShapesPyramid)
	ON_COMMAND(ID_SHAPES_FRUSTUM32824, &COpenGL_MFCView::OnShapesFrustum)
	ON_UPDATE_COMMAND_UI(ID_SHAPES_FRUSTUM32824, &COpenGL_MFCView::OnUpdateShapesFrustum)
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

	//Torus
	g_SolidTorus = MakeSolidTorus(1.0f, 3.00f, 32, 32);

	//Cube
	g_SolidCube = MakeSolidCube(3.0);

	//Box
	g_SolidBox = MakeSolidBox(5.0, 2.0, 4.0);

	//Sphere
	g_SolidSphere = MakeSolidSphere(4.0);

	//Cylinder
	g_SolidCylinder = MakeSolidCylinder(4.0, 5.0);

	//TruncatedCone
	g_SolidTruncatedCone = MakeSolidTruncatedCone(3.0, 1.0, 5.0);

	//Cone
	g_SolidCone = MakeSolidCone(2.0, 8.0);


	//Pyramid
	g_SolidPyramid = MakeSolidPyramid(3.0, 5.0);

	
	//Frustum
	g_SolidFrustum = MakeSolidFrustumShape(5.0, 3.0, 6.0);


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
	switch (SelectRender)
	{
	default:
		break;
	case 1:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	}
	case 2:
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	}
	case 3:
	{
		glPointSize(3);
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;
	}
	}
	switch (SelectShape)
	{
	default:
		break;
	case 1:
	{
		glCallList(g_SolidTeapot);
		break;
	}
	case 2:
	{
		glCallList(g_SolidTorus);
		break;
	}
	case 3:
	{
		glCallList(g_SolidCube);
		break;
	}
	case 4:
	{
		glCallList(g_SolidBox);
		break;
	}
	case 5:
	{
		glCallList(g_SolidSphere);
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
		glCallList(g_SolidPyramid);
		break;
	}
	case 10:
	{
		glCallList(g_SolidFrustum);
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
void COpenGL_MFCView::OnSelectrenderSolid()
{
	SelectRender = 1;
}


void COpenGL_MFCView::OnSelectrenderLines()
{
	SelectRender = 2;
}


void COpenGL_MFCView::OnSelectrenderPoint()
{
	SelectRender = 3;
}


void COpenGL_MFCView::OnUpdateSelectrenderSolid(CCmdUI* pCmdUI)
{
	if (SelectRender == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnUpdateSelectrenderLines(CCmdUI* pCmdUI)
{
	if (SelectRender == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnUpdateSelectrenderPoint(CCmdUI* pCmdUI)
{
	if (SelectRender == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesTeapot()
{
	SelectShape = 1;
}


void COpenGL_MFCView::OnUpdateShapesTeapot(CCmdUI* pCmdUI)
{
	if (SelectShape == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesTorus()
{
	SelectShape = 2;
}


void COpenGL_MFCView::OnUpdateShapesTorus(CCmdUI* pCmdUI)
{
	if (SelectShape == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesCube()
{
	SelectShape = 3;
}


void COpenGL_MFCView::OnUpdateShapesCube(CCmdUI* pCmdUI)
{
	if (SelectShape == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesBox()
{
	SelectShape = 4;
}


void COpenGL_MFCView::OnUpdateShapesBox(CCmdUI* pCmdUI)
{
	if (SelectShape == 4)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesSphere()
{
	SelectShape = 5;
}


void COpenGL_MFCView::OnUpdateShapesSphere(CCmdUI* pCmdUI)
{
	if (SelectShape == 5)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesCylinder()
{
	SelectShape = 6;
}


void COpenGL_MFCView::OnUpdateShapesCylinder(CCmdUI* pCmdUI)
{
	if (SelectShape == 6)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesTruncatedcone()
{
	SelectShape = 7;
}


void COpenGL_MFCView::OnUpdateShapesTruncatedcone(CCmdUI* pCmdUI)
{
	if (SelectShape == 7)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesCone()
{
	SelectShape = 8;
}


void COpenGL_MFCView::OnUpdateShapesCone(CCmdUI* pCmdUI)
{
	if (SelectShape == 8)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesPyramid()
{
	SelectShape = 9;
}


void COpenGL_MFCView::OnUpdateShapesPyramid(CCmdUI* pCmdUI)
{
	if (SelectShape == 9)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnShapesFrustum()
{
	SelectShape = 10;
}


void COpenGL_MFCView::OnUpdateShapesFrustum(CCmdUI* pCmdUI)
{
	if (SelectShape == 10)
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

	RotateSettingDlg dlg;
	dlg.DoModal();
	angleRo = dlg.GetAdjustAro();
	xRo = dlg.GetAdjustXro();
	yRo = dlg.GetAdjustYro();
	zRo = dlg.GetAdjustZro();
}