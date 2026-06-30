#include <iostream>
#include <vector>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/18352
// 메모리 및 시간 : 22020KB, 352ms

int N, M, K, X;
std::vector<int>* nodes;
std::queue<int> q;
bool* visited;
int* result;

void bfs(int start) {
	result[start] = 0;
	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < nodes[node].size(); i++) {
			int next_node = nodes[node][i];
			
			if (visited[next_node]) continue;
			
			result[next_node] = result[node] + 1;
		
			q.push(next_node);
			visited[next_node] = true;
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> K >> X;
	nodes = new std::vector<int>[N + 1];
	visited = new bool[N + 1];
	result = new int[N + 1];
	std::fill(visited, visited + N + 1, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;

		nodes[a].push_back(b);
	}

	bfs(X);

	bool flag = true;

	for (int i = 1; i < N + 1; i++) {
		if (result[i] == K) {
			std::cout << i << "\n";
			flag = false;
		}
	}
			
	if (flag) std::cout << "-1";

	return 0;
}