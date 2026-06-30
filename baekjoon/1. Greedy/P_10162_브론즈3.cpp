#include <iostream>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/10162
// 메모리, 응답시간 : 2020KB, 0ms

int main() {
	int T;
	cin >> T;

	int count[3] = {0,0,0};

	do {
		count[0] += (T / 300);
		T = T % 300;
		count[1] += (T / 60);
		T = T % 60;
		count[2] += (T / 10);
		T = T % 10;
		
		if (T != 0 && T < 10) {
			cout << "-1";
			return 0;
		}

	} while (T != 0);

	cout << count[0] << " ";
	cout << count[1] << " ";
	cout << count[2] << " ";

	return 0;
}