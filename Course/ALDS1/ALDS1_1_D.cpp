#include<iostream>
#include<algorithm>

using namespace std;

static const int MAX = 200000;

int main() {

	int R[MAX],n;
	cin >> n;
	int minv = 0;
	int maxv= -1000000000;

	for (int i = 0; i < n; i++)
	{
		cin >> R[i];
	}
	
	minv = R[0];
		for (int j = 1; j < n; j++)
		{
			maxv = max(maxv,R[j]-minv);
			minv = min(minv, R[j]);
		}
	cout << maxv<<endl;

	return 0;
}