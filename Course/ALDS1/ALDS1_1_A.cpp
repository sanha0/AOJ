#include<iostream>
#include<algorithm>

using namespace std;

static const int MAX = 100;

void insertionSort(int A[], int N);
void output(int A[],int N);


int main() {

	int A[MAX], N;
	
	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	output(A,N);
	insertionSort(A, N);
	return 0;
}

void insertionSort(int A[],int N) {
	int v = -1;
	int j = -1;
	for (int i = 1; i < N; i++) {
		v = A[i];
		j = i-1;
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		output(A, N);
	}
}

void output(int A[],int N) {
	for (int i = 0; i < N-1; i++)
	{
		cout << A[i]<<" "<<flush;
	}
	cout << A[N - 1] << endl;
}