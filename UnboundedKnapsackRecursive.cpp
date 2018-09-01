// C++ program to find maximum achievable value
// with a knapsack of weight W and multiple
// instances allowed.
#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value with knapsack of
// W capacity
int unboundedKnapsack(int W, int n, int val[], int wt[], int &maxValue)
{
	// dp[i] is going to store maximum value
	// with knapsack capacity i.
    if( W == 0)
        return true;
    int maxSoFar = INT_MIN;
    bool foundASeries = false;
    for(int i = 0; i < n; i++)
    {
        if(W >= wt[i])
        {
            maxValue  = 0;
            if(unboundedKnapsack(W-wt[i], n, val, wt, maxValue))
            {
                foundASeries = true;
                maxSoFar = max(maxSoFar, maxValue + val[i]);
            }
        }
    }
    maxValue = maxSoFar;
    return foundASeries;
}

// Driver program
int main()
{
	int W = 8;
	int val[] = {10, 40, 50, 70};
	int wt[] = {1, 3, 4, 5};
	int maxValue = 0;
	int n = sizeof(val)/sizeof(val[0]);

	cout << unboundedKnapsack(W, n, val, wt, maxValue)<<endl;
    cout<< "max value is "<<maxValue;
	return 0;
}
