#include<cstdio>
#include<cstring>
#include<cmath>

const int maxk=50+10;

int prime[maxk],num[maxk],res[maxk];

int main()
{
    int n,k,kase=0;
    long long ans;
    scanf("%d",&n);
    while(n!=0)
    {
        memset(num,0,sizeof(num));
        int ns=sqrt(n+0.5);k=0;
        for(int i=2;i<=ns;i++)
            if(n%i==0)
            {
                prime[k]=i;
                while(n%i==0)
                {
                    n/=i;
                    num[k]++;
                }
                k++;
            }
        if(n>1)
        {
            prime[k]=n;
            num[k++]=1;
        }
        ans=0;
        for(int i=0;i<k;i++)
        {
            res[i]=1;
            for(int j=0;j<num[i];j++)
                res[i]*=prime[i];
            ans+=res[i];
        }
        printf("Case %d: ",++kase);
        if(k==0)
            printf("2\n");
        else if(k==1)
            printf("%lld\n",ans+1);
        else
            printf("%lld\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
