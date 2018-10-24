// Program to find minimum number of platforms 
// required on a railway station 
#include<iostream> 
#include<algorithm> 

using namespace std; 

// Returns minimum number of platforms reqquired 
int findPlatform(int arr[], int dep[], int n) 
{ 
  int maxPlat[1440] = {0};
  int result = 0;
  for(int i =0; i < n; i++)
  {
    maxPlat[arr[i]/10] += 1;
    maxPlat[(dep[i]/10)+1] -= 1;
  }
  result = maxPlat[0];
  
  for(int i =1; i < 1440; i++)
  {
    maxPlat[i] += maxPlat[i-1];
    if(result < maxPlat[i])
        result = maxPlat[i];
  }
  return result; 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep, n); 
	return 0; 
} 
