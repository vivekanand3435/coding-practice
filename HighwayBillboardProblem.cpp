// C++ program to find maximum revenue by placing
// billboard on the highway with given constarints.
#include<bits/stdc++.h>
using namespace std;

int maxRevenue(int m, int x[], int revenue[], int n,
											int t)
{
	if(m <= 0)
	    return 0;
	if(n <= 0)
	    return 0;
	if(x[n-1] >= m)
	    return maxRevenue(m,x,revenue,n-1,t);
	else 
	    return max(maxRevenue(x[n-1]-t,x,revenue,n-1,t) + revenue[n-1], maxRevenue(m,x,revenue,n-1,t));
}

// Driven Program
int main()
{
	int m = 15;
	int x[] = {6, 9, 12, 14};
	int revenue[] = {5, 6, 3, 7};
	int n = sizeof(x)/sizeof(x[0]);
	int t = 2;
	cout << maxRevenue(m, x, revenue, n, t) << endl;
	return 0;
}
