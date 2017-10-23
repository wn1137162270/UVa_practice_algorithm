#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

const int maxn=1e6+10;

ll a[maxn],res[maxn];

int main()
{
	int n;
	ll total,last,s,ans,t;
	while(scanf("%d",&n)!=EOF)
	{
		total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			total+=a[i];
		}
		last=total/n;
		s=0;
		for(int i=0;i<n;i++)
		{
			res[i]=s;
			s+=a[i]-last;
		}
		sort(res,res+n);
		t=res[n/2];
		ans=0;
		for(int i=0;i<n;i++)
			ans+=abs(t-res[i]);
		printf("%I64d\n",ans);
	}
	return 0;
}
