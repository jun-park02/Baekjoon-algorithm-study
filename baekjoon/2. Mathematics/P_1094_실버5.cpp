#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1094
// 메모리, 응답시간 : 2024KB, 0ms

int main() {
	int X;
	std::cin >> X;

	std::vector<int> bar;
	bar.push_back(64);

	while (true) {
		int sum = 0;

		// 1. 가지고 있는 막대의 길이를 모두 더한다.
		for (int i = 0; i < bar.size(); i++) {
			sum += bar[i];
		}

		// 2. 합이 X보다 크다면 본문의 과정을 반복한다.
		if (sum > X) {
			// 3. 길이가 가장 짧은 막대를 절반으로 자른다.
			int first = bar.front() / 2;
			bar.erase(bar.begin());
		
			bar.push_back(first);
			bar.push_back(first);
	
			// 4. 위에서 자른 막대의 절반 중 하나를 버리고 남아있는
			//		막대의 길이의 합이 X보다 크다면 절반 중 하나를 버린다.
			int temp = 0;
			for (int i = 0; i < bar.size() - 1; i++) temp += bar[i];

			if (temp >= X) bar.pop_back();

			sort(bar.begin(), bar.end());
		}
		
		if (sum == X) {
			std::cout << bar.size();
			return 0;
		}
	}
}