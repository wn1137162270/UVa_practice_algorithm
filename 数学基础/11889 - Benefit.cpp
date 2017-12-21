#include<cstdio>
#include<cmath>
#include<cstring>

const int maxk=50+5;

int prime[maxk],num[maxk];

int main()
{
    int t,a,c,sa,sc,ka,kc,numa,ans;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&a,&c);
        if(c%a!=0)
        {
            printf("NO SOLUTION\n");
            continue;
        }
        sc=sqrt(c+0.5);kc=0;
        memset(num,0,sizeof(num));
        for(int i=2;i<=sc;i++)
        {
            if(c%i==0)
            {
                prime[kc]=i;
                while(c%i==0)
                {
                    c/=i;
                    num[kc]++;
                }
                kc++;
            }
        }
        if(c!=1)
        {
            prime[kc]=c;
            num[kc++]=1;
        }
        sa=sqrt(a+0.5);ka=0;
        for(int i=2;i<=sa;i++)
        {
            if(a%i==0)
            {
                numa=0;
                while(prime[ka]!=i)
                    ka++;
                while(a%i==0)
                {
                    a/=i;
                    numa++;
                }
                if(numa==num[ka])
                    num[ka]=0;
            }
        }
        if(a!=1)
        {
            while(prime[ka]!=a)
                ka++;
            if(num[ka]==1)
                num[ka]=0;
        }
        ans=1;
        for(int i=0;i<kc;i++)
        {
            if(num[i]!=0)
            {
                while(num[i]--)
                    ans*=prime[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
