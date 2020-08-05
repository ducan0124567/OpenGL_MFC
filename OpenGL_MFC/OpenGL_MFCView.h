
// OpenGL_MFCView.h : interface of the COpenGL_MFCView class
//

#pragma once
#include "GL/glut.h"

class COpenGL_MFCView : public CView
{
protected: // create from serialization only
	COpenGL_MFCView() noexcept;
	DECLARE_DYNCREATE(COpenGL_MFCView)
	
// Attributes
public:
	COpenGL_MFCDoc* GetDocument() const;
	HGLRC m_hRC;
	float m_angle = 0.0f;
	int m_hTimer = 0;
	float m_x = 0.0;
	float m_y = 0.0;
	int checkx = 0;
	int checky = 0;
	float WidthScreen, HeightScreen;

	// Draw Scene
	int draw = 0;
	float width = 3.0;
	float height = 3.0;
	double radius = 3.0;

	// SelectLightPos
	// 0 - off
	// 1 - On
	int SelectLightPos;

	//SelectScalefMouss
	// 0 - off
	// 1 - on
	int ScalefMouseCheck;

	// Animation
	// 0 - off
	// 1 - animation 1
	// 2 - animtion 2
	// 3 - animtion 3
	int SelectAnimation;

	int SelectTexture = 0;
	//Check Translatef with Mouse
	// 0 - off
	// 1 - on
	int TranslateMouseCheck;

	//Check Rotatef with Mouse
	// 0 - off
	// 1 - on
	int RotatefMouseCheck;

	//LbuttonDown
	CPoint m_point1;
	//LbuttonUp
	CPoint m_point2;

	//Base
	GLuint g_Base;
	//Teapot
	GLuint g_SolidTeapot;
	//Torus
	GLuint g_SolidTorus;
	//Cube
	GLuint g_SolidCube;
	//box
	GLuint g_SolidBox;
	//Sphere
	GLuint g_SolidSphere;
	//Cylinder
	GLuint g_SolidCylinder;
	//TruncatedCone
	GLuint g_SolidTruncatedCone;
	//Cone
	GLuint g_SolidCone;
	//Pyramid
	GLuint g_SolidPyramid;
	//Frustum
	GLuint g_SolidFrustum;

	//1 - Teapot
	//2 - Torus
	//3 - Cube
	//4 - Box
	//5 - Sphere
	//6 - Cylinder
	//7 - TruncatedCone
	//8 - Cone
	//9 - Pyramid
	//10 - Frustum
	int SelectShape = 1;

	//1 - Solid
	//2 - Lines
	//3 - Point
	int SelectRender = 1;


	//Translate
	GLfloat xTr = 0.0f, yTr = 0.0f, zTr = 0.0f;

	// 0 - Off
	// 1 - On
	int SelectTranslate = 0;

	//RotateF
	GLfloat angleRo = 0.0f, xRo = 0.0f, yRo = 0.0f, zRo = 0.0f;

	//Texture
	char* fileName;
	GLuint texture;
	
	//Projection
	int project;
	float ratio;
	float fovy;
	float aspect;
	float znear;
	float zfar;
	//gluLookAt
	//GLdouble eyeX = 5.0, eyeY = 10.0, eyeZ = 15.0, centerX = 0.0, centerY = 0.0, centerZ = 0.0, upX = 0.0, upY = 1.0, upZ = 0.0;
	GLdouble eyeX = 0.0, eyeY = 0.0, eyeZ = 15.0, centerX = 0.0, centerY = 0.0, centerZ = 0.0, upX = 0.0, upY = 1.0, upZ = 0.0;
	void SetupOpenGL();
	void RemoveOpenGL();
	void InitOpenGL(void);
	void DrawCoordinate();

	void RenderAnimation();
	void Draw_Scene();
	void Draw_Size(float x1, float y1, float x2, float y2);


// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:

// Implementation
public:
	virtual ~COpenGL_MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnAffineTranslatef();
	afx_msg void OnUpdateAffineTranslatef(CCmdUI* pCmdUI);
	afx_msg void OnAffineRotatef();
	afx_msg void OnSelectrenderSolid();
	afx_msg void OnSelectrenderLines();
	afx_msg void OnSelectrenderPoint();
	afx_msg void OnUpdateSelectrenderSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSelectrenderLines(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSelectrenderPoint(CCmdUI* pCmdUI);
	afx_msg void OnShapesTeapot();
	afx_msg void OnUpdateShapesTeapot(CCmdUI* pCmdUI);
	afx_msg void OnShapesTorus();
	afx_msg void OnUpdateShapesTorus(CCmdUI* pCmdUI);
	afx_msg void OnShapesCube();
	afx_msg void OnUpdateShapesCube(CCmdUI* pCmdUI);
	afx_msg void OnShapesBox();
	afx_msg void OnUpdateShapesBox(CCmdUI* pCmdUI);
	afx_msg void OnShapesSphere();
	afx_msg void OnUpdateShapesSphere(CCmdUI* pCmdUI);
	afx_msg void OnShapesCylinder();
	afx_msg void OnUpdateShapesCylinder(CCmdUI* pCmdUI);
	afx_msg void OnShapesTruncatedcone();
	afx_msg void OnUpdateShapesTruncatedcone(CCmdUI* pCmdUI);
	afx_msg void OnShapesCone();
	afx_msg void OnUpdateShapesCone(CCmdUI* pCmdUI);
	afx_msg void OnShapesPyramid();
	afx_msg void OnUpdateShapesPyramid(CCmdUI* pCmdUI);
	afx_msg void OnShapesFrustum();
	afx_msg void OnUpdateShapesFrustum(CCmdUI* pCmdUI);
	afx_msg void OnAffineTranslatefMouse();
	afx_msg void OnUpdateAffineTranslatefMouse(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnAffineRotatefMouse();
	afx_msg void OnUpdateAffineRotatefMouse(CCmdUI* pCmdUI);
	afx_msg void OnLoadtexture();
	afx_msg void OnTextureOfftexture();
	afx_msg void OnProjectionOn();
	afx_msg void OnProjectionOff();
	afx_msg void OnUpdateLoadtexture(CCmdUI* pCmdUI);
	afx_msg void OnUpdateProjectionOn(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTextureOfftexture(CCmdUI* pCmdUI);
	afx_msg void OnAnimationAnimation1();
	afx_msg void OnUpdateAnimationAnimation1(CCmdUI* pCmdUI);
	afx_msg void OnAnimationAnimation2();
	afx_msg void OnUpdateAnimationAnimation2(CCmdUI* pCmdUI);
	afx_msg void OnAnimationAnimation3();
	afx_msg void OnUpdateAnimationAnimation3(CCmdUI* pCmdUI);
	afx_msg void OnLightLightposition();
	afx_msg void OnUpdateLightLightposition(CCmdUI* pCmdUI);
	afx_msg void OnAffineScalefMouse();
	afx_msg void OnUpdateAffineScalefMouse(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // debug version in OpenGL_MFCView.cpp
inline COpenGL_MFCDoc* COpenGL_MFCView::GetDocument() const
   { return reinterpret_cast<COpenGL_MFCDoc*>(m_pDocument); }
#endif
