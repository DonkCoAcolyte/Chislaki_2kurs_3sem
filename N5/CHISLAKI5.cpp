#include "Header.h"

using namespace std;

double function_dud(double x, double y) {
	return 1;
}

double function1(double x, double y) {
	double answ = pow((1 + x*x*x), 1 / 2);
	return answ;
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
	if (!precision) { precision = 1e-4; }

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

		cout << "Simpson = " << Integral_Simpson(function_dud, x0, xn, y0, yn) << endl;
	}
	else {
		cout << "Trapezoid = " << Integral_Trapezoid(function_dud, x0, xn) << endl;
		cout << "Simpson = " << Integral_Simpson(function_dud, x0, xn) << endl;
	}
}