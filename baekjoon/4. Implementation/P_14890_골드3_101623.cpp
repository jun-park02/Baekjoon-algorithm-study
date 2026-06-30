#include <iostream>
#include <cmath>

// 문제주소 : https://www.acmicpc.net/problem/14890
// 메모리, 시간 : 2020KB, 4ms

int** map;
int N, L;

int solution(void) {
	int r = 0;
	int c = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		bool flag = false;

		for (int j = 0; j < N - 1; j++) {
			int wtd = map[i][j] - map[i][j + 1];

			if (std::abs(wtd) > 1) {
				flag = true;
				break;
			}

			if (wtd == 0) {
				cnt++;
			}

			// 높이 증가
			if (wtd == -1) {
				if (cnt >= L) {
					cnt = 1;
				}
				else {
					flag = true;
				}
			}

			// 높이 감소
			if (wtd == 1) {
				if (cnt < 0) {
					flag = true;
				}
				else {
					cnt = -1 * (L - 1);
				}
				
			}
		}

		if (!flag && cnt >= 0) r++;
	}

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		bool flag = false;

		for (int j = 0; j < N - 1; j++) {
			int wtd = map[j][i] - map[j + 1][i];

			if (std::abs(wtd) > 1) {
				flag = true;
				break;
			}

			if (wtd == 0) {
				cnt++;
			}

			// 높이 증가
			if (wtd == -1) {
				if (cnt >= L) {
					cnt = 1;
				}
				else {
					flag = true;
				}
			}

			// 높이 감소
			if (wtd == 1) {
				if (cnt < 0) {
					flag = true;
				}
				else {
					cnt = -1 * (L - 1);
				}

			}
		}

		if (!flag && cnt >= 0) c++;
	}
		
	return r + c;
}

int main(void) {
	std::cin >> N >> L;

	map = new int* [N];

	for (int i = 0; i < N; i++) {
		map[i] = new int[N];

		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}

	std::cout << solution();
	return 0;
}