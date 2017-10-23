#include<cstdio>
#include<algorithm>
using namespace std;

long long d;

int next(int n,int k)
{
	long long k2=(long long)k*k;
	while(k2/d!=0)   
		k2/=10;
	return (int)k2;
}

int main()
{
	int t,n,k,k1,k2,ans;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d",&n,&k);
		d=1;
		while(n--)
			d*=10;
		k1=k;k2=k;
		ans=k;
		do
		{
			k1=next(n,k1);
			k2=next(n,k2);
			ans=max(ans,k2);
			k2=next(n,k2);
			ans=max(ans,k2);
		}while(k1!=k2);
		printf("%d\n",ans);
	}
	return 0;
}
