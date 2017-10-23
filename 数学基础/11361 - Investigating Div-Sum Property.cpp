#include<cstdio>
#include<cstring> 

const int maxn=10;
const int maxm=100;

int d[maxn][maxm][maxm],pow10[maxn],k;

int dp(int i,int m1,int m2)
{
	int &ans=d[i][m1][m2];
	if(i==0)
	{
		if(m1==0&&m2==0)
			return 1;
		else
			return 0;
	}
	if(ans>=0)
		return ans;
	ans=0;
	for(int j=0;j<10;j++)
		ans+=dp(i-1,(m1+k-j%k)%k,(m2+k-(pow10[i-1]*j)%k)%k);
	return ans;
}

int get_sum(int x)
{
	int tx=x,dn=0,num=0,i=0,c,ans=0,digit=0;
	while(tx!=0)
	{
		tx/=10;
		dn++;
	}
	while(num!=x)
	{
		c=dn-1-i;
		while(num/pow10[c]!=x/pow10[c])
		{
			ans+=dp(c,(k-digit%k)%k,(k-num%k)%k);
			num+=pow10[c];
			digit++; 
		}
		i++;
	}
	ans+=dp(0,(k-digit%k)%k,(k-num%k)%k);
	return ans;
}

int main()
{
	int t,a,b;
	pow10[0]=1;
	for(int i=1;i<maxn;i++)
		pow10[i]=pow10[i-1]*10;
	scanf("%d",&t);
	for(int kase=0;kase<t;kase++)
	{
		scanf("%d %d %d",&a,&b,&k);
		if(k>82)
			printf("0\n");
		else if(k==1)
			printf("%d\n",b-a+1);
		else
		{
			memset(d,-1,sizeof(d));
			printf("%d\n",get_sum(b)-get_sum(a-1));
		} 
	}
	return 0;
}
