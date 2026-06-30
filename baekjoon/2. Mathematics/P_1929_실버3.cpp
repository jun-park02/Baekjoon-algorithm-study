#include <iostream>
#include <cmath>

int main(void) {
	int M, N;
	std::cin >> M >> N;

	for (int i = M; i <= N; i++) {
		int j = 2;
		bool prime_number = true;

		while (j <= sqrt(i)) {
			if (i % j == 0) {
				prime_number = false;
				break;
			}
			j++;
		}

		if (prime_number && i > 1)
			std::cout << i << "\n";
	}

	return 0;
}