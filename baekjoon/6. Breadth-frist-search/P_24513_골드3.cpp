#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/24513
// 메모리, 시간 : 8840KB, 228ms

int N, M;
int** town;
bool** visited;
std::queue<std::pair<int, int>> queue;
std::vector<std::pair<int, int>> vector;

void bfs() {
	while (true) {
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

				if (visited[X][Y] == false && town[X][Y] != -1 && town[X][Y] != 3 && town[X][Y] != town[cx][cy]) {
					town[X][Y] += town[cx][cy];

					if (town[X][Y] != 3)
						vector.push_back({ X, Y });
				}
			}
		}

		if (vector.size() == 0) break;

		for (int i = 0; i < vector.size(); i++) {
			int cx = vector[i].first;
			int cy = vector[i].second;

			visited[cx][cy] = true;

			if (town[cx][cy] != 3)
				queue.push({ cx, cy });
		}

		vector.clear();
	}
	
}

int main(void) {
	std::cin >> N >> M;

	town = new int* [N];
	visited = new bool* [N];

	for (int i = 0; i < N; i++) {
		town[i] = new int[M];
		visited[i] = new bool[M];

		std::fill(visited[i], visited[i] + M, false);

		for (int j = 0; j < M; j++) {
			std::cin >> town[i][j];

			if (town[i][j] == 1 || town[i][j] == 2) {
				visited[i][j] = true;
				queue.push({ i, j });
			}
		}
	}
		
	bfs();

	int count[4] = { 0, };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (town[i][j] == 1)
				count[1]++;

			if (town[i][j] == 2)
				count[2]++;

			if (town[i][j] == 3)
				count[3]++;
		}
		
	for (int i = 1; i <= 3; i++)
		std::cout << count[i] << " ";

	return 0;
}