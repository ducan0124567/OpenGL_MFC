#pragma once
#include "GL/glut.h"

//Base
GLuint MakeBase();

//Teapot
GLuint MakeSolidTeapot(const double& size);
GLuint MakeWireTeapot(const double& size);

//Torus
GLuint MakeSolidTorus(const float& innerRadius, const float& outerRadius, const int& sides, const int& ring);
GLuint MakeWireTorus(const float& innerRadius, const float& outerRadius, const int& sides, const int& ring);

//Cube
GLuint MakeSolidCube(const float& size);
GLuint MakeLinesCube(const float& size);
GLuint MakePointCube(const float& size);

//Box
GLuint MakeSolidBox(const float& length, const float& width, const float& height);
GLuint MakeLinesBox(const float& length, const float& width, const float& height);
GLuint MakePointBox(const float& length, const float& width, const float& height);

//Sphere
GLuint MakeSolidSphere(const float& radius);
GLuint MakeWireSphere(const float& radius);

//Cylinder
GLuint MakeSolidCylinder(const float& radius, const float& length);

//TruncatedCone
GLuint MakeSolidTruncatedCone(const float& base_rad, const float& top_rad, const float& length);

//Cone
GLuint MakeSolidCone(const float& base_rad, const float& length);

//Pyramid
GLuint MakeSolidPyramid(const float& size, const float& height);
GLuint MakeLinesPyramid(const float& size, const float& height);
GLuint MakePointPyramid(const float& size, const float& height);

//FrustumShape
GLuint MakeSolidFrustumShape(const float& bottom_size, const float& top_size, const float& height);
GLuint MakeLinesFrustumShape(const float& bottom_size, const float& top_size, const float& height);
GLuint MakePointFrustumShape(const float& bottom_size, const float& top_size, const float& height);
