// A O(n) program to find the largest subarray 
// with equal number of 0s and 1s 

#include <stdio.h> 
#include <stdlib.h>
#include<climits>
#include<map>
#include<iostream>
using namespace std;

// A utility function to get maximum of two 
// integers 

int max(int a, int b) { return a>b? a: b; } 

// This function Prints the starting and ending 
// indexes of the largest subarray with equal 
// number of 0s and 1s. Also returns the size 
// of such subarray. 

int findSubArray(int arr[], int n) 
{ 
    int sumleft[n] = {0};
    map<int,int> mValueIndex;
    sumleft[0] = ((arr[0] == 0) ? -1 : 1);
    int startindex = 0, maxsize = INT_MIN;
    mValueIndex[((arr[0] == 0) ? -1 : 1)] = 0;
    for(int i = 1; i < n; i++)
    {
        sumleft[i] += sumleft[i-1]+((arr[i] == 0) ? -1 : 1);
        map<int,int>::iterator itr = mValueIndex.find(sumleft[i]);
        
        if( itr != mValueIndex.end())
        {
            if((i - itr->second ) > maxsize) 
            {
                startindex = itr->second;
                maxsize = i - itr->second;
            }
        }
        else
            mValueIndex[sumleft[i]] = i;
    }
    
     map<int,int>::iterator itr = mValueIndex.begin();
     while(itr != mValueIndex.end())
     {
         cout<<itr->first<<"---"<<itr->second<<endl;
         itr++;
     }
    if (maxsize == -1) 
        printf("No such subarray"); 
    else
        printf("%d to %d", startindex, startindex+maxsize-1); 
   
	return maxsize; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {1, 0, 1, 1, 1, 0, 0};
	int size = sizeof(arr)/sizeof(arr[0]); 

	findSubArray(arr, size); 
	return 0; 
} 
