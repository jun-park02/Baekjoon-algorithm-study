#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/9663
// 메모리 및 시간 : 2020KB, 1536ms

int N;
int r = 0;
int col[15];
int diag1[30];
int diag2[30];

void run(int y) {
	if (y == N) {
		r++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (col[i] == 0 && diag1[y + i] == 0 && diag2[y - i + N] == 0) {
			col[i] = 1; 
			diag1[y + i] = 1; 
			diag2[y - i + N] = 1;

			run(y + 1);

			col[i] = 0; 
			diag1[y + i] = 0;
			diag2[y - i + N] = 0;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N;
	run(0);
	std::cout << r;
	return 0;
}