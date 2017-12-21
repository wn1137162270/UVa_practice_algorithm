#include<cstdio>
#include<cstring>
#include<cmath>

const int maxn=1e4+10;

int res[maxn];

void add_factor(int n,int d)
{
    int ns=sqrt(n+0.5);
    for(int i=2;i<=ns;i++)
        while(n%i==0)
        {
            n/=i;
            res[i]+=d;
        }
    if(n>1)
        res[n]+=d;
}

void add_factorial(int n,int d)
{
    for(int i=1;i<=n;i++)
        add_factor(i,d);
}

int main()
{
    int p,q,r,s;
    double ans;
    while(scanf("%d %d %d %d",&p,&q,&r,&s)!=EOF)
    {
        memset(res,0,sizeof(res));
        add_factorial(p,1);
        add_factorial(q,-1);
        add_factorial(p-q,-1);
        add_factorial(r,-1);
        add_factorial(s,1);
        add_factorial(r-s,1);
        ans=1;
        for(int i=1;i<maxn;i++)
            ans*=pow(i,res[i]);
        printf("%.5lf\n",ans);
    }
    return 0;
}
