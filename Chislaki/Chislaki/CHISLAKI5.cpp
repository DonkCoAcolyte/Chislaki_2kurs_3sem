#include "INTEGRAL.h"

using namespace std;

#define PRECISION_DEFAULT 1e-4

double function10x(double x) {
	return 0.1*x*x/(log10(x));
}

double function32xy(double x, double y) {
	return 4 - x*x - y*y;
}
int main() {

	double x0;
	cout << "x0 = ";
	cin >> x0;
	cout << endl;

	double xn;
	cout << "xn = ";
	cin >> xn;
	cout << endl;

	double precision;
	cout << "precision(if 0 then assume the default 10^[-4]) = ";
	cin >> precision;
	cout << endl;

	if (precision < 0) {
		cout << "Error: precision < 0";
		return 0;
	}

	if (!precision) { precision = PRECISION_DEFAULT; }

	bool choice;
	cout << "0 - f(x); 1 - f(x,y)" << endl;
	cout << "choice = ";
	cin >> choice;
	if (choice) {
		double y0;
		cout << "y0 = ";
		cin >> y0;
		cout << endl;

		double yn;
		cout << "yn = ";
		cin >> yn;
		cout << endl;

		cout << "Simpson = " << Integral_Simpsonxy(function32xy, x0, xn, y0, yn) << endl;
	}
	else {
		if (1 >= x0 && 1 <= xn) {
			cout << "1 is part of [x0;xn], cannot find (...)/lg1 (division by zero)." << endl;
			return 1;
		}
		cout << "Trapezoid = " << Integral_Trapezoid(function10x, x0, xn) << endl;
		cout << "Simpson = " << Integral_Simpsonx(function10x, x0, xn) << endl;
	}
}
