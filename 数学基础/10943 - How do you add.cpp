#include<cstdio>
#include<cstring>

const int maxn=100+10;
const int MOD=1e6;

int d[maxn][maxn];

int main()
{
    int n,k;
    memset(d,0,sizeof(d));
    d[0][0]=1;
    for(int i=1;i<=100;i++)
        for(int j=0;j<=100;j++)
            for(int k=0;k<=j;k++)
                d[i][j]=(d[i][j]+d[i-1][j-k])%MOD;
    scanf("%d %d",&n,&k);
    while(n!=0||k!=0)
    {
        printf("%d\n",d[k][n]);
        scanf("%d %d",&n,&k);
    }
    return 0;
}
