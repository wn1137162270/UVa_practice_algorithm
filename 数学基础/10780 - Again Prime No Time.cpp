#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxk=20+5;
const int INF=1<<30;

int prime[maxk],num[maxk],have[maxk];

int main()
{
    int t,m,n,sm,k,ti,minn;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&m,&n);
        sm=sqrt(m+0.5);k=0;
        memset(num,0,sizeof(num));
        for(int i=2;i<=sm;i++)
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
        if(m!=1)
        {
            prime[k]=m;
            num[k++]=1;
        }
        memset(have,0,sizeof(have));
        for(int i=2;i<=n;i++)
        {
            ti=i;
            for(int j=0;j<k;j++)
                if(ti%prime[j]==0)
                {
                    while(ti%prime[j]==0)
                    {
                        ti/=prime[j];
                        have[j]++;
                    }
                }
        }
        minn=INF;
        for(int i=0;i<k;i++)
            minn=min(minn,have[i]/num[i]);
        printf("Case %d:\n",kase+1);
        if(minn==0)
            printf("Impossible to divide\n");
        else
            printf("%d\n",minn);
    }
    return 0;
}
