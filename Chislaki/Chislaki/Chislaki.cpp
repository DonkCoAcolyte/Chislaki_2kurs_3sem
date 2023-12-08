#include <iostream>
#include "SDU1order.h"
#include "SystemToSolve.h"

#define EpsDefault 1.e-3

using namespace std;

int main()
{
	vector<double> yStart;
	yStart.push_back(1);
	yStart.push_back(0);

	vector<vector<double>> points;
	EulerExplicit(points, drv1, drv2, yStart, 0, 1, EpsDefault);
	unsigned int pointQuantity = points.size();
	for (int i = 0; i < pointQuantity; i++) {
		cout << "y1 = " << points[i][0] << "; y2 = " << points[i][1] << "; x = " << points[i][2] << endl;
	}
} 