#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/2667
// 메모리, 응답시간 : 2028KB, 0ms

int N;
std::vector<std::string> map;
std::vector<int> result;
bool** visited;
// 단지 내 집의 수
int num = 0;
// 단지 수
int count = 0;

void DFS(int x, int y) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= N) continue;

		if (map[x + dx[i]][y + dy[i]] == '1' && visited[x + dx[i]][y + dy[i]] == false) {
			visited[x + dx[i]][y + dy[i]] = true;
			num++;
			DFS(x + dx[i], y + dy[i]);
		}
	}
}

int main(void) {
	std::cin >> N;

	visited = new bool* [N];

	for (int i = 0; i < N; i++) {
		bool* arr = new bool[N];
		std::fill(arr, arr + N, false);
		visited[i] = arr;
	}
		
	for (int i = 0; i < N; i++) {
		std::string input;
		std::cin >> input;
		map.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && visited[i][j] == false) {
				count++; num++; visited[i][j] = true;
				DFS(i, j);
				result.push_back(num);
				num = 0;
			}
		}
	}

	std::sort(result.begin(), result.end());

	std::cout << count << "\n";
	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << "\n";

	return 0;
		
}