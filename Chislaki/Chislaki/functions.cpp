#include "functions.h"

double f1(double x, double y) {
	return sin(x + 1) - y - 1;
	//return x - y;
}


double df1Bydx(double x, double y) {
	return cos(x + 1);
}
double df1Bydy(double x, double y) {
	return -1;
}

//------------------------------------

double f2(double x, double y) {
	return 2 * x + cos(y) - 2;
	/*return 2*x - y;*/
}


double df2Bydx(double x, double y) {
	return 2;
}
double df2Bydy(double x, double y) {
	return -sin(y);
}