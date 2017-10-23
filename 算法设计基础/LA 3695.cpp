#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1e9+10;

struct point
{
	int x,y;
	bool operator <(const point &p)const
	{
		return x<p.x;	
	}	
};

point pts[maxn];
int xx[maxn],y[maxn],left[maxn],on[maxn],on2[maxn];

int main()
{
	int t,n,num,num2,h,x,maxx,ans,kase=0;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&pts[i].x,&pts[i].y);
			xx[i]=pts[i].x;
			y[i]=pts[i].y;
		}
		sort(pts,pts+n);
		sort(xx,xx+n);
		sort(y,y+n);
		num=unique(y,y+n)-y;
		num2=unique(xx,xx+n)-xx;
		if(num==1||num2==1)
			ans=n;
		else
		{
			ans=1;
			for(int i=0;i<num;i++)
				for(int j=i+1;j<num;j++)
				{
					h=0;x=-INF;left[0]=0;
					memset(on2,0,sizeof(on2));
					memset(on,0,sizeof(on));
					for(int k=0;k<n;k++)
						if(pts[k].y>=y[i]&&pts[k].y<=y[j])
						{
							if(pts[k].x!=x)
							{
								h++;
								left[h]=left[h-1]+on2[h-1]-on[h-1];
							}
							on2[h]++;
							if(pts[k].y>y[i]&&pts[k].y<y[j])
								on[h]++;
							x=pts[k].x;
						}
					maxx=on[1]-left[1];
					for(int k=2;k<=h;k++)
					{
						maxx=max(maxx,on[k-1]-left[k-1]);
						ans=max(ans,maxx+on2[k]+left[k]);
					}
				}
		}
		printf("Case %d: %d\n",++kase,ans);
		scanf("%d",&n);
	}
	return 0;	
} 
