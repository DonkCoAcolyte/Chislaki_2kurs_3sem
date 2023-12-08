#pragma once
#include <iostream>
#include <vector>

using namespace std;

void EulerExplicit(vector<vector<double>>& answerContainer, 
	               double drv1(double y1, double y2, double x), double drv2(double y1, double y2, double x),
	               vector<double> YiStart,double x0,double xn,double precision,
	               double y1AbsMax = 0, double y2AbsMax = 0);

void EulerImplicit(vector<vector<double>>& answerContainer, 
	               double drv1(double y1, double y2, double x), double drv2(double y1, double y2, double x),
	               vector<double> YiStart, double x0, double xn, double precision,
	               double y1AbsMax = 0, double y2AbsMax = 0);
