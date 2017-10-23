#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int maxn=1000+10;
const int mul=2000;

int visit[maxn][2],d[maxn][2];
vector<int> w[maxn];

int dp(int i,int j,int fa)
{
	int u,len,ans,sum=0;
	if(visit[i][j])
		return d[i][j];
	visit[i][j]=1;
	len=w[i].size();
	ans=mul;
	for(int k=0;k<len;k++)
	{  
		u=w[i][k];
		if(u!=fa)
			ans+=dp(u,1,i);
	}
	if(!j&&fa>=0)
		ans+=1;
	if(j||fa<0)
	{
		for(int k=0;k<len;k++)
		{  
			u=w[i][k];
			if(u!=fa)
				sum+=dp(u,0,i);
		}
		if(fa>=0)
			sum+=1;
		ans=min(ans,sum);
	}
	return d[i][j]=ans;
}

int main()
{
	int t,n=0,m,u,v,ans;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		for(int i=0;i<n;i++)
			w[i].clear();
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			w[u].push_back(v);
			w[v].push_back(u);
		}
		memset(visit,0,sizeof(visit));
		ans=0;
		for(int i=0;i<n;i++)
		{
			if(!visit[i][0])
				ans+=dp(i,0,-1);
		}
		printf("%d %d %d\n",ans/mul,m-ans%mul,ans%mul);
	}
	return 0;
}
