#include <iostream>
using namespace std;

int Problem4() {

	int ans[6] = {};
	int i = 999;
	int j = 999;
	int prod;
	bool Palindrome;


	
	for (i; i > 0; i--) {
		for (j; j > 0; j--) {
			prod = i * j;

			for (int k = 0; k < 6; k++) {
				 ans[k] = prod % 10;
				prod /= 10;
			}
			Palindrome = 1;
			
			for (int k = 0; k < 3; k++) {
				if (ans[k] != ans[5 - k]) {
					Palindrome = 0;
					break;
				}
			}
			if (Palindrome) { 
				for (int k = 0; k < 6; k++) {
					cout << ans[k];
				}
				//exit;
			}
		}
	}
	
	return 0;
}