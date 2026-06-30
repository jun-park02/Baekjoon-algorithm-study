#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/1260
// 메모리, 응답시간 : 2300KB, 0ms

std::vector<int>* graph;
std::stack<int> stack;
std::queue<int> queue;
char* visited;

void dfs(int v) {
    stack.push(v);
    visited[v] = true;
    std::cout << v << " ";

    while(!stack.empty()) {
        int cur = stack.top();
        bool found = false;

        for (int next : graph[cur]) {
            if (!visited[next]) {
                stack.push(next);
                visited[next] = true;
                std::cout << next << " ";
                found = true;
                break;
            }
        }

        if (!found) {
            stack.pop();
        }
    }

    std::cout << std::endl;
}

void bfs(int v) {
    queue.push(v);
    visited[v] = true;

    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        std::cout << cur << " ";

        for (int next : graph[cur]) {
            if (!visited[next]) {
                queue.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    // 정점, 간선, 시작 노드
    int N, M, V;
    std::cin >> N >> M >> V;

    graph = new std::vector<int>[N + 1];
    visited = new char[N + 1];

    std::fill(visited, visited + N + 1, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < N + 1; i++) {
        std::sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    std::fill(visited, visited + N + 1, false);
    bfs(V);

    delete[] graph;
    delete[] visited;

    return 0;
}