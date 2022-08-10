#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int n)
{
	int m[n][n];

	int i, j, k, L, temp;


	for (i = 1; i < n; i++)
		m[i][i] = 0;

	for (L = 2; L < n; L++)
	{
		for (i = 1; i < n - L + 1; i++)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++)
			{

				temp = m[i][k] + m[k + 1][j]
					+ p[i - 1] * p[k] * p[j];
				if (temp < m[i][j])
					m[i][j] = temp;
			}
		}
	}

	return m[1][n - 1];
}

int main()
{
	int arr[] = { 2,3,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications: "
		<< MatrixChainOrder(arr, size);

	getchar();
	return 0;
}

