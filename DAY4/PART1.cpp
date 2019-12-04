#include <bits/stdc++.h>

using namespace std;

int main() {
	int cnt = 0;
	for (char firstDigit = '2'; firstDigit <= '6'; firstDigit++) {
		for (char secondDigit = firstDigit == '2'? '8' : firstDigit; secondDigit <= '9'; secondDigit++) {
			for (char thirdDigit = secondDigit; thirdDigit <= '9'; thirdDigit++) {
				for (char fourthDigit = thirdDigit; fourthDigit <= '9'; fourthDigit++) {
					for (char fifthDigit = fourthDigit; fifthDigit <= '9'; fifthDigit++) {
						for (char sixthDigit = fifthDigit; sixthDigit <= '9'; sixthDigit++) {
							if (firstDigit == secondDigit || secondDigit == thirdDigit || thirdDigit == fourthDigit || fourthDigit == fifthDigit || fifthDigit == sixthDigit) {
								++cnt;
							}
						}
					}	
				}
			}
		}
	}
	cout << cnt;
	return 0;
}