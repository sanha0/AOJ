#include<iostream>
#include<algorithm>

using namespace std;

static const int MAX = 1000000;

void output(int A[], int N);

void insertionSort(int A[],int n,int g);
void shellSort(int A[],int n);

static int cnt = 0;

int main() {

	int A[MAX], N;

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	shellSort(A, N);

	return 0;
}

void insertionSort(int A[],int n,int g) {
	int v;
	int j;
	for (int i = g; i <n; i++)
	{
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[],int n) {
	const int m = 11;
	int m_count = 0;
	int G[m] = { 90000,30000,10000,3000 ,729,243 ,81 , 27 ,9,4,1};


	for (int i = 0; i < m;i++)
	{
		if (G[i] > n) {
			continue;
		}
		else {
			m_count++;
			insertionSort(A, n, G[i]);
		}
	}

	cout << m_count<< endl;

	for (int i = 0; i < m_count-1; i++)
	{
		cout << G[m - m_count+i] <<" "<<flush;
	}
	cout << G[10] << endl;
	cout << cnt << endl;
	output(A, n);
}


void output(int A[], int N) {
	for (int i = 0; i < N; i++)
	{
		cout << A[i] <<endl;
	}
}