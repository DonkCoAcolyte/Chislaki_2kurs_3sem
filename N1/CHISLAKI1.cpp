#include"Header.h"

int main()
{
	unsigned int n; // srtrok
	unsigned int r; // stolbcov ne schitaya svobodnyie chleny

	cout << "n = ?" << endl;
	cin >> n;
	if (!n) {
		cout << "RETARD n != 0";
		return 0;
	}
	cout << endl;

	cout << "r = ?" << endl;
	cin >> r;
	if (!r) {
		cout << "RETARD r != 0";
		return 0;
	}
	cout << endl;

	vector<vector<double>> table = vector<vector<double>>();
	for (unsigned int i = 0; i < n; i++) {
		table.push_back(vector<double>(r + 1, 0));
	}
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < r + 1; j++) {
			cout << "input " << i + 1 << " " << j + 1 << endl;
			cin >> table[i][j];
		}
	}

	ForwardRunGauss(table);

	vector<double> solution(r, 0);

	ReverseRunGauss(table, solution);

	for (unsigned int i = 0; i < r; i++) {
		cout << "answ " << i << " " << solution[i] << endl;
	}

	double deltamax = 0;
	for (int i = 0; i < r; i++) {
		double deltacurr = table[i][r];

		for (int j = 0; j < r; j++) {
			deltacurr -= table[i][j] * solution[j];
		}

		cout << "deltacurr " << i << " = " << deltacurr << endl;
		if (abs(deltamax) < abs(deltacurr)) {
			deltamax = deltacurr;
		}
	}
	cout << "deltamax = " << deltamax;
}
