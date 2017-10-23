#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1>>30;

int a[maxn],s[maxn],d[maxn][maxn];

int dp(int x,int y)
{
	int minn=0;
	if(d[x][y]!=INF)
		return d[x][y];
	for(int i=x+1;i<=y;i++)
		minn=min(minn,dp(i,y));
	for(int i=y-1;i>=x;i--)
		minn=min(minn,dp(x,i));
	return d[x][y]=s[y]-s[x-1]-minn;
}

int main()
{
	int n,ans;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s[0]=0;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=INF;
		ans=2*dp(1,n)-s[n];
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;	
} 
