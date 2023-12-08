#include "SystemToSolve.h"
#define a 1
#define k 2

double drv1(double y1, double y2, double x) {
	return y2 - (a * y1 + k * y2) * y1;
}

double drv2(double y1, double y2, double x) {
	return y
}