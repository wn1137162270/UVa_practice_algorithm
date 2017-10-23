#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;

const int maxn=50+5;
const int INF=1<<30;

int a[maxn],d[maxn][maxn];

int dp(int i,int j)
{
	int minn=INF;
	if(d[i][j]!=-1)
		return d[i][j];
	if(i==j)
		return d[i][j]=0;
	for(int k=i;k<j;k++)
		minn=min(minn,dp(i,k)+dp(k+1,j)+a[j]-a[i-1]);
	return d[i][j]=minn;
}

int main()
{
	int l,n;
	scanf("%d",&l);
	while(l!=0)
	{
		scanf("%d",&n);
		a[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=l;
		memset(d,-1,sizeof(d));
		printf("The minimum cutting is %d.\n",dp(1,n+1)); 
		scanf("%d",&l);
	}
	return 0;	
} 
