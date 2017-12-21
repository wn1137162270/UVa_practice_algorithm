#include<cstdio>
#include<cmath>
#include<cstring>

const int maxk=50+5;

int prime[maxk],num[maxk];

int main()
{
    int n,sn,k,ans,np;
    scanf("%d",&n);
    while(n!=0)
    {
        np=n;
        sn=sqrt(n+0.5);k=0;
        memset(num,0,sizeof(num));
        for(int i=2;i<=sn;i++)
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
        if(n!=1)
        {
            prime[k]=n;
            num[k++]=1;
        }
        ans=1;
        for(int i=0;i<k;i++)
            ans*=2*num[i]+1;
        ans=ans/2+1;
        printf("%d %d\n",np,ans);
        scanf("%d",&n);
    }
    return 0;
}
