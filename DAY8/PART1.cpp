#include <bits/stdc++.h>

using namespace std;

const int wide = 25;
const int tall = 6;

int main() {
	vector<pair<int, int>> layers;
	int count = 0;
	char in;
	int zeros = 0;
	int ones = 0;
	int twos = 0;
	int min0s = 1e9;
	int minPos = -1;
	bool Started = 0;
	int no_layers = -1;
	
	while (cin >> in) {
		Started = 1;
		if (in == '0') {
			++zeros;
		}
		if (in == '1') {
			++ones;
		}
		if(in == '2') {
			++twos;
		}
		if (count == wide * tall - 1) {
			++no_layers;
			if (zeros < min0s){
				min0s = zeros;
				minPos = no_layers;
			}
			if (Started) {
				layers.push_back({ones, twos});
			}
			zeros = 0; 
			ones = 0; 
			twos = 0;
		}
		count = (count + 1) % (wide * tall);
	}
	cout << layers[minPos].first * layers[minPos].second;
	return 0;
}