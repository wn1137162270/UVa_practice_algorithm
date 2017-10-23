#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1e4+10;
const int INF=1e5;

int d[maxn][3];
vector<int> nodes[maxn];

int dp(int u,int fa,int cond)
{
	int c=0,minn=INF,len=nodes[u].size();
	if(d[u][cond]!=-1)
		return d[u][cond];
	if(cond==0)
		c=1;
	for(int i=0;i<len;i++)
		if(fa!=nodes[u][i])
		{
			if(cond==0)
				c+=min(dp(nodes[u][i],u,0),dp(nodes[u][i],u,1));
			else if(cond==1)
				c+=dp(nodes[u][i],u,2);
			else
			{
				minn=min(minn,dp(nodes[u][i],u,0)-dp(nodes[u][i],u,2));
				c+=dp(nodes[u][i],u,2);
			}
		}
	if(cond==2)
		c=c+minn;
	return d[u][cond]=c;
}
 
int main()
{
	int n,end=0,u,v,ans;
	while(end!=-1)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			nodes[i].clear();
		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			u--;v--;
			nodes[u].push_back(v);
			nodes[v].push_back(u);
		}
		memset(d,-1,sizeof(d));
		ans=min(dp(0,-1,0),dp(0,-1,2));
		printf("%d\n",ans);
		scanf("%d",&end);
	}
	return 0;
}
