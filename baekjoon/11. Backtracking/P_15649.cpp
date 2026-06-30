#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/15649
// 메모리 및 시간 : 2020KB, 24ms

int N, M;
int number[9];

void func(int cnt, std::vector<int> vec) {
	if (cnt == M) {
		 for (int i = 0; i < vec.size(); i++) {
		 	std::cout << vec[i] << " ";
		 }
		 std::cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (number[i] == 0) {
			vec.push_back(i);
			number[i] = 1;
			func(cnt + 1, vec);
			number[i] = 0;
			vec.pop_back();
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N >> M;

	int cnt = 0;
	std::vector<int> vec;
	func(cnt, vec);

	return 0;
}