#pragma once
#include "GL/glut.h"

#define K_MAT_RED            0
#define K_MAT_GREEN       1
#define K_MAT_BLUE          2
#define K_MAT_YELLOW    3
#define K_MAT_PINK          4

void SetMaterialColor(GLfloat ambient[4], GLfloat diff_use[4]);
void SetMaterialColor(const int& type);