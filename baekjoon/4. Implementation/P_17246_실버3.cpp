#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/17264
// 메모리, 응답시간 : 2024KB, 12ms

int main() {
	// 총 게임 횟수
	int N;
	// 해킹을 통해 얻은 플레이어 정보 수 P
	int P;

	std::cin >> N >> P;

	// 이긴 경우 획득 점수
	int W;
	// 진 경우 손실 점수
	int L;
	// 벗어나기 위한 점수
	int G;

	std::cin >> W >> L >> G;

	std::string* str_arr = new std::string[P];
	char* WL_arr = new char[P];

	// 플레이어 정보 입력
	for (int i = 0; i < P; i++) {
		std::cin >> str_arr[i] >> WL_arr[i];
	}
	
	int score = 0;

	for (int i = 0; i < N; i++) {
		std::string temp;
		std::cin >> temp;

		char WL = ' ';

		for (int i = 0; i < P; i++) 
			if (str_arr[i].compare(temp) == 0) {
				WL = WL_arr[i];
				break;
			}
				
		if (WL == 'W') score += W;
		if (WL == 'L' || WL == ' ') score -= L;

		if (score < 0)
			score = 0;

		if (score >= G) {
			std::cout << "I AM NOT IRONMAN!!";
			return 0;
		}
	}

	std::cout << "I AM IRONMAN!!";

	return 0;
}