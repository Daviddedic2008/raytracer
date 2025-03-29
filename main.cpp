// raytracerFinishedCPU.cpp : Defines the entry point for the application.
//

#include "main.h"
#include "tracer/tracer.h"
#include "tracer/structs/screen.h"
#include <random>

using namespace std;

int main()
{
	int scrW = 512;
	int scrH = 512;
	
	initImg(scrW, scrH);

	writeToImageBuffer(color(1.0f, 0, 0), 10, 10);

	flipBufferToBMP();

	triangle t = triangle(vec3(0.0f, 0.0f, 1.0f), vec3(100.0f, 0.0f, 1.0f), vec3(100.0f, 100.0f, 1.0f), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	ray r = ray(vec3(10.0f, 10.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f));

	printf("%d\n", r.attemptFullTrace(t));
	return 0;
}
