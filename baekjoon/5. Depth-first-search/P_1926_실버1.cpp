#include <iostream>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1926
// 메모리, 응답시간 : 18708KB, 60ms

int** map;
bool** visited;
int max_area = 0;
int area = 0;
int count = 0;
int n, m;

void DFS(int x, int y) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if (X < 0 || Y < 0 || X >= n || Y >= m) continue;

		if (visited[X][Y] == false && map[X][Y] == 1) {
			visited[X][Y] = true;
			area++;
			DFS(X, Y);
		}
	}
}

int main(void) {
	std::cin >> n >> m;

	map = new int* [n];
	visited = new bool* [n];

	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
		visited[i] = new bool[m];
		std::fill(visited[i], visited[i] + m, false);

		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j] == false && map[i][j] == 1) {
				visited[i][j] = true;
				count++; area++;
				DFS(i, j);
				if (area > max_area) 
					max_area = area;
				area = 0;
			}
				
	std::cout << count << "\n" << max_area;

	return 0;
}