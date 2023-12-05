#pragma once
#include <iostream>
#include <vector>

using namespace std;

void ForwardRunGauss(vector<vector<double>>& table);
void ReverseRunGauss(vector<vector<double>>& table, vector<double>& solution);

void solveSLAU(vector<vector<double>>& table, vector<double>& solution);