#include<cstdio>
#include<cstring>

const int maxl=1e6+10;

char s1[maxl],s2[maxl];

int main()
{
    int len1,len2;
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int j=0;
        len1=strlen(s1);
        len2=strlen(s2);
        for(int i=0;i<len2;i++)
        {
            if(s2[i]==s1[j])
                j++;
            if(j==len1)
                break;
        }
        if(j==len1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
