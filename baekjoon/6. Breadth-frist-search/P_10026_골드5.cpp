#include <iostream>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/10026
// 메모리, 응답시간 : 2048KB, 0ms

int N;
bool visited[101][101];
char map[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int result1;
int result2;
char color;

void BFS(int x, int y) {
    color = map[x][y];

    std::queue<std::pair<int, int>> queue;
    queue.push(std::make_pair(x, y));

    while (!queue.empty()) {
        auto p = queue.front();
        queue.pop();

        int cx = p.first;
        int cy = p.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                if (!visited[nx][ny] && map[nx][ny] == color) {
                    visited[nx][ny] = 1;
                    queue.push(std::make_pair(nx, ny));
                }
            }   
        }
             
    }
}

void BFS2(int x, int y) {
    color = map[x][y];

    std::queue<std::pair<int, int>> queue;
    queue.push(std::make_pair(x, y));

    while (!queue.empty()) {
        auto p = queue.front();
        queue.pop();

        int cx = p.first;
        int cy = p.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                if (!visited[nx][ny]) {
                    if ((color == 'R' || color == 'G') && (map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
                        visited[nx][ny] = 1;
                        queue.push(std::make_pair(nx, ny));
                    }
                    else if(color == 'B' && map[nx][ny] == 'B') {
                        visited[nx][ny] = 1;
                        queue.push(std::make_pair(nx, ny));
                    }
                }
            }
        }        
    }
}

int main(void) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::string str; std::cin >> str;
        for (int j = 1; j <= N; j++) {
            map[i][j] = str[j-1];
        }
    }
   
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = 1;
                BFS(i, j);
                result1++;
            }
        }
    }

    std::fill(&visited[0][0], &visited[100][101], 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = 1;
                BFS2(i, j);
                result2++;
            }
        }
    }

    std::cout << result1 << " " << result2;

    return 0;
}