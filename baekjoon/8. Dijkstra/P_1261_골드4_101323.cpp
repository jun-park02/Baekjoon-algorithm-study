#include <iostream>
#include <queue>
#include <limits>

// 문제주소 : https://www.acmicpc.net/problem/1261
// 메모리 및 시간 : 2024KB, 4ms

int** map;
int** dp;
std::queue<std::pair<int, int>> q;
int N, M;

void dijkstra() {
	q.push({ 0, 0 });
	dp[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];

			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

			if (map[X][Y] == '1') {
				if (dp[X][Y] > dp[x][y] + 1) {
					dp[X][Y] = dp[x][y] + 1;
					q.push({ X, Y });
				}
			}

			if (map[X][Y] == '0') {
				if (dp[X][Y] > dp[x][y]) {
					dp[X][Y] = dp[x][y];
					q.push({ X, Y });
				}
			}
		}
	}
}

int main(void) {
	std::cin >> M >> N;

	map = new int* [N];
	dp = new int* [N];

	for (int i = 0; i < N; i++) {
		std::string str;
		std::cin >> str;

		map[i] = new int[M];
		dp[i] = new int[M];
		std::fill(dp[i], dp[i] + M, std::numeric_limits<int>::max());
	
		for (int j = 0; j < M; j++)
			map[i][j] = str[j];
	}

	dijkstra();

	std::cout << dp[N - 1][M - 1];
	
	return 0;
}