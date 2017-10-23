#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxm=11+2;
const int maxn=128+2;
const int INF=1<<30;

char s[maxm];
int object[maxn],cnt[1<<11][1<<11],d[1<<11][1<<11];

int main()
{
	int m,n,all,maxx,flag;
	scanf("%d %d",&m,&n);
	while(m!=0||n!=0)
	{
		memset(object,0,sizeof(object));
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			for(int j=0;j<m;j++)
				if(s[j]=='1')
					object[i]|=1<<j;
		}
		memset(cnt,0,sizeof(cnt));
		all=(1<<m)-1;
		for(int i=0;i<=all;i++)
			for(int j=0;j<n;j++)
				cnt[i][i&object[j]]++;
		for(int i=all;i>=0;i--)
		{
			flag=1;
			for(int s0=i;s0||flag;s0=(s0-1)&i)
			{
				if(cnt[i][s0]==0||cnt[i][s0]==1)
					d[i][s0]=0;
				else
				{
					d[i][s0]=INF;
					for(int j=0;j<m;j++)
						if(!(i&(1<<j)))
						{
							maxx=max(d[i|(1<<j)][s0|(1<<j)],d[i|(1<<j)][s0]);
							d[i][s0]=min(maxx+1,d[i][s0]);
						}
				}
				if(s0==0)
					flag=0;
			}
		}
		printf("%d\n",d[0][0]);
		scanf("%d %d",&m,&n);
	}
	return 0;
}
