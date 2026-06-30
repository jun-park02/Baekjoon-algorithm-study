#include <iostream>

int main(void) {
	int N; std::cin >> N;

	int cnt = 0;

	while (N > 0) {
		if (N >= 5 && N % 5 == 0) {
			std::cout << N / 5 + cnt;
			return 0;
		}

		N -= 3;
		cnt++;
	}

	N == 0 ? std::cout << cnt : std::cout << -1;

	return 0;
}