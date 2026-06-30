#include <iostream>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/2293
// 메모리, 시간 : 2020KB, 0ms

int main(void) {
	int n, k;
	std::cin >> n >> k;

	int* coin = new int[k + 1];
	int* dp = new int[k + 1];
	std::fill(dp, dp + k + 1, 0);

	for (int i = 1; i <= n; i++)
		std::cin >> coin[i];

	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];

	std::cout << dp[k];

	return 0;
}