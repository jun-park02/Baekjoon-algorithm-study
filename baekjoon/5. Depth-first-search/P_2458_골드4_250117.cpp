#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/2458
// 메모리 및 시간 : 3344KB, 44ms

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> graph2;
bool* visited;
int result, count;
int N, M;

void small(int start) {
    for (int i = 0; i < graph2[start].size(); i++) {
        int node = graph2[start][i];

        if (!visited[node]) {
            visited[node] = true;
            count++;
            small(node);
        }
    }
}

void big(int start) {
    for (int i = 0; i < graph[start].size(); i++) {
        int node = graph[start][i];

        if (visited[node] == false) {
            visited[node] = true;
            count++;
            big(node);
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> M;

    graph.assign(N + 1, std::vector<int>());
    graph2.assign(N + 1, std::vector<int>());
    visited = new bool[N + 1];
    std::fill(visited, visited + N + 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;

        // 자신보다 더 큰 사람
        graph[a].push_back(b);
        // 자신보다 더 작은 사람
        graph2[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        count++;
        small(i);
        big(i);

        if (count == N) {
            result++;
        }

        std::fill(visited, visited + N + 1, false);
        count = 0;
    }

    std::cout << result;

    delete[] visited;

    return 0;
}