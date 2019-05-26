#include<iostream>
#include<algorithm>

using namespace std;

static const int MAX = 100;

struct Trump {
	char mark;
	int value;
};

void selectionSort(Trump C[], int N);
void bubbleSort(Trump C[], int N);
void checkStable(Trump C1[], Trump C2[],int N);
void output(Trump C[], int N);


int main() {

	int N;
	char card[10];
	Trump T1[MAX],T2[MAX];

	//input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> card;
		T1[i].mark = card[0];
		T1[i].value = (int)(card[1]-'0');
		T2[i].mark = card[0];
		T2[i].value = (int)(card[1] - '0');
	}
	bubbleSort(T1, N);
	selectionSort(T2, N);
	checkStable(T1, T2, N);
	return 0;
}

void bubbleSort(Trump C[], int N) {
	Trump tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = N-1; j >= i+1; j--)
		{
			if (C[j].value < C[j - 1].value) {
				tmp = C[j];
				C[j] = C[j - 1];
				C[j - 1] = tmp;
			}
		}
	}
	output(C, N);
	cout << "Stable" << endl;
}

void selectionSort(Trump C[], int N) {
	int minj;
	int flag=0;
	Trump tmp;
	for (int i = 0; i < N; i++)
	{
		minj = i;
		for (int j = i; j < N; j++)
		{
			if (C[j].value < C[minj].value) {
				minj = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			tmp = C[i];
			C[i] = C[minj];
			C[minj] = tmp;
		}
		flag = 0;
	}
	output(C, N);
}

void output(Trump C[], int N) {
	for (int i = 0; i < N - 1; i++)
	{
		cout << C[i].mark << C[i].value<<" " << flush;
	}
	cout << C[N - 1].mark <<C[N-1].value <<endl;
}

void checkStable(Trump C1[],Trump C2[],int N) {
	for (int i = 0; i < N; i++)
	{
		if (C1[i].mark!= C2[i].mark || C1[i].value != C2[i].value) {
			cout << "Not stable" << endl;
			return;
		}
	}
	cout << "Stable" << endl;
}