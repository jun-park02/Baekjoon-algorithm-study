#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 문제주소 : https://www.acmicpc.net/problem/1339
// 메모리, 시간 : 2212KB, 0ms

int main(void) {
	int N;
	std::cin >> N;

	std::vector<std::pair<char, int>> alphabet;

	for (int i = 0; i < N; i++) {
		std::string input;
		std::cin >> input;
		std::reverse(input.begin(), input.end());

		for (int j = 0; j < input.length(); j++) {
			char current = input[j];

			auto it = std::find_if(alphabet.begin(), alphabet.end(),
				[&current](const auto& element) {
					return element.first == current;
				}
			);

			if (it == alphabet.end()) {
				alphabet.push_back({ current, std::pow(10, j) });
			}
			else {
				int index = it - alphabet.begin();

				alphabet[index].second += std::pow(10, j);
			}
		}
	}

	std::sort(alphabet.begin(), alphabet.end(),
		[](const auto& a, const auto& b) {
			return a.second > b.second;
		}
	);

	int num = 9;
	int result = 0;

	for (int i = 0; i < alphabet.size(); i++) {
		result += alphabet[i].second * num;
		num--;
	}

	std::cout << result;
}