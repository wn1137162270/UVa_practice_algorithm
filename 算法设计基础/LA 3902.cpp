#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=1000+10;

bool covered[maxn];
int fa[maxn],k;
vector<int> noroot[maxn],nodes[maxn];

void dfs(int u,int father,int d)
{
	int v,len=noroot[u].size();
	if(len==1&&d>k)
		nodes[d].push_back(u);
	for(int i=0;i<len;i++)
	{
		v=noroot[u][i];
		if(v!=father)
			dfs(v,fa[v]=u,d+1);
	}
}

void dfs2(int u,int f,int d)
{
	int v,len=noroot[u].size();
	if(d>k)
		return ;
	covered[u]=true;
	for(int i=0;i<len;i++)
	{
		v=noroot[u][i];
		if(v!=f)
			dfs2(v,u,d+1);
	}
}

int main()
{
	int t,n=0,s,u,v,len,cnt;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		for(int i=0;i<n;i++)
		{
			noroot[i].clear();
			nodes[i].clear();
		}
		scanf("%d",&n);
		scanf("%d %d",&s,&k);
		s--;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			u--;v--;
			noroot[u].push_back(v);
			noroot[v].push_back(u);
		}
		dfs(s,-1,0);
//		for(int i=0;i<n;i++)
//			printf("%d %d\n",i,fa[i]);
		cnt=0;
		memset(covered,0,sizeof(covered));
//		for(int i=0;i<n;i++)
//			printf("--%d %d\n",i,covered[i]);
		for(int i=n-1;i>k;i--)
		{
			len=nodes[i].size();
			for(int j=0;j<len;j++)
			{
				u=nodes[i][j];
				if(!covered[u])
				{
					cnt++;
					for(int h=0;h<k;h++)
						u=fa[u];
					dfs2(u,-1,0);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
