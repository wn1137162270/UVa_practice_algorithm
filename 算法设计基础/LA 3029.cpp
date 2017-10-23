#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000+10;

char mat[maxn][maxn];
int left[maxn][maxn],right[maxn][maxn],up[maxn][maxn];

int main()
{
	char ch;
	int t,n,m,lo,ro,ans;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++) 
			{
				ch=getchar();
				while(ch!='F'&&ch!='R')
					ch=getchar();
				mat[i][j]=ch;
			}
		for(int i=1;i<=m;i++)
			up[0][i]=0; 
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++) 
			{
				if(mat[i-1][j-1]!='F')
					up[i][j]=0;
				else
					up[i][j]=up[i-1][j]+1;
			}
		for(int i=1;i<=m;i++)
			left[0][i]=0; 
		for(int i=1;i<=n;i++) 
		{
			lo=0;
			for(int j=1;j<=m;j++)
			{
				if(up[i][j]==0)
				{
					lo=j;
					left[i][j]=0;
				}
				else
					left[i][j]=max(left[i-1][j],lo+1);
			} 
		} 
		for(int i=1;i<=m;i++)
			right[0][i]=m; 
		for(int i=1;i<=n;i++) 
		{
			ro=m+1;
			for(int j=m;j>=1;j--)
			{
				if(up[i][j]==0)
				{
					ro=j;
					right[i][j]=m;
				}
				else
					right[i][j]=min(right[i-1][j],ro-1);
			} 
		} 
		ans=0;
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++)
				if(up[i][j]!=0)
					ans=max(ans,up[i][j]*(right[i][j]-left[i][j]+1));
		printf("%d\n",ans*3);
	} 
	return 0;
}
