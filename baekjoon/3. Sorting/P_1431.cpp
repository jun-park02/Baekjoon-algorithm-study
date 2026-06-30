#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/1431
// 메모리, 응답시간 : 2032KB, 4ms

// 시리얼 번호 A-Z, 0-9
// 1. 길이가 다르면 짧은 것이 먼저
// 2. 길이가 같다면, 자리수의 합을 구해서 작은 것이 먼저(숫자만 더함)
// 3. 1번 2번으로 비교 x 이면, 사전순으로 비교. 숫자가 알파벳보다 사전순으로 작다.

// 오름차순
// 내림차순

// a랑 b랑 비교해서 true가 나오면 a가 앞으로

bool compare(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		int sum_a = 0;
		int sum_b = 0;

		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9')
				sum_a += (a[i] - '0');
			if (b[i] >= '0' && b[i] <= '9')
				sum_b += (b[i] - '0');
		}

		if (sum_a == sum_b) {
			for (int i = 0; i < a.size(); i++)
				if (a[i] != b[i])
					return a[i] < b[i];
		}
		else
			return sum_a < sum_b;
	}
}

int main() {
	// 기타의 개수
	// N <= 50
	int N;
	cin >> N;

	string* str_ptr = new string[N];

	for (int i = 0; i < N; i++)
		cin >> str_ptr[i];

	sort(str_ptr, str_ptr + N, compare);

	for (int i = 0; i < N; i++)
		cout << str_ptr[i] << endl;

	return 0;
}