#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/2178
// 메모리, 응답시간 : 2040KB, 0ms

int N, M;
std::vector<std::string> map;
std::queue<std::pair<std::pair<int, int>, int>> queue;
bool visited[100][100] = { false, };

void bfs(int n, int m) {
	visited[0][0] = true;
	queue.push(std::make_pair(std::make_pair(0, 0), 1));

	while (!queue.empty()) {
		int current_x = queue.front().first.first;
		int current_y = queue.front().first.second;
		int count = queue.front().second;
		queue.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int X = current_x + dx[i];
			int Y = current_y + dy[i];

			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

			if (X == N - 1 && Y == M - 1) {
				std::cout << count + 1;
				return;
			}
				
			if (visited[X][Y] == false && map[X][Y] == '1') {
				visited[X][Y] = true;
				queue.push(std::make_pair(std::make_pair(X, Y), count + 1));
			}
		}
	}
}

int main(void) {
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string input;
		std::cin >> input;

		map.push_back(input);
	}

	bfs(N, M);

	return 0;
}