#include<bits/stdc++.h>

using namespace std;

bool SubsetSumProblemUtil(int arr[], int size, int value, int m)
{
  //cout<<"called for size = "<<size<<endl;
  if(size == 0)
    return false;
  if((value+arr[size-1])%m == 0)
    return true;
  //cout<<"sum is "<<value+arr[size-1]<<endl;
  return SubsetSumProblemUtil(arr, size-1, value, m) || SubsetSumProblemUtil(arr, size-1, value + arr[size-1], m);
  
}

bool SubsetSumProblem(int arr[], int size, int m)
{
    return SubsetSumProblemUtil(arr, size, 0, m);
}

int main()
{
  int arr[] = {34, 12, 45, 2, 34};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  cout<<" the recursive result is "<<SubsetSumProblem(arr, size, 127)?"true":"false";
  
  return 0;
}
