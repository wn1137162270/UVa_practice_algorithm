#include<cstdio>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;

const int maxn=1000+10;

int f[maxn*maxn];

int pow_mod(int a,ull p,int n)
{
    int x,ans;
    if(p==0)
        return 1;
    x=pow_mod(a,p/2,n);
    ans=(long long)x*x%n;
    if(p%2==1)
        ans=(long long)ans*a%n;
    return ans;
}

int main()
{
    int t,n,m,num;
    ull a,b;
    scanf("%d",&t);
    f[0]=0;f[1]=1;
    for(int kase=0;kase<t;kase++)
    {
        scanf("%llu %llu %d",&a,&b,&n);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        for(int i=2;;i++)
        {
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==1&&f[i-1]==0)
            {
                m=i;
                break;
            }
        }
        m--;
        a%=(ull)m;
        num=pow_mod(a,b,m);
        printf("%d\n",f[num]);
    }
    return 0;
}
