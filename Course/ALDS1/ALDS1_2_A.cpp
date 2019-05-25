#include<iostream>
#include<algorithm>

using namespace std;

static const int MAX = 100;

int bubbleSort(int A[], int N);
void output(int A[], int N);

int main() {

	int A[MAX], N;
	int ans;

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	ans = bubbleSort(A, N);
	cout << ans << endl;
	return 0;
}

int bubbleSort(int A[], int N) {
	int count = 0;
	int flag = 1;
	int tmp;
	while (flag) {
		flag = 0;
		for (int j = N - 1; j > 0; j--) {
			if (A[j] < A[j - 1]) {
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				count++;
				flag = 1;
			}
		}
	}
	output(A, N);
	return count;
}

void output(int A[], int N) {
	for (int i = 0; i < N - 1; i++)
	{
		cout << A[i] << " " << flush;
	}
	cout << A[N - 1] << endl;
}