#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/11726
// 메모리, 응답시간 : 2020KB, 0ms


int main(void) {
    int N; std::cin >> N;

    int* dp;
    dp = new int[N + 1];

    std::fill(dp, dp + N + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    std::cout << dp[N];

    return 0;
}