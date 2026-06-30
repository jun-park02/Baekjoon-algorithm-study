#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/13699
// 메모리, 응답시간 : 2020KB, 0ms

long long dp[36] = { 0, };

int main(void) {
	int n;
	std::cin >> n;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 0; j < i; j++)
			dp[i] += (dp[j] * dp[i - j - 1]);

	std::cout << dp[n];

	return 0;
}