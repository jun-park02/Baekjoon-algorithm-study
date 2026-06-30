#include <iostream>
#include <queue>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/7576
// 메모리, 응답시간 : 11240KB, 96ms

int N, M;
int** tomato;
bool** visited;
std::queue<std::pair<int, int>> queue;
int max = 0;

void bfs() {
	while (!queue.empty()) {
		int cx = queue.front().first;
		int cy = queue.front().second;
		queue.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int X = cx + dx[i];
			int Y = cy + dy[i];

			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

			if (visited[X][Y] == false && tomato[X][Y] == 0) {
				visited[X][Y] = true;
				queue.push({ X, Y });
				tomato[X][Y] = tomato[cx][cy] + 1;
				max = std::max(max, tomato[X][Y]);
			}
		}
		
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> M >> N;

	tomato = new int* [N];
	visited = new bool* [N];

	bool all_riped = true;

	for (int i = 0; i < N; i++) {
		tomato[i] = new int[M];
		visited[i] = new bool[M];

		for (int j = 0; j < M; j++) {
			std::cin >> tomato[i][j];
			
			visited[i][j] = false;

			if (tomato[i][j] == 0) {
				all_riped = false;
			}

			if (tomato[i][j] == 1) {
				visited[i][j] = true;
				queue.push({ i, j });
			}
		}
	}

	if (all_riped) {
		std::cout << 0;
		return 0;
	}
		
	bfs();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tomato[i][j] == 0) {
				std::cout << -1;
				return 0;
			}

	std::cout << max - 1;
}