#include "pch.h"
#include "MaterialColor.h"



void SetMaterialColor(GLfloat ambient[4], GLfloat diff_use[4])
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}

void SetMaterialColor(const int& type)
{
    GLfloat ambien[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat diff_use[] = { 0.0, 0.0, 0.0, 1.0 };
    switch (type)
    {
    case K_MAT_RED:
    {
        ambien[0] = 1.0f;
        diff_use[0] = 1.0f;
    }
    break;
    case K_MAT_GREEN:
    {
        ambien[1] = 1.0f;
        diff_use[1] = 1.0f;
    }
    break;
    case K_MAT_BLUE:
    {
        ambien[2] = 1.0f;
        diff_use[2] = 1.0f;
    }
    break;
    case K_MAT_YELLOW:
    {
        ambien[0] = 1.0f;
        ambien[1] = 1.0f;
        diff_use[0] = 1.0f;
        diff_use[1] = 1.0f;
    }
    break;
    case K_MAT_PINK:
    {
        ambien[0] = 1.0f;
        ambien[2] = 1.0f;
        diff_use[0] = 1.0f;
        diff_use[1] = 1.0f;
    }
    break;
    default:
    {
        ambien[0] = 1.0f;
        ambien[1] = 1.0f;
        ambien[2] = 1.0f;
        diff_use[0] = 1.0f;
        diff_use[1] = 1.0f;
        diff_use[2] = 1.0f;
    }
    break;
    }

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambien);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}