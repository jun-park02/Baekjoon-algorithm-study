#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/1463
// 메모리, 응답시간 : 5928KB, 4ms

int main(void) {
    int N;
    std::cin >> N;

    int* dp;
    dp = new int[N + 1];

    std::fill(dp, dp + N + 1, 0);

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        }

        if (i % 3 == 0) {
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
        }
    }

    std::cout << dp[N] << "\n";

    return 0;
}