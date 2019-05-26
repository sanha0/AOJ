#include<iostream>
#include<algorithm>

using namespace std;

static const int MAX = 100;

int selectionSort(int A[], int N);
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

	ans = selectionSort(A, N);
	cout << ans << endl;
	return 0;
}

int selectionSort(int A[], int N) {
	int minj;
	int tmp;
	int count = 0;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		minj = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[minj]) {
				minj = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			count++;
			flag = 0;
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