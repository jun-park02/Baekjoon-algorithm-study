#include <iostream>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1057
// 메모리, 응답시간 : 2020KB, 0ms

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int temp;

	if (A >= B) {
		temp = A;
		A = B;
		B = temp;
	}

	int result = 1;

	while (A + 1 != B || B % 2 == 1) {
		if (A % 2 == 0)
			A /= 2;
		else
			A = (A + 1) / 2;

		if (B % 2 == 0)
			B /= 2;
		else
			B = (B + 1) / 2;
		result++;
	}

	cout << result;

	return 0;
}