/*Submitted By:- Waqas Hamid*/
/*Codechef Nick : beginner007*/
/*Leetcode Nick : beginner007*/
/*Topcoder Nick : beginner007*/
/*Codeforces Nick : beginner7*/

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
#define pb push_back
#define mp make_pair

using namespace std;

stack<LL> st;

int main()
{
	string s;
	cin>>s;
	LL len=s.length(),i;
	for(i=0;i<len;i++)
	{
		if(s[i]=='('||s[i]=='{'||s[i]=='[')
		st.push(s[i]);
		else
		{
			switch(s[i])
			{
				case ')': if(st.top()!='(') {cout<<"Invalid Expression\n"; return 0;} st.pop(); break;
				case '}': if(st.top()!='{') {cout<<"Invalid Expression\n"; return 0;} st.pop(); break;
				case ']': if(st.top()!='[') {cout<<"Invalid Expression\n"; return 0;} st.pop(); break;
			}
		}
	}
	if(st.empty())
	cout<<"Valid Expression\n";
	else
	cout<<"Invalid Expression\n";
}
