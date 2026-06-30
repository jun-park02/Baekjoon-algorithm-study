#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/1405
// 메모리, 응답시간 : 2024KB, 28ms

int N;
double probability[4];
bool visited[42][42];

double dfs(int x, int y, int count) {
	if (count == N) return 1;

	visited[x][y] = true;

	double result = 0;

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if (visited[X][Y] == false)
			result += (probability[i] * dfs(X, Y, count + 1));
	}

	visited[x][y] = false;

	return result;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	
	for (int i = 0; i < 4; i++) {
		std::cin >> probability[i];
		probability[i] /= 100;
	}

	double result = 0;

	result = dfs(20, 20, 0);

	std::cout.precision(10);
	std::cout << std::fixed << result;

	return 0;
}