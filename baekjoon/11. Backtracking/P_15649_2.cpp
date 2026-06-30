#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/15649
// 메모리 및 시간 : 2020KB, 4ms

int N, M;
char nums[18];
bool visited[9];

void func(int count) {
    if (count == M) {
        std::cout << nums << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            nums[count * 2] = i + '0';
            func(count + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> M;

    for (int i = 0; i < M * 2; i++)
        nums[i] = ' ';

    func(0);

    return 0;
}