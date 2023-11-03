#pragma once
#include <iostream>


double Integral_Trapezoid(double (*function)(double x), double x0, double xn,
	double precision = 1e-4, int n = 4, double previous_answ = 999999);

double Integral_Simpsonx(double (*function)(double x), double x0, double xn,
	double precision = 1e-4, int n = 4, double previous_answ = 999999);

double Integral_Simpsonxy(double (*function)(double x, double y), double x0, double xn,
	double y0 = 0, double yn = 1, double precision = 1e-4, int n = 4, double previous_answ = 999999);