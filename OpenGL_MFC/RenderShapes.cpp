#include "RenderShapes.h"
#include <corecrt_math.h>
#include <corecrt_math_defines.h>

//BaseShapes
GLuint MakeBase()
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glDisable(GL_LIGHTING);
	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();

	glScalef(1.0f, 0.005f, 1.0f);
	glutSolidCube(15.0f);

	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEndList();

	return dp_list;
}

//Teapot
GLuint MakeSolidTeapot(const double& size)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutSolidTeapot(size);
	glEndList();

	return dp_list;
}
GLuint MakeWireTeapot(const double& size)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutWireTeapot(size);
	glEndList();

	return dp_list;
}

//Torus
GLuint MakeSolidTorus(const float& innerRadius, const float& outerRadius, const int &sides, const int& ring)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutSolidTorus(innerRadius, outerRadius, sides, ring);
	glEndList();

	return dp_list;
}
GLuint MakeWireTorus(const float& innerRadius, const float& outerRadius, const int& sides, const int& ring)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutWireTorus(innerRadius, outerRadius, sides, ring);
	glEndList();

	return dp_list;
}

//Cube
GLuint MakeSolidCube(const float& size)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glBegin(GL_QUADS);
	// Front Face
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, size, -size);

	glEnd();
	glEndList();
	return dp_list;
}
GLuint MakeLinesCube(const float& size)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	// Front Face
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, size, -size);

	glEnd();
	glEndList();
	return dp_list;
}
GLuint MakePointCube(const float& size)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glPointSize(8);
	glBegin(GL_POINTS);
	// Front Face
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, size, size);
	glVertex3f(-size, size, size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, size, size);
	glVertex3f(-size, size, -size);

	glEnd();
	glEndList();
	return dp_list;
}

//Box
GLuint MakeSolidBox(const float& length, const float& width, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;

	//Back
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(0, y, 0);
	glEnd();

	// left
	glBegin(GL_QUADS);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(0, y, 0);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x, 0, z);
	glEnd();

	//// right
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x, 0, z);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glEnd();

	//Top
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, y, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glVertex3f(0, y, z);

	//Bottom
	glBegin(GL_QUADS);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, z);
	glVertex3f(0, 0, z);

	glEnd();

	glEndList();

	return dp_list;
}
GLuint MakeLinesBox(const float& length, const float& width, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;

	//Back
	glBegin(GL_LINE_LOOP);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(0, y, 0);
	glEnd();

	// left
	glBegin(GL_LINE_LOOP);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(0, y, 0);
	glEnd();

	//front
	glBegin(GL_LINE_LOOP);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x, 0, z);
	glEnd();

	//// right
	glBegin(GL_LINE_LOOP);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x, 0, z);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glEnd();

	//Top
	glBegin(GL_LINE_LOOP);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, y, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glVertex3f(0, y, z);

	//Bottom
	glBegin(GL_LINE_LOOP);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, z);
	glVertex3f(0, 0, z);

	glEnd();

	glEndList();

	return dp_list;
}
GLuint MakePointBox(const float& length, const float& width, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	float x = length;
	float y = height;
	float z = width;
	glPointSize(8);
	//Back
	
	glBegin(GL_POINTS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(0, y, 0);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(0, y, 0);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, z);
	glVertex3f(0, y, z);
	glVertex3f(x, y, z);
	glVertex3f(x, 0, z);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(x, 0, z);
	glVertex3f(x, 0, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, y, 0);
	glVertex3f(x, y, 0);
	glVertex3f(x, y, z);
	glVertex3f(0, y, z);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, z);
	glVertex3f(0, 0, z);

	glEnd();

	glEndList();

	return dp_list;
}

//Sphere
GLuint MakeSolidSphere(const float& radius)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutSolidSphere(radius, 64, 64);
	glEndList();

	return dp_list;
}
GLuint MakeWireSphere(const float& radius)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	glutWireSphere(radius, 64, 64);
	glEndList();

	return dp_list;
}


//Cylinder
GLuint MakeSolidCylinder(const float& radius, const float& length)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj* quadratic_obj;
	quadratic_obj = gluNewQuadric();
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic_obj, radius, radius, length, 32, 32);
	glEndList();
	return dp_list;
}

//TruncatedCone
GLuint MakeSolidTruncatedCone(const float& base_rad, const float& top_rad, const float& length)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj* quadratic_obj;
	quadratic_obj = gluNewQuadric();
	gluCylinder(quadratic_obj, base_rad, top_rad, length, 32, 32);
	glEndList();

	return dp_list;
}

//Cone
GLuint MakeSolidCone(const float& base_rad, const float& length)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj* quadratic_obj;
	quadratic_obj = gluNewQuadric();
	gluCylinder(quadratic_obj, base_rad, 0.0, length, 32, 32);
	glEndList();

	return dp_list;
}

