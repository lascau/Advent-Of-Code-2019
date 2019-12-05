#include <bits/stdc++.h>

using namespace std;

int main() {
	int x;
	long long sum = 0;
	while (cin >> x) {
		sum += floor(x / 3) - 2;
	}
	cout << sum;
	return 0;
}