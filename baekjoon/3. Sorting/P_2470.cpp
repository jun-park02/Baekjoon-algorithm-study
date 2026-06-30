#include <iostream>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/2470
// 메모리, 응답시간 : 2412KB, 68ms

int main() {
	// 2 <= N <= 100,000
	int N;
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int left = 0;
	int right = N-1;
	int min = 2147483647;

	int a = 0;
	int b = 0;

	while (left < right) {
		int sum = arr[left] + arr[right];

		if (abs(sum) <= abs(min)) {
			min = sum;
			a = arr[left];
			b = arr[right];
		}

		if (abs(arr[left]) > abs(arr[right]))
			left++;
		else
			right--;
	}

	cout << a << " " << b;

	return 0;
}