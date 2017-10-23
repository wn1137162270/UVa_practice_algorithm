#include<cstdio>
#include<cstring>

const int maxn=15;
const int maxm=100+2;

int a[maxn],d[maxm][(1<<maxn)+10],sum[(1<<maxn)+10];

int bitcount(int x)
{
	return x==0?0:bitcount(x/2)+(x&1);
}

int dp(int l,int s)
{
	int l2=sum[s]/l;
	if(d[l][s]!=-1)
		return d[l][s];
	if(bitcount(s)==1)
		return d[l][s]=1;
	for(int s0=(s-1)&s;s0;s0=(s0-1)&s)
	{
		if(sum[s0]%l==0&&dp(l,s0)&&dp(l,s^s0))
			return d[l][s]=1;
		if(sum[s0]%l2==0&&dp(l2,s0)&&dp(l2,s^s0))
			return d[l][s]=1;
	}
	return d[l][s]=0;
}

int main()
{
	int n,x,y,ans,kase=0;
	scanf("%d",&n);
	while(n!=0)
	{
		scanf("%d %d",&x,&y);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<(1<<n);i++)
		{
			sum[i]=0;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
					sum[i]+=a[j];	
			} 
		} 
		memset(d,-1,sizeof(d));
		if(sum[(1<<n)-1]==x*y)
			ans=dp(x,(1<<n)-1);
		else
			ans=0;
		printf("Case %d: %s\n",++kase,ans==1?"Yes":"No");
		scanf("%d",&n);
	}
	return 0;
}
