#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/2748
// 메모리, 시간 : 2020KB, 0ms

int main(void) {
    int N;
    long long int dp[100] = { 0, };
    dp[1] = 1; dp[2] = 1;
    std::cin >> N;

    for (int i = 3; i < N + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << dp[N];
    return 0;
}