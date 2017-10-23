#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;

int a[maxn],b[maxn];

int main()
{
	int n,s,ans;
	while(scanf("%d %d",&n,&s)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		b[0]=0;
		for(int i=1;i<=n;i++)
			b[i]=b[i-1]+a[i];
		int i=0;
		ans=maxn;
		for(int j=1;j<=n;j++)
		{
			while(b[i]<=b[j]-s&&i<j)
				i++;
			if(i>0)
				ans=min(ans,j-i+1);
		}
		printf("%d\n",ans==maxn?0:ans);
	}
	return 0; 
}
