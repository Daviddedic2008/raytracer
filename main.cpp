// raytracerFinishedCPU.cpp : Defines the entry point for the application.
//

#include "main.h"
#include "src/render.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
	int scrW = 180;
	int scrH = 180;

	Camera c = Camera(vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), 0.0f, 0.0f);

	RenderParameters params = RenderParameters(scrW, scrH, 4, 10);

	// Base of the pyramid (4 triangles forming a square pyramid)
	addTriangle(triangle(vec3(0, 0, 1), vec3(100, 0, 1), vec3(50, 50, 100), 1, 0, 0, 1, 1)); // Front face
	addTriangle(triangle(vec3(100, 0, 1), vec3(100, 100, 1), vec3(50, 50, 100), 1, 0, 0, 1, 1)); // Right face
	addTriangle(triangle(vec3(100, 100, 1), vec3(0, 100, 1), vec3(50, 50, 100), 1, 0, 0, 1, 1)); // Back face
	addTriangle(triangle(vec3(0, 100, 1), vec3(0, 0, 1), vec3(50, 50, 100), 1, 0, 0, 1, 1)); // Left face

	// Light-emitting triangle above the pyramid
	//addTriangle(triangle(vec3(25, 25, 150), vec3(75, 25, 150), vec3(50, 75, 150), 1, 1, 1, 1, 0)); // White light triangle

	Bitmap b = render(triangles, c, params);

	flipBufferToBMP();

	return 0;
}
