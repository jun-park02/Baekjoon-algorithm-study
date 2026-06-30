#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/16174
// 메모리, 응답시간 : 2020KB, 0ms

int N;
int** map;
bool** visited;

int DFS(int x, int y, int move) {
	int dx[] = { x + move, x };
	int dy[] = { y, y + move };

	for (int i = 0; i < 2; i++) {
		if (dx[i] >= N || dy[i] >= N) continue;

		if (map[dx[i]][dy[i]] == -1) return 1;

		if (visited[dx[i]][dy[i]] == false) {
			visited[dx[i]][dy[i]] = true;
			int result = DFS(dx[i], dy[i], map[dx[i]][dy[i]]);

			if (result == 1) return result;
		}
	}
		
	return 0;
}

int main(void) {
	std::cin >> N;

	map = new int* [N];
	visited = new bool* [N];

	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		visited[i] = new bool[N];
		std::fill(visited[i], visited[i] + N, false);

		for (int j = 0; j < N; j++)
			std::cin >> map[i][j];
	}
	
	visited[0][0] = true;
	int result = DFS(0, 0, map[0][0]);

	if (result == 0) std::cout << "Hing";
	if (result == 1) std::cout << "HaruHaru";

	return 0;
}