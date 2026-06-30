#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1865
// 메모리 및 시간 : 2332KB, 20ms

std::vector<std::pair<std::pair<int, int>, int>> graph;
int INF = std::numeric_limits<int>::max();

void bellmanFord(int n, int m,int start, bool* flag) {
	long long* dist = new long long[n + 1];
	std::fill(dist, dist + n + 1, INF);
	dist[start] = 0;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int from = graph[j].first.first;
			int to = graph[j].first.second;
			int cost = graph[j].second;

			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}
		
	for (int j = 0; j < graph.size(); j++) {
		int from = graph[j].first.first;
		int to = graph[j].first.second;
		int cost = graph[j].second;

		if (dist[to] > dist[from] + cost) 
			*flag = true;
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int TC; std::cin >> TC;

	while (TC--) {
		int N, M, W; std::cin >> N >> M >> W;

		for (int i = 0; i < M; i++) {
			int S, E, T; std::cin >> S >> E >> T;

			graph.push_back({ {S, E}, T });
			graph.push_back({ {E, S}, T });
		}

		for (int i = 0; i < W; i++) {
			int S, E, T; std::cin >> S >> E >> T;

			graph.push_back({ {S, E}, (- 1) * T});
 		}

		bool flag = false;

		bellmanFord(N, M, 1, &flag);

		if (flag) 
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
		
		graph.clear();
	}

	return 0;
}