#pragma once
#include "GL/glut.h"

//Base
GLuint MakeBase();

//Teapot
GLuint MakeSolidTeapot(const double& size);

//Torus
GLuint MakeSolidTorus(const float& innerRadius, const float& outerRadius, const int& sides, const int& ring);

//Cube
GLuint MakeSolidCube(const float& size);

//Box
GLuint MakeSolidBox(const float& length, const float& width, const float& height);

//Sphere
GLuint MakeSolidSphere(const float& radius);

//Cylinder
GLuint MakeSolidCylinder(const float& radius, const float& length);

//TruncatedCone
GLuint MakeSolidTruncatedCone(const float& base_rad, const float& top_rad, const float& length);

//Cone
GLuint MakeSolidCone(const float& base_rad, const float& length);

//Pyramid
GLuint MakeSolidPyramid(const float& size, const float& height);

//FrustumShape
GLuint MakeSolidFrustumShape(const float& bottom_size, const float& top_size, const float& height);
