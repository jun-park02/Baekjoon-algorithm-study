#include <iostream>
#include <string>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1439
// 메모리, 응답시간 : 2024KB, 0ms

int main() {
    string S;
    cin >> S;

    int count[2] = { 0, 0 };
    int pre = (int)(S.at(0) - '0');

    count[pre]++;

    for (int i = 1; i < S.length(); i++) {
        int current = (int)(S.at(i) - '0');
        pre = (int)(S.at(i - 1) - '0');

        if (current == pre) {
            continue;
        }
        else {
            count[current]++;
        }
    }

    if (count[0] <= count[1])
        cout << count[0];
    else
        cout << count[1];

    return 0;
}