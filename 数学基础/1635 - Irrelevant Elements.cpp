#include<cstdio>
#include<cstring>
#include<cmath>

const int maxn=1e5+10;
const int maxk=50+10;

int prime[maxk],num[maxk],res[maxk],ok[maxn],k;

void add_factor(int n,int d)
{
    for(int i=0;i<k;i++)
        while(n%prime[i]==0)
        {
            n/=prime[i];
            res[i]+=d;
        }
}

int main()
{
    int n,m,cnt,flag,first;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(num,0,sizeof(num));
        int ms=sqrt(m+0.5);k=0;
        for(int i=2;i<=ms;i++)
            if(m%i==0)
            {
                prime[k]=i;
                while(m%i==0)
                {
                    m/=i;
                    num[k]++;
                }
                k++;
            }
        if(m>1)
        {
            prime[k]=m;
            num[k++]=1;
        }
        memset(res,0,sizeof(res));
        memset(ok,0,sizeof(ok));
        cnt=0;
        for(int i=1;i<n;i++)
        {
            add_factor(n-i,1);
            add_factor(i,-1);
            flag=0;
            for(int i=0;i<k;i++)
                if(res[i]<num[i])
                {
                    flag=1;
                    break;
                }
            if(!flag)
            {
                ok[i]=1;
                cnt++;
            }
        }
        printf("%d\n",cnt);
        first=1;
        for(int i=0;i<n;i++)
            if(ok[i])
            {
                if(first)
                {
                     printf("%d",i+1);
                     first=0;
                }
                else
                    printf(" %d",i+1);
            }
        printf("\n");
    }
    return 0;
}
