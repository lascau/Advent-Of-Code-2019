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
	for (int noun = 0; noun <= 99; noun++) {
		for (int verb = 0; verb <= 99; verb++) {
			vector<int> vTemp(v);
			vTemp[1] = noun;
			vTemp[2] = verb;
			int i = 0;
			while (vTemp[i] != 99) {
				if (vTemp[i] == 1) {
					vTemp[vTemp[i + 3]] = vTemp[vTemp[i + 2]] + vTemp[vTemp[i + 1]];
				} else {
					vTemp[vTemp[i + 3]] = vTemp[vTemp[i + 2]] * vTemp[vTemp[i + 1]];
				}
				i += 4;
			}
			if (vTemp[0] == 19690720) {
				cout << noun * 100 + verb;
			}
		}
	}
	return 0;
}