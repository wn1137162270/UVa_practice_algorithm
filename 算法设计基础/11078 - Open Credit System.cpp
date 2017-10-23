#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;

int a[maxn];

int main()
{
	int t,n,ans,maxx;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		maxx=a[0];
		ans=a[0]-a[1];   
		for(int i=1;i<n;i++)
		{
			maxx=max(maxx,a[i-1]);
			ans=max(ans,maxx-a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
