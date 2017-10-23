#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000+10;

struct job
{
	int bt,jt;
	bool operator <(const job &x)const
	{
		return jt>x.jt;
	}
};

job jobs[maxn];

int main()
{
	int n,bt,maxx,kase=1;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=0;i<n;i++)
			scanf("%d %d",&jobs[i].bt,&jobs[i].jt);
		sort(jobs,jobs+n);
		bt=0;maxx=0;
		for(int i=0;i<n;i++)
		{
			bt+=jobs[i].bt;
			maxx=max(maxx,bt+jobs[i].jt);
		}
		printf("Case %d: %d\n",kase++,maxx);
		scanf("%d",&n);
	}
	return 0;	
} 
