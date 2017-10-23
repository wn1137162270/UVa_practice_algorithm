#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=5000+10;
const int maxl=26;

char s1[maxn],s2[maxn];
int start1[maxl],end1[maxl],start2[maxl],end2[maxl],d[maxn][maxn],f[maxn][maxn];

void init(char *s,int len,int start[],int end[])
{
	memset(start,0,sizeof(int)*26);
	memset(end,0,sizeof(int)*26);
	for(int i=1;i<=len;i++)
	{
		if(start[s[i]-'A']==0)
			start[s[i]-'A']=i;
		end[s[i]-'A']=i;
	}
}

bool judge_start(char *s,int *start1,int *start2,int i,int j)
{
	return start1[s[i]-'A']==i&&(start2[s[i]-'A']>j||start2[s[i]-'A']==0);
}

bool judge_end(char *s,int *end1,int *end2,int i,int j)
{
	return end1[s[i]-'A']==i&&(end2[s[i]-'A']<=j||end2[s[i]-'A']==0);
}

int main()
{
	int t,len1,len2;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		len1=strlen(s1+1);
		len2=strlen(s2+1);
		init(s1,len1,start1,end1);
		init(s2,len2,start2,end2);
		f[0][0]=0;
		for(int j=1;j<=len2;j++)
		{
			if(judge_start(s2,start2,start1,j,0)&&!judge_end(s2,end2,end1,j,0))
				f[0][j]=f[0][j-1]+1;
			else if(judge_end(s2,end2,end1,j,0)&&!judge_start(s2,start2,start1,j,0))
				f[0][j]=f[0][j-1]-1;
			else
				f[0][j]=f[0][j-1];
		}
		for(int i=1;i<=len1;i++)
			for(int j=0;j<=len2;j++)
			{
				if(judge_start(s1,start1,start2,i,j)&&!judge_end(s1,end1,end2,i,j))
					f[i][j]=f[i-1][j]+1;
				else if(judge_end(s1,end1,end2,i,j)&&!judge_start(s1,start1,start2,i,j))
					f[i][j]=f[i-1][j]-1;
				else
					f[i][j]=f[i-1][j];
			}
		d[0][0]=0;
		for(int j=1;j<=len2;j++)
			d[0][j]=d[0][j-1]+f[0][j-1];
		for(int i=1;i<=len1;i++)
			d[i][0]=d[i-1][0]+f[i-1][0];
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++)
				d[i][j]=min(d[i-1][j]+f[i-1][j],d[i][j-1]+f[i][j-1]);
		printf("%d\n",d[len1][len2]);
	}
	return 0;	
} 
