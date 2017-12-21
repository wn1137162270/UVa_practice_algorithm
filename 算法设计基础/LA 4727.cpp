#include<cstdio>

const int maxn=500000+10;

int f1[maxn],f2[maxn],f3[maxn];

int remain(int n,int a,int b)
{
    for(int i=0;i<n;i++)
        if(i!=a&&i!=b)
            return i;
}

int main()
{
    int t,n,k;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&n,&k);
        f1[1]=0;
        f1[2]=(f1[1]+k)%2;
        f2[2]=remain(2,f1[2],-1);
        f1[3]=(f1[2]+k)%3;
        f2[3]=(f2[2]+k)%3;
        f3[3]=remain(3,f1[3],f2[3]);
        for(int i=4;i<=n;i++)
        {
            f1[i]=(f1[i-1]+k)%i;
            f2[i]=(f2[i-1]+k)%i;
            f3[i]=(f3[i-1]+k)%i;
        }
        printf("%d %d %d\n",f3[n]+1,f2[n]+1,f1[n]+1);
    }
    return 0;
}
