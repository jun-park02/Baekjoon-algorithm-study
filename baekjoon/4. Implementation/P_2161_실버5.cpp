#include <iostream>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/2161
// 메모리, 응답시간 : 2020KB, 0ms

int main() {
	int N;
	std::cin >> N;

	std::queue<int> cards;

	for (int i = 1; i < N + 1; i++) 
		cards.push(i);

	while (cards.size() != 1) {
		int card = cards.front();
		std::cout << card << " ";
		cards.pop();

		int second_card = cards.front();
		cards.pop();

		cards.push(second_card);
	}

	std::cout << cards.front();
		
	return 0;
}