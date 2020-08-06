
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
#include "stb_image.h"
#include "Projection_Setting.h"

#include "GL/GL.H"
#include "GL/GLU.H"
#include "GL/glut.h"
#include "GL/GLAUX.H"
#include <stdio.h>

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
	ON_COMMAND(ID_AFFINE_TRANSLATEF32825, &COpenGL_MFCView::OnAffineTranslatefMouse)
	ON_UPDATE_COMMAND_UI(ID_AFFINE_TRANSLATEF32825, &COpenGL_MFCView::OnUpdateAffineTranslatefMouse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_AFFINE_ROTATEF32826, &COpenGL_MFCView::OnAffineRotatefMouse)
	ON_UPDATE_COMMAND_UI(ID_AFFINE_ROTATEF32826, &COpenGL_MFCView::OnUpdateAffineRotatefMouse)
	ON_COMMAND(ID_LoadTEXTURE, &COpenGL_MFCView::OnLoadtexture)
	ON_COMMAND(ID_TEXTURE_OFFTEXTURE, &COpenGL_MFCView::OnTextureOfftexture)
	ON_COMMAND(ID_PROJECTION_ON, &COpenGL_MFCView::OnProjectionOn)
	ON_COMMAND(ID_PROJECTION_OFF, &COpenGL_MFCView::OnProjectionOff)
	ON_UPDATE_COMMAND_UI(ID_LoadTEXTURE, &COpenGL_MFCView::OnUpdateLoadtexture)
	ON_UPDATE_COMMAND_UI(ID_PROJECTION_ON, &COpenGL_MFCView::OnUpdateProjectionOn)
	ON_UPDATE_COMMAND_UI(ID_TEXTURE_OFFTEXTURE, &COpenGL_MFCView::OnUpdateTextureOfftexture)
	ON_COMMAND(ID_ANIMATION_ANIMATION1, &COpenGL_MFCView::OnAnimationAnimation1)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION_ANIMATION1, &COpenGL_MFCView::OnUpdateAnimationAnimation1)
	ON_COMMAND(ID_ANIMATION_ANIMATION2, &COpenGL_MFCView::OnAnimationAnimation2)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION_ANIMATION2, &COpenGL_MFCView::OnUpdateAnimationAnimation2)
	ON_COMMAND(ID_ANIMATION_ANIMATION3, &COpenGL_MFCView::OnAnimationAnimation3)
	ON_UPDATE_COMMAND_UI(ID_ANIMATION_ANIMATION3, &COpenGL_MFCView::OnUpdateAnimationAnimation3)
	ON_COMMAND(ID_LIGHT_LIGHTPOSITION, &COpenGL_MFCView::OnLightLightposition)
	ON_UPDATE_COMMAND_UI(ID_LIGHT_LIGHTPOSITION, &COpenGL_MFCView::OnUpdateLightLightposition)
	ON_COMMAND(ID_AFFINE_SCALEF, &COpenGL_MFCView::OnAffineScalefMouse)
	ON_UPDATE_COMMAND_UI(ID_AFFINE_SCALEF, &COpenGL_MFCView::OnUpdateAffineScalefMouse)
	ON_COMMAND(ID_LIGHT_SHADOW, &COpenGL_MFCView::OnLightShadow)
	ON_UPDATE_COMMAND_UI(ID_LIGHT_SHADOW, &COpenGL_MFCView::OnUpdateLightShadow)
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
	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	GLfloat light_pos[] = { 5.0, 5.0, 5.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 0.8, 0.8, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.8, 0.8, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
	
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);


}

void COpenGL_MFCView::DrawCoordinate()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 100.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

// Get the size to draw function
void COpenGL_MFCView::Draw_Size(float x1, float y1, float x2, float y2) {
	width = abs(x1 - x2) / 80;
	height = abs(y1 - y2) / 80;
	radius = sqrt(width * width + height * height);
}

void COpenGL_MFCView::DrawShadow(int nShadow)
{

	if (nShadow == 0)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.2, 0.2, 0.2);
	Draw_Scene();
}

