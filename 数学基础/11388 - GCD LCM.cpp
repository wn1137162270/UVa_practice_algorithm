#include<cstdio>

int main()
{
    int t,gcd,lcm;
    scanf("%d",&t);
    for(int kase=0;kase<t;kase++)
    {
        scanf("%d %d",&gcd,&lcm);
        if(lcm%gcd!=0)
            printf("-1\n");
        else
            printf("%d %d\n",gcd,lcm);
    }
    return 0;
}
