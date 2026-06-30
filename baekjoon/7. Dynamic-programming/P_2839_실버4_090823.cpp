#include <iostream>
#include <algorithm>

int main(void) {
	int N;
	std::cin >> N;

	int sugar[5001];
	std::fill(sugar, sugar + 5001, 99999999);

	sugar[3] = 1;
	sugar[5] = 1;

	for (int i = 6; i <= N; i++) 
		sugar[i] = std::min(sugar[i - 3] + 1, sugar[i - 5] + 1);
	
	sugar[N] >= 99999999 ? std::cout << -1 : std::cout << sugar[N];
	
	return 0;
}