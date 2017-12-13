/*Submitted By:- Waqas Hamid*/
/*Leetcode Nick : beginner007*/
/*Waqas Hamid on Interviewbit*/

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
#define rip freopen("input.txt","r",stdin);
#define wop freopen("output.txt","w",stdout);
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18

using namespace std;


int main()
{
    int n;
    cin>> n;
    stack<int> s;
    int i;
    int a[n+1];
    for(i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    s.push(a[0]);
    int next = 0;
    map<int,int> m;
    for(i = 1 ; i < n ;i++)
    {
        next = a[i];
        if(s.top() < next)
        {
            while(!s.empty() && s.top() < next)
            {
                int element = s.top();
                s.pop();
                m[element] = next;
            }
        }
        s.push(next);
    }
    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        m[element] = -1;
    }
    for(i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<" "<<m[a[i]]<<endl;
    }
    return 0;
}
