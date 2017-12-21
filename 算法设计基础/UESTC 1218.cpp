#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1000+10;

int a[maxn],v[maxn];
long long d[2][4*maxn][3];

int main()
{
    int t,n,l,cur;
    long long ans;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&n,&l);
        l*=2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i],&v[i]);
            a[i]*=2;
        }
        memset(d[0],0,sizeof(d[0]));
        cur=0;
        for(int i=1;i<=n;i++)
        {
            cur^=1;
            d[cur][0][0]=0;
            d[cur][0][1]=0;
            d[cur][0][2]=0;
            for(int j=1;j<=l;j++)
            {
                d[cur][j][2]=d[1^cur][j][2];
                d[cur][j][1]=d[1^cur][j][1];
                d[cur][j][0]=d[1^cur][j][0];
                if(j-a[i]/2>=0)
                {
                    d[cur][j][2]=max(d[cur][j][2],d[1^cur][j-a[i]/2][1]+v[i]);
                    d[cur][j][1]=max(d[cur][j][1],d[1^cur][j-a[i]/2][0]+v[i]);
                }
                if(j-a[i]>=0)
                {
                    d[cur][j][2]=max(d[cur][j][2],d[1^cur][j-a[i]][2]+v[i]);
                    d[cur][j][1]=max(d[cur][j][1],d[1^cur][j-a[i]][1]+v[i]);
                    d[cur][j][0]=max(d[cur][j][0],d[1^cur][j-a[i]][0]+v[i]);
                }
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,(long long)v[i]);
        ans=max(ans,d[cur][l][1]);
        ans=max(ans,d[cur][l][2]);
        printf("Case #%d: %lld\n",kase+1,ans);
    }
    return 0;
}