//Pyramid
GLuint MakeSolidPyramid(const float& size, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	double half_size = size * 0.5;
	glBegin(GL_TRIANGLES);
	//Front face
	glNormal3f(0.0, 0.0, 1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, half_size);
	glVertex3f(half_size, 0, half_size);

	//left face
	glNormal3f(-1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);

	//back face
	glNormal3f(0.0, 0.0, -1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, -half_size);
	glVertex3f(half_size, 0, -half_size);

	//Right face
	glNormal3f(1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(half_size, 0.0, half_size);
	glEnd();

	//Bottom face
	glBegin(GL_QUADS);
	glNormal3f(0.0, -1.0, 0.0f);
	glVertex3f(half_size, 0.0, half_size);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);
	glEnd();
	glEndList();

	return dp_list;
}
GLuint MakeLinesPyramid(const float& size, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	double half_size = size * 0.5;
	glBegin(GL_LINE_LOOP);
	//Front face
	glNormal3f(0.0, 0.0, 1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, half_size);
	glVertex3f(half_size, 0, half_size);

	//left face
	glNormal3f(-1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);

	//back face
	glNormal3f(0.0, 0.0, -1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, -half_size);
	glVertex3f(half_size, 0, -half_size);

	//Right face
	glNormal3f(1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(half_size, 0.0, half_size);
	glEnd();

	//Bottom face
	glBegin(GL_LINE_LOOP);
	glNormal3f(0.0, -1.0, 0.0f);
	glVertex3f(half_size, 0.0, half_size);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);
	glEnd();
	glEndList();

	return dp_list;
}
GLuint MakePointPyramid(const float& size, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	double half_size = size * 0.5;
	glPointSize(8);
	glBegin(GL_POINTS);
	//Front face
	glNormal3f(0.0, 0.0, 1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, half_size);
	glVertex3f(half_size, 0, half_size);

	//left face
	glNormal3f(-1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);

	//back face
	glNormal3f(0.0, 0.0, -1.0f);
	glVertex3f(0.0f, height, 0.0f);
	glVertex3f(-half_size, 0, -half_size);
	glVertex3f(half_size, 0, -half_size);

	//Right face
	glNormal3f(1.0, 0.0, 0.0f);
	glVertex3f(0.0, height, 0.0);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(half_size, 0.0, half_size);
	glEnd();

	//Bottom face
	glBegin(GL_POINTS);
	glNormal3f(0.0, -1.0, 0.0f);
	glVertex3f(half_size, 0.0, half_size);
	glVertex3f(half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, -half_size);
	glVertex3f(-half_size, 0.0, half_size);
	glEnd();
	glEndList();

	return dp_list;
}

//FrustumShape
GLuint MakeSolidFrustumShape(const float& bottom_size, const float& top_size, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	double half_bottom_size = 0.5 * bottom_size;
	double half_top_size = 0.5 * top_size;

	glBegin(GL_QUADS);
	// Front Face
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(-half_top_size, height, half_top_size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_top_size, height, -half_top_size);
	glVertex3f(-half_top_size, height, -half_top_size);

	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-half_top_size, height, -half_top_size);
	glVertex3f(-half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, -half_top_size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, -half_top_size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(-half_top_size, height, half_top_size);
	glVertex3f(-half_top_size, height, -half_top_size);
	glEnd();

	glEndList();

	return dp_list;
}
GLuint MakeLinesFrustumShape(const float& bottom_size, const float& top_size, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	double half_bottom_size = 0.5 * bottom_size;
	double half_top_size = 0.5 * top_size;

	glBegin(GL_LINE_LOOP);
	// Front Face
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(-half_top_size, height, half_top_size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_top_size, height, -half_top_size);
	glVertex3f(-half_top_size, height, -half_top_size);

	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-half_top_size, height, -half_top_size);
	glVertex3f(-half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, -half_top_size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, -half_top_size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(-half_top_size, height, half_top_size);
	glVertex3f(-half_top_size, height, -half_top_size);
	glEnd();

	glEndList();

	return dp_list;
}
GLuint MakePointFrustumShape(const float& bottom_size, const float& top_size, const float& height)
{
	GLuint dp_list;
	dp_list = glGenLists(1);
	glNewList(dp_list, GL_COMPILE);
	double half_bottom_size = 0.5 * bottom_size;
	double half_top_size = 0.5 * top_size;
	glPointSize(8);
	glBegin(GL_POINTS);
	// Front Face
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(-half_top_size, height, half_top_size);
	// Back Face
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_top_size, height, -half_top_size);
	glVertex3f(-half_top_size, height, -half_top_size);

	// Top Face
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-half_top_size, height, -half_top_size);
	glVertex3f(-half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, -half_top_size);
	// Bottom Face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	// Right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(half_top_size, height, half_top_size);
	glVertex3f(half_top_size, height, -half_top_size);
	// Left Face
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-half_bottom_size, 0.0, -half_bottom_size);
	glVertex3f(-half_bottom_size, 0.0, half_bottom_size);
	glVertex3f(-half_top_size, height, half_top_size);
	glVertex3f(-half_top_size, height, -half_top_size);
	glEnd();

	glEndList();

	return dp_list;
}