// Draw shape function
void COpenGL_MFCView::Draw_Scene() {
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
			GLuint gl = MakeSolidTeapot(radius);
			glCallList(gl);
			break;
		}
		case 2:
		{
			GLuint gl =MakeSolidTorus(0.3 * radius, radius, 32, 32);
			glCallList(gl);
			break;
		}
		case 3:
		{
			GLuint gl = MakeSolidCube(radius/5);
			glCallList(gl);
			break;
		}
		case 4:
		{
			GLuint gl = MakeSolidBox(width,height,height/2);
			glCallList(gl);
			break;
		}
		case 5:
		{
			GLuint gl = MakeSolidSphere(radius);
			glCallList(gl);
			break;
		}
		case 6:
		{
			GLuint gl = MakeSolidCylinder(radius/5, height);
			glCallList(gl);
			break;
		}
		case 7:
		{
			GLuint gl = MakeSolidTruncatedCone(radius/3,radius/6, height);
			glCallList(gl);
			break;
		}
		case 8:
		{
			GLuint gl = MakeSolidCone(radius / 3, height);
			glCallList(gl);
			break;
		}
		case 9:
		{
			GLuint gl = MakeSolidPyramid(width, height);
			glCallList(gl);
			break;
		}
		case 10:
		{
			GLuint gl = MakeSolidFrustumShape(width,width/2, height);
			glCallList(gl);
			break;
		}
		}
}

void COpenGL_MFCView::RenderAnimation()
{
	switch (SelectAnimation)
	{
	default:
	{
		xTr = yTr = zTr = angleRo = 0;
		break;
	}
	case 1:
	{
		xRo = 0;
		yRo = 1;
		zRo = 0;
		angleRo = m_angle;
		xTr = m_x;
		yTr = 0;
		zTr = 0;
		break;
	}
	case 2:
	{
		xRo = 1;
		yRo = 0;
		zRo = 0;
		angleRo = m_angle;
		xTr = 0;
		yTr = m_y;
		zTr = 0;
		break;
	}
	case 3:
	{
		xRo = 0;
		yRo = 0;
		zRo = 1;
		angleRo = m_angle;
		xTr = m_x;
		yTr = m_y;
		zTr = -abs(m_x);
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
	ratio = (float)rect.Width() / (float)rect.Height();
	WidthScreen = (float)rect.Width();
	HeightScreen = (float)rect.Height();
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);

	m_point2.x = WidthScreen / 2;
	m_point2.y = HeightScreen / 2;
}

void COpenGL_MFCView::OnTimer(UINT_PTR nIDEvent)
{
	CView::OnTimer(nIDEvent);

	m_angle += 10.0f;
	if (m_angle > 360)
		m_angle = m_angle - 360.0f;

	if (m_x == 8.0)
		checkx = 1;
	if (m_x == -8.0)
		checkx = 0;
	if (checkx == 1)
		m_x -= 0.25;
	else
		m_x += 0.25;

	if (m_y == 4.0)
		checky = 1;
	if (m_y == -4.0)
		checky = 0;
	if (checky == 1)
		m_y -= 0.25;
	else
		m_y += 0.25;
	InvalidateRect(NULL, false);
}

void set_Projection(float fovy, float aspect, float znear, float zfar)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, aspect, znear, zfar);
	glMatrixMode(GL_MODELVIEW);
}
float distance(int x1, int y1, int x2, int y2)
{
	// Calculating distance 
	return sqrt(pow(x2 - x1, 2) +
		pow(y2 - y1, 2) * 1.0);
}
//RenderScene
void COpenGL_MFCView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	if (project == 0) {
		set_Projection(45.0f, ratio, 1.0, 100.0);
	}
	if (project == 1) {
		set_Projection(fovy, aspect, znear, zfar);
	}

	if (SelectShadow == 1)
		RenderSceneShadow();
	else
		RenderSceneNormal();

	glFlush();
	SwapBuffers(dc.m_ps.hdc);

}

