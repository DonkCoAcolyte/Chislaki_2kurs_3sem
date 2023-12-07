#include "NLAU.h"

bool endCondition(double function1(double x, double y), double function2(double x, double y),
	vector<double> answ, vector<double> deltaX, double precision1, double precision2) {
	if (abs(function1(answ[0], answ[1])) > precision1) return 0;
	if (abs(function2(answ[0], answ[1])) > precision1) return 0;
	// |fi(X)| <= E1

	for (int i = 0; i < 2; i++) {
		if (answ[i] < 1) {
			if (abs(deltaX[i]) > precision2) return 0;
		}
		else {
			if (abs(deltaX[i]/answ[i]) > precision2) return 0;
		}
	}
	// |deltaX| <= E2; X < 1
	// |deltaX/X| <= E2; X >= 1
	

	return 1;
}

vector<double> jacobianRow(double function(double x, double y), vector<double> point, double M) {
	vector<double> answ(2, 0); 
	double dx = point[0] * M;
	double dy = point[1] * M;

	answ[0] = (function(point[0] + dx, point[1]) - function(point[0], point[1])) / dx;

	answ[1] = (function(point[0], point[1] + dy) - function(point[0], point[1])) / dy;

	return answ;
}

vector<double> NLAUsolver(double function1(double x, double y), double function2(double x, double y),
	vector<double> guessPoint, double M, double precision1, double precision2, unsigned int IterationsToDo) {

	if (!IterationsToDo) throw 2;

	/*double SLAU[3][2];*/
	vector<vector<double>> SLAU = vector<vector<double>>();
	for (int i = 0; i < 2; i++) {
		SLAU.push_back(vector<double>(3, 0));
	}


	SLAU[0][2] = (-1) * function1(guessPoint[0], guessPoint[1]);
	SLAU[1][2] = (-1) * function2(guessPoint[0], guessPoint[1]);
	// found -F(X)

	vector<double> J1 = jacobianRow(function1, guessPoint, M);
	for (int i = 0; i < 2; i++) SLAU[0][i] = J1[i];

	vector<double> J2 = jacobianRow(function2, guessPoint, M);
	for (int i = 0; i < 2; i++) SLAU[1][i] = J2[i];
	// found J(x)

	//J(x) and -F(x) have been combined into a matrix of -f(X) = f'(X)*deltaX;

	vector<double> deltaX(2, 0);
	solveSLAU(SLAU, deltaX);

	vector<double> newPoint(2, 0);
	for (int i = 0; i < 2; i++) {
		newPoint[i] = guessPoint[i] + deltaX[i];
	}

	if (endCondition(function1, function2, newPoint, deltaX, precision1, precision2)) {
		return newPoint;
	}
	else {
		IterationsToDo--;
	    return NLAUsolver(function1, function2, newPoint, M, precision1, precision2, IterationsToDo);
	}

}

vector<double> NLAUsolverALT(double function1(double x, double y), double function2(double x, double y),
	double df1Bydx(double x, double y), double df1Bydy(double x, double y), double df2Bydx(double x, double y), double df2Bydy(double x, double y),
	vector<double> guessPoint, double M, double precision1, double precision2, unsigned int IterationsToDo) {

	if (!IterationsToDo) throw 2;

	/*double SLAU[3][2];*/
	vector<vector<double>> SLAU = vector<vector<double>>();
	for (int i = 0; i < 2; i++) {
		SLAU.push_back(vector<double>(3, 0));
	}


	SLAU[0][2] = (-1) * function1(guessPoint[0], guessPoint[1]);
	SLAU[1][2] = (-1) * function2(guessPoint[0], guessPoint[1]);
	// found -F(X)

	SLAU[0][0] = df1Bydx(guessPoint[0], guessPoint[1]);
	SLAU[0][1] = df1Bydy(guessPoint[0], guessPoint[1]);
	SLAU[1][0] = df2Bydx(guessPoint[0], guessPoint[1]);
	SLAU[1][1] = df2Bydy(guessPoint[0], guessPoint[1]);
	// found J(x)

	//J(x) and -F(x) have been combined into a matrix of -f(X) = f'(X)*deltaX;

	vector<double> deltaX(2, 0);
	solveSLAU(SLAU, deltaX);

	vector<double> newPoint(2, 0);
	for (int i = 0; i < 2; i++) {
		newPoint[i] = guessPoint[i] + deltaX[i];
	}

	if (endCondition(function1, function2, newPoint, deltaX, precision1, precision2)) {
		return newPoint;
	}
	else {
		IterationsToDo--;
		return NLAUsolverALT(function1, function2, df1Bydx, df1Bydy, df2Bydx, df2Bydy, newPoint, M, precision1, precision2, IterationsToDo);
	}

}