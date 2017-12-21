#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e4+10;
const int INF=1<<30;

int a[maxn],g[maxn],d[maxn],b[maxn],h[maxn],d2[maxn];

int main()
{
    int n,minn,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[n-1-i]=a[i];
        }
        for(int i=1;i<=n;i++)
            g[i]=INF;
        for(int i=0;i<n;i++)
        {
            int k=lower_bound(g+1,g+n+1,a[i])-g;
            d[i]=k;
            g[k]=a[i];
        }
        for(int i=1;i<=n;i++)
            h[i]=INF;
        for(int i=0;i<n;i++)
        {
            int k=lower_bound(h+1,h+n+1,b[i])-h;
            d2[i]=k;
            h[k]=b[i];
        }
        ans=0;
        for(int i=0;i<n;i++)
        {
            minn=min(d[i],d2[n-1-i]);
            ans=max(ans,minn*2-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
