#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/10026
// 메모리, 응답시간 : 2060KB, 0ms

int N;
std::vector<std::vector<char>> board;
std::vector<std::vector<bool>> visited;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int row, int col) {
	char color = board[row][col];
	visited[row][col] = 1;

	for (int i = 0; i < 4; i++) {
		int nRow = row + dx[i];
		int nCol = col + dy[i];

		if (nRow >= 0 && nRow < N && nCol >= 0 && nCol < N) {
			if (!visited[nRow][nCol] && color == board[nRow][nCol]) {
				dfs(nRow, nCol);
			}
		}
	}

	if (board[row][col] == 'G') {
		board[row][col] = 'R';
	}
}

int getCount() {
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				count++;
				dfs(i, j);
			}
		}
	}

	return count;
}

int main(void) {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string str;
		std::cin >> str;

		std::vector<char> temp;
		std::vector<bool> temp2;

		for (int j = 0; j < N; j++) {
			temp.push_back(str[j]);
			temp2.push_back(false);
		}

		board.push_back(temp);
		visited.push_back(temp2);
		temp.clear();
		temp2.clear();
	}

	int result = getCount();

	for (int i = 0; i < N; i++) {
		std::fill(visited[i].begin(), visited[i].end(), false);
	}

	int result2 = getCount();

	std::cout << result << " " << result2;

	return 0;
}