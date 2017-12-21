#include<cstdio>
#include<cstring>

const int maxn=100+10;

char s[maxn];

int main()
{
    int a,b,len,res;
    while(scanf("%s",s)!=EOF)
    {
        a=0;b=0;
        len=strlen(s);
        for(int i=0;i<len;i++)
            if(s[i]=='0')
            {
                b++;
                if(s[(i+1)%len]=='0')
                    a++;
            }
        res=a*len-b*b;
        if(res>0)
            printf("SHOOT\n");
        else if(res==0)
            printf("EQUAL\n");
        else
            printf("ROTATE\n");
    }
    return 0;
}
