#include<cstdio>

int main()
{
    int a,b,c;
    double ans;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        ans=(double)(a*b+b*(b-1))/((a+b)*(a+b-c-1));
        printf("%.5lf\n",ans);
    }
    return 0;
}
