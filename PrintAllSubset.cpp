// CPP program to find the largest subset which
// where each pair is divisible.
#include <bits/stdc++.h>
using namespace std;

void PrintAllSubsetsUtil(int a[], int i, int n, vector<int>&v)
{
    if(i == n)
    {
        for(int idx = 0; idx < v.size(); idx++)
        {
            cout<<v[idx]<<"--";
        }
        cout<<endl;
        return;
    }
    
    v.push_back(a[i]);
    PrintAllSubsetsUtil(a,  i+1, n, v);
    v.pop_back();
    PrintAllSubsetsUtil(a,  i+1, n, v);
}

void PrintAllSubsets(int a[], int n)
{
    vector<int> v;
    PrintAllSubsetsUtil(a,  0, n, v);
}


// driver code to check the above function
int main()
{
	int a[] = { 1, 3, 5};
	int n = sizeof(a) / sizeof(a[0]);
	PrintAllSubsets(a, n) ;
	return 0;
}
