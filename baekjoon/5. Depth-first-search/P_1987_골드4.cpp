#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1987
// 메모리, 응답시간 : 2024KB, 1644ms

int R, C;
char** map;
bool** visited;
int result = 0;
std::vector<char> abcd;

void DFS(int x, int y, int count) {
	if (count > result)
		result = count;

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int X = dx[i] + x;
		int Y = dy[i] + y;

		if (X < 0 || Y < 0 || X >= R || Y >= C) continue;

		if (visited[X][Y] == false && std::find(abcd.begin(), abcd.end(), map[X][Y]) == abcd.end()) {
			visited[X][Y] = true;
			abcd.push_back(map[X][Y]);
			DFS(X, Y, count + 1);
			abcd.erase(std::remove(abcd.begin(), abcd.end(), map[X][Y]), abcd.end());
			visited[X][Y] = false;
		}
	}
}

int main(void) {	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> R >> C;

	map = new char* [R];
	visited = new bool* [R];

	for (int i = 0; i < R; i++) {
		map[i] = new char[C];
		visited[i] = new bool[C];
		std::fill(visited[i], visited[i] + C, false);

		std::string input;
		std::cin >> input;

		for (int j = 0; j < C; j++)
			map[i][j] = input[j];
	}

	visited[0][0] = true;
	abcd.push_back(map[0][0]);
	DFS(0, 0, 1);

	std::cout << result;

	return 0;
}