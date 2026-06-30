#include <iostream>

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* M = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int i = 0; i < n2; i++)
		M[i] = arr[m + 1 + i];

	int i, j, k;
	i = 0; j = 0; k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++; k++;
	}
	while (j < n2) {
		arr[k] = M[j];
		j++; k++;
	}

	delete[] L;
	delete[] M;
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	mergeSort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		std::cout << arr[i] << "\n";

	return 0;
}