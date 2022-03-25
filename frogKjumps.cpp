#include<bits/stdc++.h>
using namespace std;
int f(int ind ,int*height,int k)
{
	if(ind==0)return 0;

	int minSteps = INT_MAX;
	for(int i = 1 ; i <= k ; i++)
	{
		if(ind-i>=0){
		int jump = f(ind-i , height,k)+abs(height[ind]-height[ind-i]);
		minSteps = min(minSteps , jump);
	}
	}
	return minSteps;
}
int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r" ,stdin);
// 	freopen("output.txt","w" ,stdout);
// #endif
	int arr[] = {30,10,60 , 10 , 60 , 50};
	int n=6;
	cout << f(n-1,arr,2) << endl;

	
}