#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/1058
// 메모리 및 시간 : 2024KB, 0ms

int** friendYN;

int main(void) {
	int N; std::cin >> N;

	friendYN = new int* [N];

	for (int i = 0; i < N; i++) {
		friendYN[i] = new int[N];

		std::string input;
		std::cin >> input;

		for (int j = 0; j < N; j++) {
			if (input[j] == 'Y')
				friendYN[i][j] = 1;

			if (input[j] == 'N')
				friendYN[i][j] = 0;
		}
	}
		
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i != j && friendYN[i][j] == 0)
					if (friendYN[i][k] == 1 && friendYN[k][j] == 1)
						friendYN[i][j] = 2;

	int max = 0;

	for (int i = 0; i < N; i++) {
		int count = 0;

		for (int j = 0; j < N; j++)
			if (friendYN[i][j] == 1 || friendYN[i][j] == 2)
				count++;

		if (count > max)
			max = count;
	}
		
	std::cout << max;

	return 0;
}