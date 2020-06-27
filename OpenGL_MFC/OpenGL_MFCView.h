
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
};

#ifndef _DEBUG  // debug version in OpenGL_MFCView.cpp
inline COpenGL_MFCDoc* COpenGL_MFCView::GetDocument() const
   { return reinterpret_cast<COpenGL_MFCDoc*>(m_pDocument); }
#endif
