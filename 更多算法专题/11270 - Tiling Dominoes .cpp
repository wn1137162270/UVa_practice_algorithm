#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxm=12;

long long d[2][1<<maxm];
int m,cur;

void update(int a,int b)
{
	if(b&(1<<m))
		d[cur][b^(1<<m)]+=d[1-cur][a];
}

int main()
{
	int n,all;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n*m%2)
		{
			printf("0\n");
			continue;
		}
		if(m>n)
			swap(n,m);
		all=(1<<m)-1;cur=0;
		memset(d[0],0,sizeof(d[0]));
		d[0][all]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cur^=1;	
				memset(d[cur],0,sizeof(d[cur]));
				for(int k=0;k<=all;k++)
				{
					update(k,k<<1);
					if(i&&!(k&(1<<(m-1))))
						update(k,(k<<1)^(1<<m)^1);
					if(j&&!(k&1))
						update(k,(k<<1)^3);
				}
			}
		printf("%lld\n",d[cur][all]);
	}
	return 0;	
} 
