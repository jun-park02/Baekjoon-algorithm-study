틀린 풀이. 왜 틀렸는지 몰랐는데 물고기를 발견하자마자 잡아먹으면 가장 위쪽 그리고 왼쪽을 우선을 먹는것을 보장할 수 없음.

// #include <iostream>
// #include <vector>
// #include <queue>

// int N;
// int a, b;
// int sharkSize;
// int eatCount;
// int result;
// int count;
// bool flag;
// std::vector<std::vector<int>> board;
// std::vector<std::vector<bool>> visited;
// int dx[] = { -1, 0, 0, 1 };
// int dy[] = { 0, -1, 1, 0 };

// void BFS(int x, int y) {
//     std::queue<std::pair<std::pair<int, int>, int>> queue;
//     queue.push(std::make_pair(std::make_pair(x, y), 1));
//     visited[x][y] = true;
//     flag = false;

//     while (!queue.empty()) {
//         int cx = queue.front().first.first;
//         int cy = queue.front().first.second;
//         int cl = queue.front().second;
//         queue.pop();
        
//         for (int i = 0; i < 4; i++) {
//             int nx = cx + dx[i];
//             int ny = cy + dy[i];

//             if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
//                 if (!visited[nx][ny]) {
//                     if (board[nx][ny] != 0 && board[nx][ny] < sharkSize) {
//                         eatCount++;

//                         if (eatCount == sharkSize) {
//                             sharkSize++;
//                             eatCount = 0;
//                         }
                        
//                         board[nx][ny] = 0;

//                         result += cl;

//                         a = nx;
//                         b = ny;
                        
//                         flag = true;
                        
//                         while(!queue.empty()) {
//                             queue.pop();
//                         }

//                         return;
//                     }
//                     if (sharkSize == board[nx][ny] || board[nx][ny] == 0) {
//                         visited[nx][ny] = true;
//                         queue.push(std::make_pair(std::make_pair(nx, ny), cl + 1));
//                     }
//                 }
//             }
//         }
//     }
// }

// int main(void) {
//     std::cin >> N;

//     board.assign(N, std::vector<int>(N));
//     visited.assign(N, std::vector<bool>(N, false));

//     sharkSize = 2;

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             std::cin >> board[i][j];

//             if (board[i][j] == 9) {
//                 board[i][j] = 0;
//                 a = i;
//                 b = j;
//             }
//         }
//     }

//     flag = true;

//     while (flag) {
//         BFS(a, b);

//         for (int i = 0; i < N; i++) {
//             std::fill(visited[i].begin(), visited[i].end(), false);
//         }
//     }

//     std::cout << result;

//     return 0;
// }