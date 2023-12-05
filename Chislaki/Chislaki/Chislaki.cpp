#include "functions.h"
#include "NLAU.h"

int main()
{
	vector<double> solution = NLAUsolver(f1, f2, vector<double>(2, 1), 0.01, 1.e-9, 1.e-9);
	cout << "solution: ";
	for (int i = 0; i < 2; i++) {
		cout << solution[i] << "; ";
	}
}