#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제주소 : https://www.acmicpc.net/problem/2910
// 메모리, 응답시간 : 2024KB, 0ms

class Number {
public:
	int number;
	int count;
	int order;

	Number() {};
	Number(int number, int count, int order) {
		this->number = number;
		this->count = count;
		this->order = order;
	}

	bool operator < (Number& number) {
		if (this->count == number.count)
			return this->order < number.order;

		return this->count > number.count;
	}
};


int main() {
	int N, C;
	cin >> N >> C;

	vector<Number> number_vector;

	int order = 1;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		bool isfound = false;

		for (int j = 0; j < number_vector.size(); j++) {
			if (number_vector[j].number == temp) {
				number_vector[j].count++;
				isfound = true;
			}
		}

		if (isfound == false) {
			number_vector.push_back(Number(temp, 1, order));
			order++;
		}
	}

	sort(number_vector.begin(), number_vector.end());
		
	for (int i = 0; i < number_vector.size(); i++)
		for (int j = 0; j < number_vector[i].count; j++)
			cout << number_vector[i].number << " ";

	return 0;
}