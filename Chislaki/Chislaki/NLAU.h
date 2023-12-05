#pragma once
#include <cmath>
#include "SLAU.h"
vector<double> NLAUsolver(double function1(double x, double y), double function2(double x, double y),
	vector<double> guessPoint, double M, double precision1, double precision2);

vector<double> NLAUsolverALT(double function1(double x, double y), double function2(double x, double y),
	double df1Bydx(double x, double y), double df1Bydy(double x, double y), double df2Bydx(double x, double y), double df2Bydy(double x, double y),
	vector<double> guessPoint, double M, double precision1, double precision2);

vector<double> jacobianRow(double function(double x, double y), vector<double> point, double M);
bool endCondition(double function1(double x, double y), double function2(double x, double y),
	vector<double> answ, vector<double> deltaX, double precision1, double precision2);