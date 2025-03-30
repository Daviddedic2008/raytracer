// raytracerFinishedCPU.cpp : Defines the entry point for the application.
//

#include "main.h"
#include "src/render.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
	int scrW = 10;
	int scrH = 10;

	Camera c = Camera(vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f), 0.0f, 0.0f);

	RenderParameters params = RenderParameters(10, 10, 4, 10);

	addTriangle(triangle(vec3(0, 0, 1), vec3(100, 0, 1), vec3(100, 100, 1), 1, 0, 0, 1, 0));

	Bitmap b = render(triangles, c, params);

	for (int x = 0; x < scrW; x++) {
		for (int y = 0; y < scrH; y++) {
			printf("%f ", b.colors[x + y * scrW].r);
		}
		printf("\n");
	}

	return 0;
}
