#include <iostream>
using namespace std;

int Problem2() {
	int sum = 2;

	int i = 1;
	int j = 2;
	int num = 3;

	while (num < 4000000) {
		i = j;
		j = num;
		num = i + j;

		if (num % 2 == 0) { sum += num; }
	}

	cout << sum << endl;

	return 0;
}