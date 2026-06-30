#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/1753
// 메모리, 시간 : 9188KB, 96ms

int V, E;
std::vector<std::pair<int, int>>* nodes;
std::priority_queue<std::pair<int, int>> pq;
int* cost;

void dijkstra(int start) {
	pq.push({ 0, start });
	cost[start] = 0;

	while (!pq.empty()) {
		int current_cost = pq.top().first * (-1);
		int current_node = pq.top().second;
		pq.pop();

		if (cost[current_node] < current_cost) continue;

		for (int i = 0; i < nodes[current_node].size(); i++) {
			int after_cost = nodes[current_node][i].second;
			int through = after_cost + current_cost;

			if (through < cost[nodes[current_node][i].first]) {
				cost[nodes[current_node][i].first] = through;
				pq.push({ through * (-1), nodes[current_node][i].first });
			}
		}

	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> V >> E;

	int start;
	std::cin >> start;

	nodes = new std::vector<std::pair<int, int>>[V + 1];
	cost = new int[V + 1];

	std::fill(cost, cost + V + 1, std::numeric_limits<int>::max());

	for (int i = 0; i < E; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;

		nodes[u].push_back({ v, w });
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (cost[i] == std::numeric_limits<int>::max())
			std::cout << "INF" << "\n";
		else
			std::cout << cost[i] << "\n";
	}

	return 0;
}