// C++ program to build the smallest number by removing 
// n digits from a given number 
#include<bits/stdc++.h> 
using namespace std; 


string buildLowestNumber(string num, int k) 
{ 
        int count = k;
        vector<char> str(num.begin(), num.end()) ;
        int i = 0;
        int len = num.length();
        vector<char>::iterator itr = str.begin();
        while(count>0)
        {
            while( itr+1 != str.end() && *itr <= *(itr+1))
            {
                itr++;
            }
            str.erase(itr);
            itr--;
            count--;
        }
     
        itr = str.begin();
        while((itr != str.end()) && (*itr == '0'))
            str.erase(itr);
        if(str.empty())
            return "0";
        else 
        return string(str.begin(), str.end());
    
} 

// Driver program to test above function 
int main() 
{ 
	string str = "5555782"; 
	int n = 3; 
	cout << buildLowestNumber(str, n)<< endl; 
	return 0; 
} 
// This code is contributed by Gaurav Mamgain 
