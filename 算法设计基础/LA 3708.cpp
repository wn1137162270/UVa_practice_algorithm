#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	double ans,pos;
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		ans=0;
		for(int i=1;i<n;i++)
		{
			pos=(double)(i*(n+m))/(double)n;
			ans+=abs(floor(pos+0.5)-pos);
		}
		printf("%.6lf\n",ans*10000/(n+m));
	}
	return 0;
}
