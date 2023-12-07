#include "SLAU.h"

void ForwardRunGauss(vector<vector<double>>& table) { // DOESNT ACCOUNT FOR r < n;
	unsigned int n = table.size(); // stroki
	unsigned int r = table[0].size() - 1; //stolbci bez svobodnogo chlena

	if (n < r) {
		throw invalid_argument("beskonechnost' resheniy (esli ne r-n nulevih stolbcov, ya ne budu eto proveryat)");
	}

	if (r < n) {
		throw invalid_argument("razmernost' ne nxn (oops!)");
	}

	for (unsigned int jmin = 0; jmin < r; jmin++) {
		unsigned int imin = jmin;

		double AMAX = 0;
		unsigned int IMAX;

		for (unsigned int ee = jmin; ee < r; ee++) { // finding out which row has the element with the largest module within this column;
			if (abs(table[ee][jmin]) > abs(AMAX)) {
				AMAX = table[ee][jmin];
				IMAX = ee;
			}
		}

		if (AMAX == 0) throw invalid_argument("beskonechnost' resheniy ili net resheniy (AMAX = 0)"); // if a column consists entirely of 0;

		for (int jswap = jmin; jswap < (r + 1); jswap++) { // swapped the first row with the row found earlier;
			double a = table[imin][jswap];
			table[imin][jswap] = table[IMAX][jswap];
			table[IMAX][jswap] = a;
		}

		for (int j1 = jmin; j1 < (r + 1); j1++) {
			table[imin][j1] /= AMAX;
		} // divided the "first" row by the "first" element;
		for (unsigned int i2 = imin + 1; i2 < r; i2++) {
			double A2 = table[i2][jmin];
			for (unsigned int j2 = jmin; j2 < r + 1; j2++) {
				table[i2][j2] -= A2 * table[imin][j2];
			}
		} // subtracted the "first" row from all later rows, multiplied by the first element of each later row;


	}
}

void ReverseRunGauss(vector<vector<double>>& table, vector<double>& solution) {
	unsigned int n = table.size();
	unsigned int r = table[0].size() - 1;

	for (int imin = r - 1; imin > -1; imin--) {
		int jmin = imin;
		solution[jmin] = table[imin][r]; // q

		for (int j = jmin + 1; j < r; j++) {
			solution[jmin] -= table[imin][j] * solution[j]; //xj = q - an*xn - ...;
		}
	}
	solution;
}

void solveSLAU(vector<vector<double>>& table, vector<double>& solution) {
	ForwardRunGauss(table);
	ReverseRunGauss(table, solution);

}