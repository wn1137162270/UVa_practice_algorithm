#include<iostream>
using namespace std;

const int maxn=1e6+10;

long long f[maxn];

long long value(int x)
{
	long long xl=x;
	return ((xl-1)*(xl-2)/2-(xl-1)/2)/2;
}

int main()
{
	int n;
	f[3]=0;
	for(int i=4;i<maxn;i++)
		f[i]=f[i-1]+value(i);
	cin>>n;
	while(n>=3)
	{
		cout<<f[n]<<endl;
		cin>>n;
	}
	return 0;
}
