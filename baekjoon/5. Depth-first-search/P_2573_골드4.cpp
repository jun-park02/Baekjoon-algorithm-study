#include <iostream>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/2573
// 메모리, 응답시간 : 3436KB, 104ms

int N, M;
int** map;
int** melt_map;
bool** visited;
int count = 0;
int year = 0;

void init() {
	count = 0;

	for (int i = 0; i < N; i++) {
		std::fill(melt_map[i], melt_map[i] + M, 0);
		std::fill(visited[i], visited[i] + M, false);
	}
}

int melt(int x, int y) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	int count = 0;

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if (map[X][Y] == 0)
			count++;
	}

	return count;
}

void dfs(int x, int y) {
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, 1, -1 };

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

		if (visited[X][Y] == false && map[X][Y] != 0) {
			visited[X][Y] = true;
			dfs(X, Y);
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	map = new int* [N];
	melt_map = new int* [N];
	visited = new bool* [N];

	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		melt_map[i] = new int[M];
		visited[i] = new bool[M];

		for (int j = 0; j < M; j++)
			std::cin >> map[i][j];
	}

	// 두 덩어리가 될때까지 반복
	while (true) {
		// melt_map, visited, count 설정
		init(); 

		year++;

		// 빙산이 다 녹은 경우 false
		bool flag = false;

		// 1년 후 얼마나 녹을 것인지 계산
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] != 0) {
					flag = true;
					melt_map[i][j] = melt(i, j);
				}

		// 녹이기
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] != 0)
					map[i][j] = std::max(map[i][j] - melt_map[i][j], 0);

		// dfs (빙산 개수 세기)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] != 0 && visited[i][j] == false) {
					visited[i][j] = true;
					count++;
					dfs(i, j);
				}
		
		// 빙산의 개수가 2개 이상인 경우 종료
		if (count >= 2)
			break;

		// 빙산이 다 녹은 경우 0 출력
		if (flag == false) {
			std::cout << "0";
			return 0;
		}
	}

	std::cout << year;

	return 0;
}