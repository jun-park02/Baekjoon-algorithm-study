#include <iostream>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1049
// 메모리, 응답시간 : 2020KB | 0ms

int main() {
	// 끊어진 기타줄의 수
	int N;
	cin >> N;

	// 브랜드의 수
	int M;
	cin >> M;

	int M_arr[50][2];

	// 0번 인덱스 : 패키지 최소값
	// 1번 인덱스 : 개별 최소값
	int min[2];

	cin >> M_arr[0][0];
	cin >> M_arr[0][1];

	min[0] = M_arr[0][0];
	min[1] = M_arr[0][1];

	for (int i = 1; i < M; i++) {
		cin >> M_arr[i][0];
		cin >> M_arr[i][1];

		if (M_arr[i][0] <= min[0]) 
			min[0] = M_arr[i][0];

		if (M_arr[i][1] <= min[1])
			min[1] = M_arr[i][1];
	}

	int total = 0;

	if (min[0] < min[1] * 6) {
		total += ((N / 6) * min[0]);
		N = N % 6;

		int A = min[0];
		int B = min[1] * N;

		if (A <= B) {
			total += A;
		}
		else {
			total += B;
		}
	}
	else {
		total += (min[1] * N);
	}

	cout << total;

	return 0;
}