/*Submitted By:- Waqas Hamid*/
/*Codechef Nick : beginner007*/

#include<bits/stdc++.h>
#define LL long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)


using namespace std;

LL dp[1001][1001];
LL coins[1001];

int main()
{
	LL total,n,i,j;
	sl(total);
	sl(n);
	f(i,n)
	sl(coins[i]);
	for(j=0;j<=total;j++)
	if(j%coins[0]==0)
	dp[0][j]=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<=total;j++)
		{
			if(j==0)
			dp[i][j]=1;
			if(j>=coins[i])
			dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[i-1][total]<<endl;
	return 0;
}
