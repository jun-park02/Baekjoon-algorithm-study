#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소: https://www.acmicpc.net/problem/11725
// 메모리, 응답시간 : 16316KB, 120ms

std::vector<std::pair<int, int>> result;

void DFS(std::vector<int> graph[], bool visited[], int start) {
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		int current = graph[start][i];

		if (!visited[current]) {
			visited[current] = true;
			result.push_back(std::make_pair(current, start));
			DFS(graph, visited, current);
		}
	}
}

int main(void) {
	int N;
	std::cin >> N;

	std::vector<int>* graph = new std::vector<int>[N + 1];
	bool* visited = new bool[N + 1];
	std::fill(visited, visited + N + 1, false);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		std::cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(graph, visited, 1);

	std::sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		std::cout << result[i].second << "\n";

	return 0;
}