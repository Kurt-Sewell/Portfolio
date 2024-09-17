#include <iostream>
using namespace std;

int Problem3() {

	long long num = 600851475143;
	long long ans = 0;
	bool isPrime = 1;

	for (long long i = 1; i * i <= num / 2; i++) {
		isPrime = 1;
		for (long long j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			
			if (num % i == 0 ) {
				ans = i;
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}