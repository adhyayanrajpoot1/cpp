#include<bits/stdc++.h>

using namespace std;
string longestPalindrome1(string s) {
        int n = s.length(), mx = 1, st=0;
        
        for(int i=0; i<n; i++){
            int low = i, high = i;
            
            while(low >=0 && s[low] == s[i]) low--;
            while(high <n && s[high] == s[i]) high++;
            
            while(low>=0 && high <n && s[low] == s[high]){
                low--;
                high++;
            }
            
            if(mx < (high - low -1)){
                st = low + 1;
                mx = high - low -1;
            }
        }
        
        return s.substr(st, mx);
    }
string longestPalindrome(string s) {
        int n = s.length();
        int**dp = new int*[n];
        for(int i = 0 ; i < n ; i++)
        {
        	dp[i] = new int[n];
        	for(int j = 0 ; j < n ; j++)
        	{
        		dp[i][j] = 0;
        	}
        }
        
////////////////////////////  
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if( i==j)
                    dp[i][j] = 1;
                
                else if(s[i] == s[j]){
                    if(i == j-1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i+1][j-1] ? 2 + dp[i+1][j-1] : 0;
                }
            }
        }
        
 ///////////////////////////       
        int mx = 0, st=0, ed=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(mx <dp[i][j]){
                    mx = dp[i][j];
                    st = i;
                    ed = j;
                }
            }
        }
        
        return s.substr(st, ed-st+1);
    }
bool isPalindrome(string str,int i , int j)
{
	int left = i;
	int right = j;
	while(left<=right)
	{
		if(str[left++]!=str[right--])
		{
			return false;
		}

	}
	return true;
}
string longestSubstring(string str)
{
	int si = 0 , ei = 0;
	int n = str.length();
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i ; j < n ; j++)
		{
			if(isPalindrome(str,i,j))
			{
				if(ei-si < j-i)
				{
					si = i;
					ei = j;
				}
			}
		}
	}return str.substr(si , ei-si+1);
}
int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r" ,stdin);
// 	freopen("output.txt","w" ,stdout);
// #endif
	string s;
	cin >> s;
	string str1 = longestPalindrome(s);
	cout << str1 << endl;
	
}