#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/9095
// 메모리, 시간 : 2020KB, 0ms

int main(void) {
	int T;
	std::cin >> T;

	while (T--) {
		int n;
		std::cin >> n;

		int* DP = new int[n + 1];

		std::fill(DP, DP + n + 1, 0);
		DP[0] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				if (i - j >= 0)
					DP[i] += DP[i - j];

		std::cout << DP[n] << "\n";
		delete[] DP;
	}

	return 0;
}