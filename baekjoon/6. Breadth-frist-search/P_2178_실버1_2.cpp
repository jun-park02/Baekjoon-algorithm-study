#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/2178
// 메모리, 응답시간 : 2072KB, 0ms

int N, M;
int map[100][100] = { 0, };
std::queue<std::pair<int, int>> queue;
bool visited[100][100] = { false, };

void bfs(int n, int m) {
	visited[0][0] = true;
	queue.push(std::make_pair(0, 0));

	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];

			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

			if (visited[X][Y] == false && map[X][Y] != 0) {
				visited[X][Y] = true;
				queue.push(std::make_pair(X, Y));
				map[X][Y] += map[x][y];
			}
		}
	}
}

int main(void) {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf_s("%1d", &map[i][j]);

	bfs(N, M);
	std::cout << map[N - 1][M - 1];

	return 0;
}