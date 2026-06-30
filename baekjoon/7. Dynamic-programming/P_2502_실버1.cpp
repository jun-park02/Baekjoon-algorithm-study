#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/2502
// 메모리, 시간 : 2020KB, 0ms

int main(void) {
	int D, K;
	std::cin >> D >> K;

	long long rice_cake[31][2];

	rice_cake[1][0] = 1;
	rice_cake[1][1] = 0;
	rice_cake[2][0] = 0;
	rice_cake[2][1] = 1;

	for (int i = 3; i <= D; i++) {
		rice_cake[i][0] = rice_cake[i - 1][0] + rice_cake[i - 2][0];
		rice_cake[i][1] = rice_cake[i - 1][1] + rice_cake[i - 2][1];
	}

	int a = 1;
	int b = 1;

	while (true) {
		if (rice_cake[D][0] * a + rice_cake[D][1] * b == K) {
			std::cout << a << "\n" << b;
			return 0;
		}

		b++;

		if (b >= K) {
			a++;
			b = a;
		}
	}

	return 0;
}