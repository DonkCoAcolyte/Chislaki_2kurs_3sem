#include "SDU1order.h"
#define dxMax 0.1
#define dxMin 1.e-3
double EulerExplicit_dxSolver(double& precision,
	double& y1AbsMax, double& y2AbsMax,
	double& drvY1, double& drvY2) {
	double dx1;
	double dx2;

	try {
		dx1 = precision * y1AbsMax / abs(drvY1);
	}
	catch (...) {
		dx1 = dxMax;
	}

	try {
		dx2 = precision * y2AbsMax / abs(drvY2);
	}
	catch (...) {
		dx2 = dxMax;
	}

	double dx = min(dx1, dx2);
	if (dx < dxMin) dx = dxMin;
	if (dx > dxMax) dx = dxMax;

	return dx;
}

void EulerExplicit(vector<vector<double>>& answerContainer,
	               double drv1(double y1, double y2, double x), double drv2(double y1, double y2, double x),
	               vector<double> YiStart, double x0, double xn, double precision,
	               double y1AbsMax, double y2AbsMax) {

	if (abs(YiStart[0]) > y1AbsMax) y1AbsMax = abs(YiStart[0]);
	if (abs(YiStart[1]) > y2AbsMax) y2AbsMax = abs(YiStart[1]);
	// found yiMax
	if (y1AbsMax == 0) y1AbsMax = precision;
	if (y2AbsMax == 0) y2AbsMax = precision;

	double drvY1 = drv1(YiStart[0], YiStart[1], x0);
	double drvY2 = drv2(YiStart[0], YiStart[1], x0);
	// found y1', y2'

	double dx = EulerExplicit_dxSolver(precision, y1AbsMax, y2AbsMax, drvY1, drvY2);

	vector<double> YiNext;
	YiNext.push_back(YiStart[0] + dx * drvY1);
	YiNext.push_back(YiStart[1] + dx * drvY2);
	x0 += dx;
	//found y1,y2,x k+1

	vector<double> NewPoint(YiNext);
	NewPoint.push_back(x0);
	answerContainer.push_back(NewPoint);
	//put the found point in answerContainer;

	if (x0 < xn) EulerExplicit(answerContainer, drv1, drv2, YiNext, x0, xn, precision, y1AbsMax, y2AbsMax);
}

void EulerImplicit(vector<vector<double>>& answerContainer, 
	               double drv1(double y1, double y2, double x), double drv2(double y1, double y2, double x),
	               vector<double> YiStart, double x0, double xn, double precision,
                   double y1AbsMax, double y2AbsMax) {

}
