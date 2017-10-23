#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
const int INF=1<<30;

struct package
{
	int x,y,w;
};

int origin[maxn],dist[maxn],d[maxn];
package ps[maxn];

int main()
{
	int t,c,n,x,y,w,sum,j;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d",&c,&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d %d %d",&x,&y,&w);
			ps[i]=(package){x,y,w};
		}
		for(int i=1;i<=n;i++) 
			origin[i]=ps[i].x+ps[i].y;
		dist[1]=0;
		for(int i=2;i<=n;i++) 
			dist[i]=dist[i-1]+abs(ps[i].x-ps[i-1].x)+abs(ps[i].y-ps[i-1].y);
		d[0]=0;
		for(int i=1;i<=n;i++) 
		{
			d[i]=INF;
			sum=ps[i].w;j=i;
			while(j>=1&&sum<=c)
			{
				d[i]=min(d[i],d[j-1]+origin[j]-dist[j]);
				j--;
				sum+=ps[j].w;
			}
			d[i]+=origin[i]+dist[i];
		}
		printf("%d\n",d[n]);
		if(kase!=t-1)
			printf("\n");
	}
	return 0; 
} 
