#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/16206
// 메모리, 응답시간 : 2080KB, 0ms

int main() {
    int N, M;
    cin >> N;
    cin >> M;

    cin.ignore();

    string str;
    getline(cin, str);

    stringstream sstream(str);
    vector<int> cake_length;
    string num;

    while (getline(sstream, num, ' '))
    {
        cake_length.push_back(stoi(num));
    }

    sort(cake_length.begin(), cake_length.end());

    int result = 0;
    int cut = 0;
    bool flag = false;

    for (int i = 0; i < cake_length.size(); i++) {
        int current = cake_length[i];

        if (current % 10 == 0) {
            while (true) {
                if (current == 10) {
                    result++;
                    break;
                }

                if (cut < M) {
                    cut++;
                    result++;
                    current -= 10;
                }
                else {
                    flag = true;
                    break;
                }
                    
                
                if (current < 10) break;
            }
        }

        if (flag == true)
            break;
    }
    
    flag = false;

    for (int i = 0; i < cake_length.size(); i++) {
        int current = cake_length[i];

        if (current % 10 != 0) {
            while (true) {
                if (current < 10) break;

                if (cut < M) {
                    cut++;
                    result++;
                    current -= 10;
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true)
            break;
    }

    cout << result;

    return 0;
}