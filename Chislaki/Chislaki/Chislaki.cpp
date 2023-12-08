#include "functions.h"
#include "NLAU.h"

namespace MethodConfig {
	constexpr int kEps = 1.e-9;
	constexpr int kEpsIt = 1.e-9;
	constexpr int kIterationOverheadCount = 1000;
};

int main()
{
	bool choice;
	cout << "use pre-set derivatives?";
	cin >> choice;
	vector<double> solution;
	if (choice) {
		solution = NLAUsolverALT(f1, f2, df1Bydx, df1Bydy, df2Bydx, df2Bydy, vector<double>(2, 1), 0.01, 1.e-9, 1.e-9);
	}
	else {
	 solution = NLAUsolver(f1, f2, vector<double>(2, 1), 0.01, MethodConfig::kEps, 1.e-9);
	}
		cout << "solution: ";
		for (int i = 0; i < 2; i++) {
			cout << solution[i] << "; ";
		}
}