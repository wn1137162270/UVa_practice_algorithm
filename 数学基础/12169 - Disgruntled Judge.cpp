#include<cstdio>

typedef long long ll;

const int maxt=100+10;
const int MOD=1e4+1;

int f[2*maxt];

void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)
    {
        d=a;x=1;y=0;
    }
    else
    {
         ex_gcd(b,a%b,d,y,x);
         y-=(a/b)*x;
    }
}

ll inverse(ll a,ll n)
{
    ll d,x,y;
    ex_gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

int main()
{
    int t,res,flag,inv,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        scanf("%d",&f[2*i]);
    for(int a=0;a<MOD;a++)
    {
        inv=inverse(1+a,MOD);
        if(inv==-1)
            continue;
        f[1]=((f[2]+a*f[0])%MOD*inv)%MOD;
        b=((f[1]-a*f[0])%MOD+MOD)%MOD;
        flag=0;
        for(int i=0;i<t;i++)
        {
            f[2*i+1]=(a*f[2*i]+b)%MOD;
            res=(a*f[2*i+1]+b)%MOD;
            if(i!=t-1&&res!=f[2*i+2])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
            break;
    }
    for(int i=0;i<t;i++)
        printf("%d\n",f[2*i+1]);
    return 0;
}
