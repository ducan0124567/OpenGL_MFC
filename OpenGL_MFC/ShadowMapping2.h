#pragma once

#include <windows.h>
#include <stdio.h>
#include "GLee/GLee.h"	//GL header file, including extensions
#include "include/GL/glut.h"
#include "Maths/Maths.h"

class ShadowMapping2
{
private:
protected:

public:
	//Camera & light positions
	VECTOR3D cameraPosition(-2.5f, 3.5f, -2.5f);
	VECTOR3D lightPosition(2.0f, 3.0f, -2.0f);

	//Size of shadow map
	const int shadowMapSize = 512;

	//Textures
	GLuint shadowMapTexture;

	//window size
	int windowWidth, windowHeight;

	//Matrices
	MATRIX4X4 lightProjectionMatrix, lightViewMatrix;
	MATRIX4X4 cameraProjectionMatrix, cameraViewMatrix;
	//Called for initiation
	bool Init(void);

	//Called to draw scene
	void Display(void);

	//Called on window resize
	void Reshape(int w, int h);
	void DrawScene(float angle);
};

