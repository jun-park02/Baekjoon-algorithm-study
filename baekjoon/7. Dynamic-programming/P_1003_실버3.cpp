#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/1003
// 메모리, 시간: 2020KB, 4ms

int dp[41][2];

int main(void) {
	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;

		dp[0][0] = 1;
		dp[0][1] = 0;

		dp[1][0] = 0;
		dp[1][1] = 1;

		for (int i = 2; i <= N; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		}

		std::cout << dp[N][0] << " " << dp[N][1] << "\n";
	}

	return 0;
}