void COpenGL_MFCView::RenderSceneShadow()
{

	M3DVector3f points[3] = { { -3.0f, -7.0f, -2.0f },
	{ -3.0f, -7.0f, 2.0f },
	{ 4.0f, -7.0f, 2.0f } };
	// Get the plane equation from three points on the ground
	M3DVector4f vPlaneEquation;
	m3dGetPlaneEquation(vPlaneEquation, points[0], points[1], points[2]);


	// Calculate projection matrix to draw shadow on the ground
	GLfloat lightPos[] = { -(WidthScreen / 2) / 20, (HeightScreen / 2) / 20, 10.0, 0.0 };
	if (SelectLightPos == 1)
	{

		lightPos[0] = -(WidthScreen / 2 - m_point2.x) / 10;
		lightPos[1] = (HeightScreen / 2 - m_point2.y) / 10;
	}
	m3dMakePlanarShadowMatrix(shadowMat, vPlaneEquation, lightPos);



	glEnable(GL_NORMALIZE);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//// Move out Z axis so we can see everything
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	gluLookAt(0.0, 15.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.1, 0.8);
	glVertex3f(25.0f, -5.0f, -25.0f);
	glVertex3f(-25.0f, -5.0f, -25.0f);
	glVertex3f(-25.0f, -5.0f, 25.0f);
	glVertex3f(25.0f, -5.0f, 25.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);


	RenderAnimation();

	//ScaleF
	if (ScalefMouseCheck == 1)
		glScalef((WidthScreen / 2 - m_point2.x) / 200, (HeightScreen / 2 - m_point2.y) / 200, 1.0);
	else
		glScalef(1.0, 1.0, 1.0);

	//TranslateF
	if (TranslateMouseCheck == 1)
		glTranslatef((m_point2.x - WidthScreen / 2) / 80, (HeightScreen / 2 - m_point2.y) / 80, zTr);
	else
		glTranslatef(xTr, yTr, zTr);

	//RotateF
	if (RotatefMouseCheck == 1)
	{
		angleRo = distance(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
		glRotatef(angleRo, (m_point2.y - m_point1.y), -(m_point1.x - m_point2.x), zRo);
	}
	else
		glRotatef(angleRo, xRo, yRo, zRo);

	if (SelectShape==2|| SelectShape == 5|| SelectShape == 6 || SelectShape == 7|| SelectShape == 8)
	{
		glEnable(GL_TEXTURE_GEN_S);                     // Enable Texture Coord Generation For S 
		glEnable(GL_TEXTURE_GEN_T);                     // Enable Texture Coord Generation For T
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	if (draw == 1)
	{
		glPushMatrix();
		//(WidthScreen / 2 - m_point2.x) / 40, (HeightScreen / 2 - m_point2.y)
		//Draw_Size(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
		Draw_Size(WidthScreen / 2, HeightScreen / 2, m_point2.x, m_point2.y);
		DrawShadow(0);
		glPopMatrix();
	}
	else
	{
		DrawShadow(0);
	}
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	glPopMatrix();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glPushMatrix();


	glMultMatrixf((float*)shadowMat);


	RenderAnimation();

	//ScaleF
	if (ScalefMouseCheck == 1)
		glScalef((WidthScreen / 2 - m_point2.x) / 200, (HeightScreen / 2 - m_point2.y) / 200, 1.0);
	else
		glScalef(1.0, 1.0, 1.0);

	//TranslateF
	if (TranslateMouseCheck == 1)
		glTranslatef((m_point2.x - WidthScreen / 2) / 80, (HeightScreen / 2 - m_point2.y) / 80, zTr);
	else
		glTranslatef(xTr, yTr, zTr);

	//RotateF
	if (RotatefMouseCheck == 1)
	{
		angleRo = distance(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
		glRotatef(angleRo, (m_point2.y - m_point1.y), -(m_point1.x - m_point2.x), zRo);
	}
	else
		glRotatef(angleRo, xRo, yRo, zRo);

	if (draw == 1)
	{
		glPushMatrix();
		//(WidthScreen / 2 - m_point2.x) / 40, (HeightScreen / 2 - m_point2.y)
		//Draw_Size(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
		Draw_Size(WidthScreen / 2, HeightScreen / 2, m_point2.x, m_point2.y);
		DrawShadow(1);
		glPopMatrix();
	}
	else
	{
		DrawShadow(1);
	}


	glPopMatrix();

	//glPushMatrix();
	//glTranslatef(lightPos[0] / 10, lightPos[1] / 10, lightPos[2] / 10);
	//glColor3ub(255, 255, 0);
	//glutSolidSphere(0.5f, 10, 10);
	//glPopMatrix();


	glEnable(GL_DEPTH_TEST);
}

void COpenGL_MFCView::RenderSceneNormal()
{
	if (SelectLightPos == 1)
	{
		GLfloat light_pos[] = { -(WidthScreen / 2 - m_point2.x) / 40, (HeightScreen / 2 - m_point2.y) / 40, 15.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();
	
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);

	glPushMatrix();
	DrawCoordinate();


	RenderAnimation();

	//ScaleF
	if (ScalefMouseCheck == 1)
		glScalef( (WidthScreen / 2 - m_point2.x) / 200, (HeightScreen / 2 - m_point2.y) / 200, 1.0);
	else
		glScalef(1.0, 1.0, 1.0);

	//TranslateF
	if (TranslateMouseCheck == 1)
		glTranslatef((m_point2.x - WidthScreen / 2) / 80, (HeightScreen / 2 - m_point2.y) / 80, zTr);
	else
		glTranslatef(xTr, yTr, zTr);

	//RotateF
	if (RotatefMouseCheck == 1)
	{
		angleRo = distance(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
		glRotatef(angleRo, (m_point2.y - m_point1.y), -(m_point1.x - m_point2.x), zRo);
	}
	else
		glRotatef(angleRo, xRo, yRo, zRo);
	
	// Texture mapping on quaratic object
	if (SelectShape==2|| SelectShape == 5|| SelectShape == 6 || SelectShape == 7|| SelectShape == 8)
	{
		glEnable(GL_TEXTURE_GEN_S);                     // Enable Texture Coord Generation For S 
		glEnable(GL_TEXTURE_GEN_T);                     // Enable Texture Coord Generation For T
	}

	//Select Shape and Render and Texture enable
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	if (draw == 1)
	{
		glPushMatrix();
		//(WidthScreen / 2 - m_point2.x) / 40, (HeightScreen / 2 - m_point2.y)
		//Draw_Size(m_point1.x, m_point1.y, m_point2.x, m_point2.y);
		Draw_Size(WidthScreen / 2, HeightScreen / 2, m_point2.x, m_point2.y);
		Draw_Scene();
		glPopMatrix();
	}
	else
	{
		Draw_Scene();
	}

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 1;
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
	draw = 0;
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
	draw = 0;
	RotateSettingDlg dlg;
	dlg.DoModal();
	angleRo = dlg.GetAdjustAro();
	xRo = dlg.GetAdjustXro();
	yRo = dlg.GetAdjustYro();
	zRo = dlg.GetAdjustZro();
}

void COpenGL_MFCView::OnAffineTranslatefMouse()
{
	draw = 0;
	xTr = 0.0f, yTr = 0.0f, zTr = 0.0f;
	if (TranslateMouseCheck == 1)
		TranslateMouseCheck = 0;
	else
		TranslateMouseCheck = 1;
}


void COpenGL_MFCView::OnUpdateAffineTranslatefMouse(CCmdUI* pCmdUI)
{
	draw = 0;
	if (TranslateMouseCheck == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnAffineRotatefMouse()
{
	draw = 0;
	angleRo = 0.0f, xRo = 0.0f, yRo = 0.0f, zRo = 0.0f;
	if (RotatefMouseCheck == 1)
		RotatefMouseCheck = 0;
	else
		RotatefMouseCheck = 1;
}


void COpenGL_MFCView::OnUpdateAffineRotatefMouse(CCmdUI* pCmdUI)
{
	if (RotatefMouseCheck == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnAffineScalefMouse()
{
	draw = 0;
	if (ScalefMouseCheck == 1)
		ScalefMouseCheck = 0;
	else
	{
		ScalefMouseCheck = 1;
		m_point2.x = WidthScreen / 2 - 200;
		m_point2.y = HeightScreen / 2 - 200;
	}
}


void COpenGL_MFCView::OnUpdateAffineScalefMouse(CCmdUI* pCmdUI)
{
	if (ScalefMouseCheck == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void COpenGL_MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_point1 = point;
	m_point2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void COpenGL_MFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_point2 = point;
	//Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void COpenGL_MFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags && MK_LBUTTON && (TranslateMouseCheck||RotatefMouseCheck|| SelectLightPos || ScalefMouseCheck || draw))
	{
		m_point2 = point;
		//Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void COpenGL_MFCView::OnLoadtexture()
{
	SelectTexture = 1;
	draw = 0;

	GLfloat diff_use[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	CDC* pDC = GetDC();


	CFileDialog dlg(true);
	if (dlg.DoModal() == IDOK) {
		CString str = dlg.GetPathName();
		CT2CA temp(str);
		fileName = (char*)(temp);
		stbi_set_flip_vertically_on_load(true);

		// Texture component
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// Load image file and get size, channel of image
		int width, height, nrChannels;
		unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);

		// Buid a Texture map to do the mapping
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		stbi_image_free(data);

		//--------------------------------
		CView::OnInitialUpdate();
	}

}


void COpenGL_MFCView::OnTextureOfftexture()
{
	// TODO: Add your command handler code here
	Draw_Scene();
	texture = 0;
	fileName = NULL;
	SelectTexture = 0;
	GLfloat diff_use[] = { 0.8, 0.8, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}


void COpenGL_MFCView::OnProjectionOn()
{
	// TODO: Add your command handler code here
	draw = 0;
	if (project == 1)
		project = 0;
	else
		project = 1;
	if (project == 1)
	{
		project = 1;
		Projection_Setting dlg;
		dlg.DoModal();
		fovy = dlg.get_fovy();
		aspect = dlg.get_aspect();
		znear = dlg.get_znear();
		zfar = dlg.get_zfar();
	}
}


void COpenGL_MFCView::OnProjectionOff()
{
	// TODO: Add your command handler code here
	project = 0;
}

void COpenGL_MFCView::OnUpdateProjectionOn(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (project == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnUpdateLoadtexture(CCmdUI* pCmdUI)
{
	if (SelectTexture == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);

}


void COpenGL_MFCView::OnUpdateTextureOfftexture(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (SelectTexture == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnAnimationAnimation1()
{
	draw = 0;
	if (SelectAnimation != 1)
	{
		SelectAnimation = 1;
		m_x = m_y = 0.0;
	}
	else
		SelectAnimation = 0;
}


void COpenGL_MFCView::OnUpdateAnimationAnimation1(CCmdUI* pCmdUI)
{
	if (SelectAnimation == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnAnimationAnimation2()
{
	draw = 0;
	if (SelectAnimation != 2)
	{
		SelectAnimation = 2;
		m_x = m_y = 0.0;
	}
	else
		SelectAnimation = 0;
}


void COpenGL_MFCView::OnUpdateAnimationAnimation2(CCmdUI* pCmdUI)
{
	if (SelectAnimation == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}



void COpenGL_MFCView::OnAnimationAnimation3()
{
	draw = 0;
	if (SelectAnimation != 3)
	{
		SelectAnimation = 3;
		m_x = m_y = 0.0;
	}
	else
		SelectAnimation = 0;
}


void COpenGL_MFCView::OnUpdateAnimationAnimation3(CCmdUI* pCmdUI)
{
	if (SelectAnimation == 3)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}


void COpenGL_MFCView::OnLightLightposition()
{
	draw = 0;
	if (SelectLightPos == 1)
		SelectLightPos = 0;
	else
		SelectLightPos = 1;
}


void COpenGL_MFCView::OnUpdateLightLightposition(CCmdUI* pCmdUI)
{
	if (SelectLightPos == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}



void COpenGL_MFCView::OnLightShadow()
{
	draw = 0;
	if (SelectShadow == 1)
		SelectShadow = 0;
	else
		SelectShadow = 1;
}


void COpenGL_MFCView::OnUpdateLightShadow(CCmdUI* pCmdUI)
{
	if (SelectShadow == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}
