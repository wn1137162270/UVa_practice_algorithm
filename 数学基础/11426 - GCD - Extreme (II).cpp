#include<cstdio>
#include<cstring>

typedef long long ll;

const int maxn=4*1e6;

int phi[maxn+1];
ll f[maxn+1],s[maxn+1];

void phi_table()
{
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<=maxn;i++)
        if(!phi[i])
            for(int j=i;j<=maxn;j+=i)
            {
                if(!phi[j])
                    phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
}

void init_f()
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=maxn;i++)
        for(int j=2*i;j<=maxn;j+=i)
            f[j]+=(ll)phi[j/i]*i;
}

void init_s()
{
    s[2]=f[2];
    for(int i=3;i<=maxn;i++)
        s[i]=s[i-1]+f[i];
}

int main()
{
    int n;
    phi_table();
    init_f();
    init_s();
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%lld\n",s[n]);
        scanf("%d",&n);
    }
    return 0;
}
