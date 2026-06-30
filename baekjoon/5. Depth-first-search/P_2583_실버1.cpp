#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/2583
// 메모리, 응답시간 : 2528KB, 0ms

int territory = 0;
int area = 0;
int M, N, K;
int** map;
bool** visited;
std::vector<int> result;

void DFS(int y, int x) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

		if (map[Y][X] == 0 && visited[Y][X] == false) {
			area++; visited[Y][X] = true;
			DFS(Y, X);
		}
	}
}

int main(void) {
	std::cin >> M >> N >> K;

	map = new int* [M];
	visited = new bool* [M];

	for (int i = 0; i < M; i++) {
		map[i] = new int[N];
		std::fill(map[i], map[i] + N, 0);
		visited[i] = new bool[N];
		std::fill(visited[i], visited[i] + N, false);
	}
		
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
			for (int k = x1; k < x2; k++)
				map[j][k] = 1;
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 0 && visited[i][j] == false) {
				territory++; area++; visited[i][j] = true;
				DFS(i, j);
				result.push_back(area);
				area = 0;
			}

	std::sort(result.begin(), result.end());

	std::cout << territory << "\n";
	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";

	return 0;
}