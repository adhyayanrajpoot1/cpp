#include<bits/stdc++.h>
using namespace std;
int fiboDPoptimised(int n , vector<int>&v)
{
	int prev1 = 1;
	int prev2 = 0;

	for(int i = 2 ; i <= n ; i++)
	{
		int curr = prev2+prev1;
		prev2 = prev1;
		prev1 = curr;

	}
	return prev1;
}
int fibDP(int n , vector<int>&v)
{
	v[0] = 0;
	v[1] = 1;
	for(int i = 2 ; i <= n ; i++)
	{
		v[i] = v[i-1]+v[i-2];
	}
	return v[n];
}
int fiboMem(int n , vector<int>&v)
{
	if(n<=1)return n;
	if(v[n]!=-1)return v[n];
	int smallAns = fiboMem(n-1 , v)+fiboMem(n-2 , v);
	v[n] = smallAns;
	return smallAns; 
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r" ,stdin);
	freopen("output.txt","w" ,stdout);
#endif
	int n;
	cin >> n;
	vector<int>dp(n+1,-1);
	cout << fiboDPoptimised(n , dp)<<endl;
	
}