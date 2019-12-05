#include <bits/stdc++.h>

using namespace std;

int main() {
	int x;
	long long sum = 0;
	while (cin >> x) {
		int temp = floor(x / 3) - 2;
		
		while (temp > 0) {
			sum += temp;
			temp = floor(temp / 3) - 2;
		}
	}
	cout << sum;
	return 0;
}