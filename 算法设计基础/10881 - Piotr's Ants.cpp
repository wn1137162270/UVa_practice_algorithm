#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
const char dir_name[3][10]={"L","Turning","R"};

typedef long long ll;

struct ant
{
	int id; 
	ll loc;
	int dir;
	
	bool operator <(const ant &x)const 
	{
		return loc<x.loc;
	}	
};

ant start[maxn],endd[maxn];
int findd[maxn];

int main()
{
	ll length,time,loc;
	int n,kase,k,d;
	char dir;
	scanf("%d",&kase);
	for(int k=0;k<kase;k++)
	{
		scanf("%lld %lld %d",&length,&time,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld %c",&loc,&dir);
			d=(dir=='R')?1:-1;
			start[i]=(ant){i,loc,d};
			endd[i]=(ant){-1,loc+d*time,d};
		}
		sort(start,start+n);
		for(int i=0;i<n;i++)
			findd[start[i].id]=i;
		sort(endd,endd+n);
		for(int i=1;i<n;i++)
			if(endd[i].loc==endd[i-1].loc)
				endd[i].dir=endd[i-1].dir=0;
		printf("Case #%d:\n",k+1);
		for(int i=0;i<n;i++)
		{
			if(endd[findd[i]].loc<0||endd[findd[i]].loc>length)
				printf("Fell off\n");
			else
				printf("%lld %s\n",endd[findd[i]].loc,dir_name[endd[findd[i]].dir+1]);
		}
		printf("\n");
	}
	return 0;
}
