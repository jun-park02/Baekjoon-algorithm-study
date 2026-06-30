#include <iostream>
#include <algorithm>
#include <vector>

// 문제주소: https://www.acmicpc.net/problem/16724
// 메모리, 응답시간 : 4104KB, 28ms

int N, M;
char** map;
bool** visited;
int safe_count = 0;

void DFS(int x, int y) {
	int dx = x;
	int dy = y;

	switch (map[x][y]) {
	case 'U': dx += -1; dy += 0; break;
	case 'D': dx += 1; dy += 0; break;
	case 'L': dx += 0; dy += -1; break;
	case 'R': dx += 0; dy += 1; break;
	}

	if (map[dx][dy] == 'S' && visited[dx][dy] != true) {
		return;
	}

	if (visited[dx][dy] == true) {
		safe_count++;
		map[x][y] = 'S';
	}
	else {
		visited[dx][dy] = true;
		map[x][y] = 'S';
		DFS(dx, dy);
		visited[dx][dy] = false;
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	map = new char* [N];
	visited = new bool* [N];

	for (int i = 0; i < N; i++) {
		map[i] = new char[M];
		visited[i] = new bool[M];

		std::fill(visited[i], visited[i] + M, false);

		std::string input;
		std::cin >> input;

		for (int j = 0; j < M; j++)
			map[i][j] = input[j];
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] != 'S') {
				visited[i][j] = true;
				DFS(i, j);
				visited[i][j] = false;
			}

	std::cout << safe_count;

	return 0;
}
