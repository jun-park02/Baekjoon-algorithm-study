#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/23349
// 메모리, 응답시간 : 3992KB, 16ms

int main() {
	int N;
	std::cin >> N;

	std::vector<std::string> names;
	std::map<std::string, int*> hashmap;

	for (int i = 0; i < N; i++) {
		std::string name, place;
		int start, end;
		std::cin >> name >> place >> start >> end;
		
		// 처음 입력일 경우
		if (find(names.begin(), names.end(), name) == names.end()) {
			// 해시맵에 키 값이 없는 경우
			if (hashmap.find(place) == hashmap.end()) {
				int* arr = new int[50001];
				std::fill(arr, arr + 50001, 0);

				for (int i = start; i < end; i++) arr[i]++;

				hashmap.insert(std::make_pair(place, arr));
			}
			// 키 값이 있는 경우
			else {
				for (int i = start; i < end; i++)
					hashmap[place][i]++;
			}

			names.push_back(name);
		}
		// 처음 입력이 아닐 경우
		else {
			continue;
		}
	}

	int max = 0;
	int max_start = 0;
	int max_end = 0;
	std::string max_name = "";

	for (const auto& item : hashmap) {
		int temp = *std::max_element(item.second, item.second + 50001);

		if (max < temp) {
			max = temp;
			max_name = item.first;
			max_start = std::max_element(item.second, item.second + 50001) - item.second;

			for (int i = max_start + 1; true; i++) {
				if (item.second[i] != max || i == 50000) {
					max_end = i;
					break;
				}
			}
		}
	}

	std::cout << max_name << " " << max_start << " " << max_end;

	return 0;
}