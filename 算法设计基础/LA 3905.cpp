#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;

struct endd
{
	double time;
	int type;
	bool operator <(const endd &e)const
	{
		return time<e.time||(time==e.time&&type>e.type);
	}
};

int w,h;
endd endds[2*maxn];

void update(int x,int a,int w,double &l,double &r)
{
	if(a==0)
	{
		if(x<=0||x>=w)
			r=l-1;
	}
	else if(a>0)
	{
		l=max(l,(double)(-x)/a);
		r=min(r,(double)(w-x)/a);
	}
	else
	{
		r=min(r,(double)(-x)/a);
		l=max(l,(double)(w-x)/a);
	}
}

int main()
{
	int t,n,x,y,a,b,num,cnt,ans;
	double l,r;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d",&w,&h);
		scanf("%d",&n);
		num=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&x,&y,&a,&b);
			l=0;r=3*maxn;
			update(x,a,w,l,r);
			update(y,b,h,l,r);
			if(r>l)
			{
				endds[num++]=(endd){l,1};
				endds[num++]=(endd){r,2};
			}
		}
		sort(endds,endds+num);
		cnt=0;ans=0;
		for(int i=0;i<num;i++)
		{
			if(endds[i].type==1)
			{
				cnt++;
				ans=max(ans,cnt);
			}
			else
				cnt--;
		}
		printf("%d\n",ans);
	}
	return 0;	
} 
