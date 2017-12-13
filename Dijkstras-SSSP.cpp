//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E*log(V))

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
#define INF INT_MAX

using namespace std;


const int sz=10001;
vector<pair<int,int> > adj[sz];
int dis[sz];
bool vis[sz]={0};

class comparator
{
public:
bool operator ()(const pair<int, int>&p1 ,const pair<int, int>&p2)
{
return p1.second>p2.second;
}
};
void Dijkstra(int source, int n)
{
    for(int i=0;i<sz;i++)
        dis[i]=INF;

    priority_queue<pair<int,int> ,vector<pair<int,int> >, comparator> pq;

    pq.push(make_pair(source,dis[source]=0));

    while(!pq.empty())
    {
        pair<int, int> curr=pq.top();

        pq.pop();
        int v=curr.first,w=curr.second;

        if(vis[v])
        continue;
        vis[v]=true;
        for(int i=0;i<adj[v].size();i++)
            if(!vis[adj[v][i].first] && adj[v][i].second+w<dis[adj[v][i].first])

                pq.push(make_pair(adj[v][i].first,(dis[adj[v][i].first]=adj[v][i].second+w)));

    }
}

int main()
{
    int n,m,x,y,w;

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }

    int source;
    cin>>source;
    Dijkstra(source,n);
    for(int i=1;i<=n;i++)
    dis[i]!=INF&&dis[i]!=0? cout<<dis[i]<<" " : cout<<"-1 ";
    return 0;
}
