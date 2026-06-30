#include <iostream>
#include <vector>
#include <queue>
#include <limits>

std::vector<int>* nodes;
int* result;
std::priority_queue<int> pq;

void Dikstra(int start) {
	result[start] = 0;
	pq.push(start);

	while (!pq.empty()) {
		int current_node = pq.top();
		pq.pop();

		for (int i = 0; i < nodes[current_node].size(); i++) {
			int next_node = nodes[current_node][i];

			if (result[next_node] > result[current_node] + 1) {
				result[next_node] = result[current_node] + 1;
				pq.push(next_node);
			}
		}
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, K, X;
	std::cin >> N >> M >> K >> X;
	nodes = new std::vector<int>[N + 1];
	result = new int[N + 1];
	std::fill(result, result + N + 1, std::numeric_limits<int>::max());

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;

		nodes[a].push_back(b);
	}

	Dikstra(X);

	bool flag = false;

	for (int i = 1; i < N + 1; i++)
		if (result[i] == K) {
			std::cout << i << "\n";
			flag = true;
		}
	
	if (!flag) {
		std::cout << "-1";
	}

	return 0;
}