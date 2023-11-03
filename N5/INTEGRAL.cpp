#include "INTEGRAL.h"
using namespace std;

double Integral_Trapezoid(double (*function)(double x, double y), double x0, double xn, 
	                      double precision, int n, double previous_answ) {
	double h = xn - x0;
	double dx = h / n;
	double answ = 0;
	double xi = x0;
	for (int i = 1; i < n; i++) {
		xi += dx;
		answ += function(xi, 0);
	}
	answ *= 2;
	answ += function(x0, 0) + function(xn, 0);
	answ = answ * dx / 2; // final answ

	if (abs(answ - previous_answ) <= 3 * precision) {
		return answ;
	}
	else {
		return Integral_Trapezoid(function, x0, xn, precision, n * 2, answ);
	}
}

double Integral_Simpson(double (*function)(double x, double y), double x0, double xn,
	double y0, double yn, double precision, int n, double previous_answ) {
	double dx = (xn - x0) / n;
	double dy = (yn - y0) / n;
	double answ = 0;
	double xi = x0;
	double yi = y0;
	for (int i = 0; i < n/2; i++) {
		for (int j = 0; j < n/2; j++) {
			answ += function(x0 + 2 * i * dx, y0 + 2 * j * dy);
			answ += 4 * function(x0 + (2 * i + 1) * dx, y0 + (2 * j) * dy);
			answ += 4 * function(x0 + (2 * i) * dx, y0 + (2 * j + 1) * dy);
			answ += 16 * function(x0 + (2 * i + 1) * dx, y0 + (2 * j + 1) * dy);

			answ += function(x0 + (2 * i + 2) * dx, y0 + (2 * j) * dy);
			answ += 4 * function(x0 + (2 * i + 2) * dx, y0 + (2 * j + 1) * dy);

			answ += function(x0 + (2 * i) * dx, y0 + (2 * j + 2) * dy);
			answ += 4 * function(x0 + (2 * i + 1) * dx, y0 + (2 * j + 2) * dy);

			answ += function(x0 + (2 * i + 2) * dx, y0 + (2 * j + 2) * dy);
		}
	}
	answ *= dx * dy / 9;

	if (abs(answ - previous_answ) <= 15 * precision) {
		return answ;
	}
	else {
		return Integral_Simpson(function, x0, xn, y0, yn, precision, n * 2, answ);
	}
}