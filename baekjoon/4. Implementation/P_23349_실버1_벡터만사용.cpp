#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/23349
// 메모리, 응답시간 : 3996KB, 0ms

int main() {
	int N;
	std::cin >> N;

	// 이름 저장
	std::vector<std::string> names;
	// place마다 하나의 int형 배열
	std::vector<std::pair<std::string, int*>> places;

	for (int i = 0; i < N; i++) {
		std::string name, place;
		int start, end;

		std::cin >> name >> place >> start >> end;

		// 처음 제출하는 이름일 경우
		if (std::find(names.begin(), names.end(), name) == names.end()) {
			names.push_back(name);

			// 처음 제출된 장소일 경우
			if (std::find_if(places.begin(), places.end(), 
					[&place](const auto& element) 
					{
						return element.first == place;
					}) == places.end()
				) {
				// int arr[50001]; 이렇게 하면 안됨
				int* arr = new int[50001];
				std::fill(arr, arr + 50001, 0);

				for (int j = start; j < end; j++)
					arr[j]++;

				places.push_back(std::make_pair(place, arr));
			}
			// 이미 제출된 장소일 경우
			else {
				int index = std::find_if(places.begin(), places.end(),
					[&place](const auto& element)
					{
						return element.first.compare(place) == 0;
					}
				) - places.begin();

				int* arr_ptr = places[index].second;

				for (int j = start; j < end; j++)
					(*(arr_ptr + j))++;
			}
		}
		// 이미 제출한 적이 있는 이름일 경우 무시
	}

	// 사전순으로 place들을 정렬
	std::sort(places.begin(), places.end());

	int max = 0;
	int max_start = 0;
	int max_end = 0;
	std::string max_name = "";

	for (int i = 0; i < places.size(); i++) {
		int* max_in_places = std::max_element(places[i].second, places[i].second + 50001);

		if (*max_in_places > max) {
			max_name = places[i].first;
			max = *max_in_places;
			max_start = max_in_places - places[i].second;
			
			for (int j = max_start + 1; true; j++) {
				if (j == 50001 || places[i].second[j] != max) {
					max_end = j;
					break;
				}
			}
		}
	}

	std::cout << max_name << " ";
	std::cout << max_start << " ";
	std::cout << max_end << " ";

	return 0;
}