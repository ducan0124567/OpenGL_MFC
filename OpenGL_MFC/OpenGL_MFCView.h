
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
	
	//Base
	GLuint g_Base;

	//Teapot
	GLuint g_SolidTeapot;
	GLuint g_WireTeapot;

	//Torus
	GLuint g_SolidTorus;
	GLuint g_WireTorus;

	//Cube
	GLuint g_SolidCube;
	GLuint g_LinesCube;
	GLuint g_PointCube;

	//box
	GLuint g_SolidBox;
	GLuint g_LinesBox;
	GLuint g_PointBox;

	//Sphere
	GLuint g_SolidSphere;
	GLuint g_WireSphere;

	//Cylinder
	GLuint g_SolidCylinder;

	//TruncatedCone
	GLuint g_SolidTruncatedCone;

	//Cone
	GLuint g_SolidCone;

	//Pyramid
	GLuint g_SolidPyramid;
	GLuint g_LinesPyramid;
	GLuint g_PointPyramid;

	//Frustum
	GLuint g_SolidFrustum;
	GLuint g_LinesFrustum;
	GLuint g_PointFrustum;

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
	//2 - Wire/Line
	//3 - Point
	int SelectRender = 1;


	//Translate
	GLfloat xTr = 0.0f, yTr = 0.0f, zTr = 0.0f;

	// 0 - Off
	// 1 - On
	int SelectTranslate = 0;

	//RotateF
	GLfloat angleRo = 0.0f, xRo = 0.0f, yRo = 0.0f, zRo = 0.0f;

	//gluLookAt
	GLdouble eyeX = 5.0, eyeY = 10.0, eyeZ = 15.0, centerX = 0.0, centerY = 0.0, centerZ = 0.0, upX = 0.0, upY = 1.0, upZ = 0.0;
	void SetupOpenGL();
	void RemoveOpenGL();
	void InitOpenGL(void);
	void DrawCoordinate();
	void Select_Shape_Render();


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
	afx_msg void OnTeapotSolid();
	afx_msg void OnUpdateTeapotSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTeapotWire(CCmdUI* pCmdUI);
	afx_msg void OnTeapotWire();
	afx_msg void OnTorusSolid();
	afx_msg void OnUpdateTorusSolid(CCmdUI* pCmdUI);
	afx_msg void OnTorusWire();
	afx_msg void OnUpdateTorusWire(CCmdUI* pCmdUI);
	afx_msg void OnCubeSolid();
	afx_msg void OnCubeLine();
	afx_msg void OnCubePoint();
	afx_msg void OnBoxSolid();
	afx_msg void OnBoxLines();
	afx_msg void OnBoxPoint();
	afx_msg void OnSphereSolid();
	afx_msg void OnSphereWire();
	afx_msg void OnCylinderSolid();
	afx_msg void OnTruncatedconeSolid();
	afx_msg void OnConeSolid();
	afx_msg void OnPyramidSolid();
	afx_msg void OnPyramidLines();
	afx_msg void OnPyramidPoint();
	afx_msg void OnFrustumSolid();
	afx_msg void OnFrustumLines();
	afx_msg void OnFrustumPoint();
	afx_msg void OnUpdateCubeSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCubeLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCubePoint(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBoxSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBoxLines(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBoxPoint(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSphereSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSphereWire(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCylinderSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTruncatedconeSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateConeSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePyramidSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePyramidLines(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePyramidPoint(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFrustumSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFrustumLines(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFrustumPoint(CCmdUI* pCmdUI);
	afx_msg void OnAffineTranslatef();
	afx_msg void OnUpdateAffineTranslatef(CCmdUI* pCmdUI);
	afx_msg void OnAffineRotatef();
};

#ifndef _DEBUG  // debug version in OpenGL_MFCView.cpp
inline COpenGL_MFCDoc* COpenGL_MFCView::GetDocument() const
   { return reinterpret_cast<COpenGL_MFCDoc*>(m_pDocument); }
#endif
