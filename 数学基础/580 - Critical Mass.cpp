#include<cstdio>
#include<cstring>

const int maxn=30+10;

int f[maxn];

int main()
{
    int t,n;
    f[0]=0;
    for(int i=1;i<=30;i++)
    {
        f[i]=f[i-1]*2;
        if(i==3)
            f[i]+=1;
        else if(i>=4)
        {
            t=i-4;
            f[i]+=(1<<t)-f[t];
        }
    }
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%d\n",f[n]);
        scanf("%d",&n);
    }
    return 0;
}
