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

int origin[maxn],dist[maxn],d[maxn],q[maxn];
package ps[maxn];

int func(int x)
{
	return d[x-1]+origin[x]-dist[x];
} 

int main()
{
	int t,c,n,x,y,w,sum,front,rear,f,k;
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
		front=1;rear=1;sum=0;d[0]=0;k=1;
		for(int i=1;i<=n;i++) 
		{
			f=func(i);
			for(int j=rear-1;j>=front&&func(q[j])>=f;j--)
				rear--;
			q[rear++]=i;
			sum+=ps[i].w;
			while(sum>c)
			{
				sum-=ps[k].w;
				if(k==q[front])
					front++;
				k++;
			}
			d[i]=func(q[front])+dist[i]+origin[i];
		}
		printf("%d\n",d[n]);
		if(kase!=t-1)
			printf("\n");
	}
	return 0; 
} 
