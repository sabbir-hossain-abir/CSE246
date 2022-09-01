#include <stdio.h>


int max(int a, int b)
{
	return (a > b) ? a : b;
}


int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int V[n + 1][W + 1];

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				V[i][w] = 0;
			else if (wt[i - 1] <= w)
				V[i][w] = max(val[i - 1] + V[i - 1][w - wt[i - 1]], V[i - 1][w]);
			else
				V[i][w] = V[i - 1][w];
		}
	}

	int res = V[n][W];   
    printf("maximum value that can be obtained: %d\n", res);

 	w = W;

 	printf("Included Weights: ");
    	for (i = n; i > 0 && res > 0; i--) {
         
        	if (res == V[i - 1][w])
            	continue;       
        	else {
            	printf("%d ", wt[i - 1]);
            	res = res - val[i - 1];
            	w = w - wt[i - 1];
        	}
    	}
}

int main()
{
	int val[] = { 40, 100, 50, 60 };
	int wt[] = { 20, 10, 40, 30 };
	int W = 60;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}
