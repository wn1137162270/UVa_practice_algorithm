#include<cstdio>

const int maxn=20+2;

int a[maxn],n,r;
double p[maxn],sum[maxn],total;

void dfs(int i,int num,double d)
{
    if(i==n)
    {
        if(num==r)
        {
            total+=d;
            for(int j=0;j<n;j++)
                if(a[j])
                    sum[j]+=d;
        }
        return;
    }
    a[i]=0;
    dfs(i+1,num,d*(1-p[i]));
    a[i]=1;
    dfs(i+1,num+1,d*p[i]);
}

int main()
{
    int kase=0;
    scanf("%d %d",&n,&r);
    while(n!=0||r!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%lf",&p[i]);
        total=0;
        for(int i=0;i<n;i++)
            sum[i]=0;
        dfs(0,0,1);
        printf("Case %d:\n",++kase);
        for(int i=0;i<n;i++)
            printf("%.6lf\n",sum[i]/total);
        scanf("%d %d",&n,&r);
    }
    return 0;
}

