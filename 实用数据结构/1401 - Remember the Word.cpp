#include<cstdio>
#include<cstring>

const int maxm=300000+10;
const int maxn=4000+10;
const int maxw=100+5;
const int maxnode=maxn*maxw;
const int sigma_size=26;
const int mod=20071027;

int num[maxw];

struct Trie
{
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	int get_index(char c){return c-'a';}
	
	void init()
	{
		for(int i=0;i<maxnode;i++)
			memset(ch[i],0,sizeof(ch[i]));
		memset(val,0,sizeof(val));
		sz=1;
	}
	
	void insert(char *s,int v)
	{
		int len=strlen(s),u=0;
		for(int i=0;i<len;i++)
		{
			int index=get_index(s[i]);
			if(!ch[u][index])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;
				ch[u][index]=sz++;
			}
			u=ch[u][index];
		}
		val[u]=v;
	}
	
	void query(char *s,int start,int len)
	{
		int u=0;
		memset(num,0,sizeof(num));
		for(int i=start;i<len;i++)
		{
			int c=get_index(s[i]);
			if(!ch[u][c])
				break;
			u=ch[u][c];
			if(val[u]==1)
				num[i-start+1]=1;
		}
	}
};

Trie trie;
int dp[maxm];
char s[maxm],word[maxw];

int main()
{
	int n,len,*num,m=0;
	while(scanf("%s",s)!=EOF)
	{
		trie.init();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",word);
			trie.insert(word,1);
		}
		memset(dp,0,sizeof(dp));
		len=strlen(s);
		dp[len]=1;
		for(int i=len-1;i>=0;i--)
		{
			trie.query(s,i,len);
			for(int j=1;j<maxw;j++)
				if(num[j]==1)
					dp[i]=(dp[i]+dp[i+j])%mod;
		}
		printf("Case %d: %d\n",++m,dp[0]);
	}
	return 0;
}
