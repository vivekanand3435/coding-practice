// A Naive recursive C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
   // base case 
   if (V == 0) return 0; 
   if(m == 0 && V > 0)
        return INT_MAX;
        
   // Initialize result 
   int res = INT_MAX; 
  
   // Try every coin that has smaller value than V 

     if (coins[m-1] <= V) 
     { 
         int sub_res = minCoins(coins, m, V-coins[m-1]); 
  
         // Check for INT_MAX to avoid overflow and see if 
         // result can minimized 
         if (sub_res != INT_MAX && sub_res + 1 < res) 
            res = sub_res + 1; 
     } 
     int sub_res = minCoins(coins, m-1, V);
     if (sub_res != INT_MAX && sub_res < res) 
            res = sub_res; 
   return res; 
}


// Driver program to test above function
int main()
{
	int coins[] = {9, 6, 5, 1};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 5;
	cout << "Minimum coins required is "
		<< minCoins(coins, m, V);
	return 0;
}
