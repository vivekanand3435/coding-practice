#include<bits/stdc++.h>

using namespace std;

bool SubsetSumProblem(int arr[], int size, int value)
{
  if(value == 0)
    return true;
  
  if((size == 0) && (value != 0))
    return false;
  
  if(value < arr[size-1])
    return SubsetSumProblem(arr, size-1, value);
    
  return SubsetSumProblem(arr, size-1, value) || SubsetSumProblem(arr, size-1, value - arr[size-1]);
  
}

int main()
{
  int arr[] = {34, 12, 45, 2, 34};
  int size = sizeof(arr)/sizeof(arr[0]);
  
  cout<<" the recursive result is "<<SubsetSumProblem(arr, size, 14)?"true":"false";
  
  return 0;
}
