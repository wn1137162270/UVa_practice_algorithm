#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=500+10;

int a[maxn][maxn],b[maxn][maxn],sum1[maxn][maxn],sum2[maxn][maxn],d[maxn][maxn],f[maxn][maxn];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while(n!=0||m!=0)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        for(int i=1;i<=n;i++)
        {
            sum1[i][0]=0;
            for(int j=1;j<=m;j++)
                sum1[i][j]=sum1[i][j-1]+a[i][j];
        }
        for(int i=1;i<=n;i++)
        {
            sum2[i][0]=0;
            for(int j=1;j<=m;j++)
                sum2[i][j]=sum2[i][j-1]+b[i][m-j+1];
        }
        for(int j=0;j<=m;j++)
            f[0][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                d[i][j]=sum1[i][j]+sum2[i][m-j]+f[i-1][j];
                if(j==0)
                    f[i][j]=d[i][j];
                else
                    f[i][j]=max(f[i][j-1],d[i][j]);
            }
        printf("%d\n",f[n][m]);
        scanf("%d %d",&n,&m);
    }
    return 0;
}
