#include <iostream>
#include <queue>

int result = 0;
int N, M;
int** cheese;
bool** visited;
std::queue<std::pair<int, int>> queue;

void melt(void) {
	result++;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			
			if (cheese[i][j] >= 3)
				cheese[i][j] = 0;

			if (cheese[i][j] >= 2 && cheese[i][j] < 3)
				cheese[i][j] = 1;
		}	
}

void BFS(int a, int b) {
	queue.push({ a, b });
	visited[a][b] = true;

	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;
		queue.pop();

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };

		for (int i = 0; i < 4; i++) {
			int X = dx[i] + x;
			int Y = dy[i] + y;

			if (X < 0 || Y < 0 || X >= N || Y >= M) continue;

			if (!visited[X][Y] && cheese[X][Y] == 0) {
				queue.push({ X, Y });
				visited[X][Y] = true;
			}
			
			if (cheese[X][Y] > 0) {
				cheese[X][Y]++;
			}
		}
	}
}

bool done(void) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (cheese[i][j] != 0)
				return false;

	return true;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	cheese = new int* [N];
	visited = new bool* [N];

	for (int i = 0; i < N; i++) {
		cheese[i] = new int[M];
		visited[i] = new bool [M];
		std::fill(visited[i], visited[i] + M, false);
		
		for (int j = 0; j < M; j++) 
			std::cin >> cheese[i][j];
	}

	while (!done()) {
		BFS(0, 0);
		melt();
	}

	std::cout << result;
}