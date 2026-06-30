#include <iostream>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1149
// 메모리, 시간 : 2032KB, 0ms

int color[1001][3];

int main() {
	int N;
	std::cin >> N;

	color[0][0] = 0;
	color[0][1] = 0;
	color[0][2] = 0;

	for (int i = 1; i <= N; i++) {
		int r, g, b;

		std::cin >> r >> g >> b;

		color[i][0] = std::min(color[i - 1][1], color[i - 1][2]) + r;
		color[i][1] = std::min(color[i - 1][0], color[i - 1][2]) + g;
		color[i][2] = std::min(color[i - 1][0], color[i - 1][1]) + b;
	}

	int min = std::min(color[N][2], std::min(color[N][0], color[N][1]));

	std::cout << min;
}