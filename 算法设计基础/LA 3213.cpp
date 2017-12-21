#include<cstdio>
#include<cstring>

const int maxl=100+10;

char s1[maxl],s2[maxl];
int tb[26],tb2[26],num[maxl];

int main()
{
    int len,flag;
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        memset(tb,0,sizeof(tb));
        memset(tb2,0,sizeof(tb2));
        len=strlen(s1);
        for(int i=0;i<len;i++)
        {
            tb[s1[i]-'A']++;
            tb2[s2[i]-'A']++;
        }
        memset(num,0,sizeof(num));
        for(int i=0;i<26;i++)
            num[tb[i]]++;
        for(int i=0;i<26;i++)
            num[tb2[i]]--;
        flag=0;
        for(int i=0;i<maxl;i++)
            if(num[i]!=0)
            {
                flag=1;
                break;
            }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
