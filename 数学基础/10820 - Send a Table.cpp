#include<cstdio>
#include<cstring>

const int maxn=5*1e4+10;

int phi[maxn],num[maxn];

void phi_table()
{
    memset(phi,0,sizeof(phi));
    phi[1]=1;
    for(int i=2;i<maxn;i++)
        if(!phi[i])
            for(int j=i;j<maxn;j+=i)
            {
                if(!phi[j])
                    phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
}

int main()
{
    int n;
    phi_table();
    num[1]=1;num[2]=1;
    for(int i=3;i<maxn;i++)
        num[i]=num[i-1]+phi[i];
    for(int i=2;i<maxn;i++)
        num[i]=num[i]*2+1;
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%d\n",num[n]);
        scanf("%d",&n);
    }
    return 0;
}
