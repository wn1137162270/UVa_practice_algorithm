#include<cstdio>
#include<cstring>

const int maxn=16+1;

char s[maxn];
int weapon[1<<maxn],every[maxn];
long long d[1<<maxn];

int main()
{
    int t,n,origin,f,all;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d",&n);
        origin=0;
        scanf("%s",s);
        for(int i=0;i<n;i++)
            if(s[i]=='1')
                origin|=1<<i;
        memset(every,0,sizeof(every));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<n;j++)
                if(s[j]=='1')
                    every[i]|=1<<j;
        }
        all=1<<n;
        for(int i=0;i<all;i++)
        {
            weapon[i]=origin;
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                    weapon[i]|=every[j];
        }
        memset(d,0,sizeof(d));
        d[0]=1;
        for(int i=0;i<all;i++)
        {
            for(int j=0;j<n;j++)
                if((weapon[i]&(1<<j))&&!(i&(1<<j)))
                    d[i|(1<<j)]+=d[i];
        }
        printf("Case %d: %lld\n",kase+1,d[all-1]);
    }
    return 0;
}
