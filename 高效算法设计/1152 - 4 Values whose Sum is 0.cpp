#include<cstdio>
#include<cstring>

const int maxn=4000+10;
const int hashsize=1e8;

int a[maxn],b[maxn],c[maxn],d[maxn],sum[maxn*maxn],cnt[maxn*maxn];
int head[hashsize],next[maxn*maxn];
long long ans;

int hash(int x)
{
    return (x%hashsize+hashsize)%hashsize;
}

void insert(int x)
{
    int h=hash(sum[x]);
    int u=head[h];
    while(u)
    {
        if(sum[u]==sum[x])
        {
            cnt[u]++;
            return;
        }
        u=next[u];
    }
    next[x]=head[h];
    head[h]=x;
    cnt[x]++;
}

void find(int x)
{
    int h=hash(x);
    int u=head[h];
    while(u)
    {
        if(sum[u]==x)
        {
            ans+=cnt[u];
            return;
        }
        u=next[u];
    }
}

int main()
{
    int t,n,l;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
        l=0;
        memset(head,0,sizeof(head));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                sum[++l]=a[i]+b[j];
                insert(l);
            }
        ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                find(-c[i]-d[j]);
        printf("%lld\n",ans);
        if(kase!=t-1)
            printf("\n");
    }
    return 0;
}
