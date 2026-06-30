#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1260
// 메모리, 응답시간 : 2156KB, 4ms

int N, M, V;
std::vector<int>* graph;
bool visited[1001] = { false, };
std::queue<int> queue;

void dfs(int x) {
	visited[x] = true;
	std::cout << x << " ";

	for (int i = 0; i < (graph + x)->size(); i++) {
		int current = graph[x][i];

		if (!visited[current])
			dfs(current);
	}
}

void bfs(int x) {
	queue.push(x);
	visited[x] = true;

	while (!queue.empty()) {
		int current = queue.front();
		queue.pop();
		std::cout << current << " ";

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];

			if (!visited[next]) {
				queue.push(next);
				visited[next] = true;
			}
		}
	}
}

int main(void) {
	std::cin >> N >> M >> V;

	graph = new std::vector<int>[N + 1];

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N + 1; i++)
		std::sort(graph[i].begin(), graph[i].end());

	dfs(V);

	std::cout << "\n";
	std::fill(visited, visited + 1001, false);

	bfs(V);

	return 0;
}