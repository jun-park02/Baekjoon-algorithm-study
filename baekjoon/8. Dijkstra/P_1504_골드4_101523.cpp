#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// 문제주소 : https://www.acmicpc.net/problem/1504
// 메모리 및 시간 : 5728KB, 44ms

std::vector<std::pair<int, int>>* nodes;
std::priority_queue<std::pair<int, int>> pq;
long long int* dp;
int INF = std::numeric_limits<int>::max();
int N, E;

void dijkstra(int start, int end) {
	for (int i = 0; i < N + 1; i++)
		dp[i] = INF;

	pq.push({ 0, start });
	dp[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first * -1;
		int node = pq.top().second;
		pq.pop();

		if (dp[node] < cost) continue;

		for (int i = 0; i < nodes[node].size(); i++) {
			int next_node = nodes[node][i].first;
			int next_cost = nodes[node][i].second;
			int after = cost + next_cost;

			if (after < dp[next_node]) {
				dp[next_node] = after;
				pq.push({ -1 * after, next_node });
			}
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> E;
	nodes = new std::vector<std::pair<int, int>>[N + 1];
	dp = new long long int[N + 1];

	for (int i = 0; i < E; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		nodes[a].push_back({ b , c });
		nodes[b].push_back({ a, c });
	}

	int v1, v2;
	std::cin >> v1 >> v2;


	int a, b, c, d, e;

	dijkstra(1, v1);
	a = dp[v1];

	dijkstra(v1, v2);
	b = dp[v2];
	
	dijkstra(v2, N);
	c = dp[N];

	dijkstra(1, v2);
	d = dp[v2];

	dijkstra(v1, N);
	e = dp[N];

	if (a >= INF || b >= INF || c >= INF || d >= INF || e >= INF) {
		std::cout << -1;
		return 0;
	}
		
	a + b + c < d + b + e ? 
	std::cout << a + b + c << "\n" : 
	std::cout << d + b + e << "\n";

	return 0;
}