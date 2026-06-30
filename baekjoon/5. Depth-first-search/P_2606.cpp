#include <iostream>
#include <vector>
#include <stack>

// 문제주소 : https://www.acmicpc.net/problem/2606
// 메모리, 응답시간 : 2020KB | 0ms

std::vector<int>* graph;
bool* visited;
int result;

void DFS(int start) {
	visited[start] = true;
	result++;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main(void) {
	// 컴퓨터의 수, 간선의 수
	int n, m;
	std::cin >> n >> m;

	graph = new std::vector<int>[n + 1];
	visited = new bool[n + 1];
	result = 0;

	std::fill(visited, visited + n + 1, false);

	for (int i = 0; i < m; i++) {
		int c1, c2;

		std::cin >> c1 >> c2;

		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}

	DFS(1);

	std::cout << result - 1;

	delete[] graph;
	delete[] visited;

	return 0;
}