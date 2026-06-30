#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/4716
// 메모리, 응답시간 : 2300KB, 16ms

class Team {
public:
	// 달아줘야 하는 풍선의 수
	int K;
	// a로 부터 떨어진 거리
	int distance_a;
	// b로 부터 떨어진 거리
	int distance_b;
	// a - b
	int interval;

	Team() {};

	Team(int a, int b, int c) {
		K = a;
		distance_a = b;
		distance_b = c;
		interval = b - c;
	}

	bool operator < (Team& team) {
		return abs(this->interval) > abs(team.interval);
	}
};

int main() {
	vector<int> vec;

	while (true) {
		// 1 <= 팀의 수 <= 1000
		int N;
		// 0 <= A방의 풍선 개수 <= 10,000
		int balloon_a;
		// 0 <= B방의 풍선 개수 <= 10,000
		int balloon_b;

		cin >> N >> balloon_a >> balloon_b;

		if (N == 0 && balloon_a == 0 && balloon_b == 0)
			break;

		Team* teams = new Team[N];

		for (int i = 0; i < N; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			teams[i] = Team(a, b, c);
		}

		sort(teams, teams + N);

		int result = 0;
		for (int i = 0; i < N; i++) {
			while (teams[i].K > 0) {
				if (teams[i].distance_a <= teams[i].distance_b && balloon_a > 0) {
					result += teams[i].distance_a;
					teams[i].K--;
					balloon_a--;
					continue;
				}
				if (teams[i].distance_b <= teams[i].distance_a && balloon_b > 0) {
					result += teams[i].distance_b;
					teams[i].K--;
					balloon_b--;
					continue;
				}
				if (balloon_a == 0) {
					result += teams[i].distance_b;
					teams[i].K--;
					balloon_b--;
					continue;
				}
				if (balloon_b == 0) {
					result += teams[i].distance_a;
					teams[i].K--;
					balloon_a--;
					continue;
				}
			}
		}

		vec.push_back(result);
	}

	for (int i = 0; i < vec.size(); i++)
		cout << vec.at(i) << "\n";
}