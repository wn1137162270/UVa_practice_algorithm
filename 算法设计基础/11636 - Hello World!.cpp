#include<cstdio>

int main()
{
    int i,n,kase=0;
    scanf("%d",&n);
    while(n>0)
    {
        i=0;
        while((1<<i)<n)
            i++;
        printf("Case %d: %d\n",++kase,i);
        scanf("%d",&n);
    }
    return 0;
}
