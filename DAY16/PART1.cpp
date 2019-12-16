#include <bits/stdc++.h>

using namespace std;
/*
int myop(int x, int y) {
	return x + 5;
}
*/

int main() {
	string s;
	cin >> s;
	for (int phase = 1; phase <= 100; ++phase) {
		string t = "";
		for (int posDigit = 0; posDigit < s.size(); ++posDigit) {
			/*
			int cycle[100000];
			vector<int> four(100000);
			fill(four.begin(), four.end(), 4);
			partial_sum(four.begin(), four.end(), cycle, myop);
			*/
			vector<int> zeros(posDigit + 1); fill(zeros.begin(), zeros.end(), 0);
			vector<int> ones(posDigit + 1); fill(ones.begin(), ones.end(), 1);
			vector<int> negones(posDigit + 1); fill(negones.begin(), negones.end(), -1);
			vector<int> pattern = ones;
			pattern.insert(pattern.end(), zeros.begin(), zeros.end());
			pattern.insert(pattern.end(), negones.begin(), negones.end());
			pattern.insert(pattern.end(), zeros.begin(), zeros.end());
			int digit = 0;
			for (int i = posDigit; i < s.size(); ++i) {
				digit += (s[i] - '0') * pattern[(i - posDigit) % pattern.size()];
			}
			digit = abs(digit) % 10;
			t += ('0' + digit);
		}
		s = t;
	}
	cout << s.substr(0, 8);
	return 0;
}