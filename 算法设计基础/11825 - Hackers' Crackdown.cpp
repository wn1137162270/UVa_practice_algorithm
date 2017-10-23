#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=16;
const int maxm=1<<16;

int p[maxn],cover[maxm],f[maxm];

int main()
{
	int n,m,x,all,kase=0;
	scanf("%d",&n);    
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			p[i]=1<<i;
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				p[i]|=1<<x;
			}
		}
		all=1<<n;
		for(int i=0;i<all;i++)
		{
			cover[i]=0;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
					cover[i]|=p[j];
			}
		}
		for(int i=0;i<all;i++)
		{
			f[i]=0;
			for(int i0=i;i0;i0=(i0-1)&i)
			{
				if(cover[i0]==all-1)
					f[i]=max(f[i],f[i^i0]+1);
			}
		}
		printf("Case %d: %d\n",++kase,f[all-1]);
		scanf("%d",&n);
	}
	return 0;	
} 
