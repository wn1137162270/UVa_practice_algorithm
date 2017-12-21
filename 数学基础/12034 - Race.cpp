#include<cstdio>
#include<cstring>

const int maxn=1000+10;
const int MOD=10056;

long long f[maxn],c[maxn][maxn];

int main()
{
    int t,n;
    memset(c,0,sizeof(c));
    for(int i=0;i<maxn;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
    memset(f,0,sizeof(f));
    f[0]=1;
    for(int i=1;i<maxn;i++)
        for(int j=1;j<=i;j++)
            f[i]=(f[i]+c[i][j]*f[i-j])%MOD;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",kase+1,f[n]);
    }
    return 0;
}
