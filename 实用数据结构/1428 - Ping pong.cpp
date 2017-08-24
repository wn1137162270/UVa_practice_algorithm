#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=20000+10;
const int maxm=100000+10; 

int a[maxn],c[maxm],l[maxn],r[maxn],maxx;

int lowbit(int x)
{
	return x&-x;
}

int sum(int x)
{
	int res=0;
	while(x>0)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}

void add(int x,int d)
{
	while(x<=maxx)
	{
		c[x]+=d;
		x+=lowbit(x);	
	} 
} 

int main()
{
	int t,n;
	long long cnt;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		maxx=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			maxx=max(maxx,a[j]);
		}
		memset(c,0,sizeof(c));
		for(int j=0;j<n;j++)
		{
			add(a[j],1);
			l[j]=sum(a[j]-1);
		}
		memset(c,0,sizeof(c));
		for(int j=n-1;j>=0;j--)
		{
			add(a[j],1);
			r[j]=sum(a[j]-1);
		}
		cnt=0;
		for(int j=0;j<n;j++)
			cnt+=l[j]*(n-j-1-r[j])+(j-l[j])*r[j];
		printf("%lld\n",cnt);
	}
	return 0;	
} 
