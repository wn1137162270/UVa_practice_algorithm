#include<cstdio>
#include<algorithm>
using namespace std;

const int c[10]={6,2,5,5,4,5,6,3,7,6};
const int maxn=100+10;
const int maxm=3000+10;
const int INF=1<<30;

int d[maxn/2][maxm],ini[maxn/2][10],ans[maxn/2];

int main()
{
    int n,m,w,answ,t,first,kase=0;
    while(scanf("%d %d",&n,&m)==2)
    {
        w=(n-1)/2+1;
        for(int i=0;i<=w;i++)
            for(int j=0;j<m;j++)
                d[i][j]=INF;
        d[0][0]=0;
        for(int i=0;i<w;i++)
            for(int j=0;j<m;j++)
                if(d[i][j]!=INF)
                    for(int k=0;k<10;k++)
                        d[i+1][(j*10+k)%m]=min(d[i+1][(j*10+k)%m],d[i][j]+c[k]);
        answ=-1;
        for(int i=1;i<=w;i++)
            if(d[i][0]<=n)
                answ=i;
        printf("Case %d: ",++kase);
        if(answ==-1)
            printf("-1\n");
        else
        {
            for(int i=0;i<10;i++)
                ini[1][i]=i%m;
            for(int i=2;i<=answ;i++)
                for(int j=0;j<10;j++)
                    ini[i][j]=(ini[i-1][j]*10)%m;
            t=0;
            for(int i=answ;i>=1;i--)
                for(int j=9;j>=0;j--)
                    if(c[j]+d[i-1][(t+m-ini[i][j])%m]<=n)
                    {
                        ans[answ-i]=j;
                        t=(t+m-ini[i][j])%m;
                        n-=c[j];
                        break;
                    }
            first=1;
            for(int i=0;i<answ;i++)
            {
                if(!first)
                    printf("%d",ans[i]);
                else if(ans[i])
                {
                    printf("%d",ans[i]);
                    first=0;
                }
            }
            if(first)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}
