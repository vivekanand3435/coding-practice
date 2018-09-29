// C++ program to reverse individual words in a given 
// string using STL list 
#include <bits/stdc++.h> 
using namespace std; 

void reverseWord(string &str, int st, int end)
{
    while(st <= end)
    {
        char t = str[st];
        str[st] = str[end];
        str[end] = t;
        st++;
        end--;
    }
}
// reverses individual words of a string 
void reverseWords(string str) 
{ 
   int st = 0, i = 0;
   while(i < str.length())
   {
       while(str[i] != ' ' && str[i] != '\0')
                i++;
       reverseWord(str, st, i-1);
       while(str[i] == ' ')
                i++;
       st = i;
       
   }
   cout<<"reversed string is "<<str<<endl;
} 

// Driver program to test function 
int main() 
{ 
	string str = "Geeks for Geeks"; 
	reverseWords(str); 
	return 0; 
} 
