#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long n,m,ans;
	cin>>n>>m;
	while(n!=0||m!=0)
	{
		if(n>m)
			swap(n,m);
		if(n==1&&m==1)
			ans=1;
		else
			ans=n*m*(n+m-2)+2*n*(n-1)*(3*m-n-1)/3;
		cout<<ans<<endl;
		cin>>n>>m;
	} 
	return 0;	
} 
