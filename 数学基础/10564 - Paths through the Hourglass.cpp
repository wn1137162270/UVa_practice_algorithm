#include<cstdio>

int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    while(n!=0||s!=0)
    {
        for(int i=0;i<2*n-1;i++)
        scanf("%d %d",&n,&s);
    }
    return 0;
}
