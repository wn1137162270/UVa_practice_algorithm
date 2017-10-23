#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100+10;
const int INF=1>>30;

int a[maxn],s[maxn],d[maxn][maxn],f[maxn][maxn],g[maxn][maxn];

int main()
{
	int n,ans,j,minn;
	scanf("%d",&n);
	while(n!=0)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s[0]=0;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;i++)
			f[i][i]=g[i][i]=d[i][i]=a[i];
		for(int l=1;l<n;l++)
			for(int i=1;i+l<=n;i++)
			{
				j=i+l;
				minn=0;
				minn=min(minn,f[i+1][j]);
				minn=min(minn,g[i][j-1]);
				d[i][j]=s[j]-s[i-1]-minn;
				f[i][j]=min(d[i][j],f[i+1][j]);
				g[i][j]=min(d[i][j],g[i][j-1]);
			}
		ans=2*d[1][n]-s[n];
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;	
} 
