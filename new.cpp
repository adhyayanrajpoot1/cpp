#include<bits/stdc++.h>
using namespace std;
//get ith bit
int getIth(int n , int i)
{
	int mask = 1 << i;
	return mask&n;
}
void clearIthBit(int &n , int i)
{
	cout << n << ":->" ;
	int mask = ~(1<<i);
	n=n&mask;
}
void clearLastIthBit(int &n , int i)
{
	int mask = (-1<<i);
	n=n&mask;
}
void clearRangeOfBits(int&n , int i , int j)
{
	int a = (~0) << (j+1);
	int b = (1<<i)-1;
	int mask = a|b;
	n=n&mask;
}

//you are given two 32 bit number, N and M,and two bit position i ans j
//Write a method to set all bits between i and j in N equal to M.
//M becomes a substring of N locationed at andstarting at j;
void replaceBits(int&n , int i , int j , int m)
{
	clearRangeOfBits(n , i , j);
	int mask = m << i;
	n = n | mask;
}
//check whether a number is a power of 2 or not
void checkPowerOf2(int n)
{
	if((n&(n-1))==0)cout << "Power of 2" <<endl;
	else cout << "Not a power of 2" << endl;
}

int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r" ,stdin);
// 	freopen("output.txt","w" ,stdout);
// #endif
	int n , i ,j ,m;
	// cin >> n >> i >> j >>m;
	cin >> n;
	// clearIthBit(n , i);
	checkPowerOf2(n );
	// cout<<n<<endl;


	
}