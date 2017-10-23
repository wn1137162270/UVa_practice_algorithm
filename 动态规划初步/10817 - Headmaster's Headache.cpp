#include<cstdio>
#include<cstring>

const int maxs=8;
const int maxm=20+2;
const int maxn=100+2;
const int maxp=maxm+maxn;

int cost[maxp],st[maxp],d[maxp][1<<maxs][1<<maxs];

int dp(int x,int s0,int s1,int s2)
{
	int &ans=d[x][s1][s2];
	if(ans!=-1)
		return ans;
	   
}

int main()
{
	char ch;
	int sub,m,n;
	scanf("%d %d %d",&sub,&m,&n);
	while(sub!=0)
	{
		scanf("%d %d %d",&sub,&m,&n);
		memset(st,0,sizeof(st));
		for(int i=0;i<m+n;i++)
		{
			scanf("%d",&cost[i]);
			ch=getchar();
			while(ch!='\n')
			{
				if(ch>='1'&&ch<='8')
					st[i]|=1<<(ch-'1');
				ch=getchar();
			}
		}
		memset(d,-1,sizeof(d));
	}
	return 0;	
} 
