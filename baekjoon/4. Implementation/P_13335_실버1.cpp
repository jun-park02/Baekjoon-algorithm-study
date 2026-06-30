#include <iostream>
#include <queue>
#include <vector>

// 트럭 순서 변경 x
// 무게는 다를 수 있음
// w대의 트럭만 동시에 올라갈 수 있음
// 단위시간에 하나의 단위길이 만큼만 이동가능
// 트럭들의 무게의 합은 L보다 작거나 같아야함
// 다리위에 완전히 올라가지 않은 트럭은 포함x

// 문제주소 : https://www.acmicpc.net/problem/13335
// 메모리, 응답시간 : 2024KB, 0ms

int main() {
	// 트럭의 수, 다리의 길이, 최대하중
	int n, w, L;
	std::cin >> n >> w >> L;

	std::vector<int> trucks;

	// 트럭 무게 입력
	for (int i = 0; i < n; i++) {
		int truck;
		std::cin >> truck;
		trucks.push_back(truck);
	}
		
	std::queue<int> bridge;

	int time = 0;
	int total_weight = 0;

	for (int i = 0; i < trucks.size(); i++) {
		while (true) {
			// 트럭이 다리에서 내려감
			if (bridge.size() == w) {
				total_weight -= bridge.front();
				bridge.pop();
			}
			// 트럭이 더 올라갈 수 있으면 break
			if (total_weight + trucks[i] <= L)
				break;
			// 트럭이 더 올라갈 수 없으면 현재 트럭을 이동시킴
			else {
				bridge.push(0);
				time++;
			}
		}
		// 트럭이 다리에 올라감
		total_weight += trucks[i];
		bridge.push(trucks[i]);
		time++;
	}

	std::cout << time + w;

	return 0;
}