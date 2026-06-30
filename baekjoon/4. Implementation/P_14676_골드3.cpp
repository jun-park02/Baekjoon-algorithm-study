#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/14676
// 메모리, 응답시간 : 6864KB, 176ms

int main() {
	// 건물 종류의 개수, 건물 사이 관계의 수, 게임 정보의 수
	int N, M, K;

	std::cin >> N >> M >> K;

	// 지어진 건물의 수
	int* building = new int[N + 1];
	// 필요한 건물의 수
	int* require = new int[N + 1];
	// 관계
	std::vector<int>* relation = new std::vector<int>[N + 1];
	
	std::fill(building, building + N + 1, 0);
	std::fill(require, require + N + 1, 0);

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		
		if (a == b)
			continue;

		relation[a].push_back(b);
		require[b]++;
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		std::cin >> a >> b;

		// 건설
		if (a == 1) {
			if (require[b] > 0) {
				std::cout << "Lier!";
				return 0;
			}
			else {
				if (building[b] == 0)
					for (int j = 0; j < relation[b].size(); j++)
						require[relation[b][j]]--;
				building[b]++;
			}
		}

		// 파괴
		if (a == 2) {
			if (building[b] < 1) {
				std::cout << "Lier!";
				return 0;
			}
			else {
				if (building[b] == 1) 
					for (int j = 0; j < relation[b].size(); j++)
						require[relation[b][j]]++;
				building[b]--;
			}
		}
	}

	std::cout << "King-God-Emperor";

	return 0;
}