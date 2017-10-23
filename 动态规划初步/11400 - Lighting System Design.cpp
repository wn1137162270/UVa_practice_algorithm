#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000+10;
const int INF=1<<30;

struct light
{
	int v,k,c,l;	
	bool operator <(const light &lt)const
	{
		return v<lt.v;
	}
};

int d[maxn],s[maxn];
light lts[maxn];

int main()
{
	int n;
	scanf("%d",&n); 
	while(n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d %d %d %d",&lts[i].v,&lts[i].k,&lts[i].c,&lts[i].l);
		sort(lts+1,lts+n+1);
		s[0]=0;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+lts[i].l;
		d[0]=0;
		for(int i=1;i<=n;i++)
		{
			d[i]=INF;
			for(int j=1;j<=i;j++)
				d[i]=min(d[i],d[j-1]+lts[i].k+lts[i].c*(s[i]-s[j-1]));
		}
		printf("%d\n",d[n]);
		scanf("%d",&n); 
	}
	return 0;
}
