#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
	vector<int> v;
	string input;
	cin >> input;
    istringstream iss(input);
    string number;
    while (std::getline(iss, number, ','))
    {
        v.push_back(stoi(number));
    }
	int i = 0;
	while (v[i] != 99) {
		if (v[i] == 1) {
			v[v[i + 3]] = v[v[i + 2]] + v[v[i + 1]];
		} else {
			v[v[i + 3]] = v[v[i + 2]] * v[v[i + 1]];
		}
		i += 4;
	}
	for (int val: v) {
		cout << val << ' ';
	}
	return 0;
}