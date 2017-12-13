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

struct node
{
	int data;
	struct node* left,*right;
};

int c[1000005];
int sz;
struct node* newnode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder_wrec(struct node* node)
{
	struct node *prev,*curr;
	if(node==NULL)
	return;
	curr=node;
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
		cout<<curr->data<<" ";
		curr=curr->right;
		}
		else
		{
			prev=curr->left;
			while(prev->right!=NULL&&prev->right!=curr)
			prev=prev->right;

			if(prev->right==NULL)
			{
			prev->right=curr;
			curr=curr->left;
			}

			else
			{
				prev->right=NULL;
				cout<<curr->data<<" ";
				curr=curr->right;
			}

		}

	}
}

void preorder_wrec(struct node* node)
{
	struct node *curr,*prev;
	curr=node;
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
		cout<<curr->data<<" ";
		curr=curr->right;
		}
		else
		{
			prev=curr->left;
			while(prev->right!=NULL&&prev->right!=curr)
			prev=prev->right;

			if(prev->right!=NULL)
			{
				prev->right=NULL;						//Diff from inorder
				curr=curr->right;
			}
			else
			{
				cout<<curr->data<<" ";
				prev->right=curr;
				curr=curr->left;
			}
		}

	}
}

void postorder_wrec(struct node* root)
{
	if(root == NULL)
		return;
	stack<struct node*> s;
	s.push(root);
	while (!s.empty())
	{
		node* temp = s.top();

		if(temp->right == NULL && temp->left == NULL)
		{
			cout<<temp->data<<" ";
			s.pop();
		}
		else
		{
			if(temp->right)
			{
				s.push(temp->right);
				//since this node is processed make is NULL
				temp->right =  NULL;
			}
			if(temp->left)
			{
				s.push(temp->left);
				//since this node is processed make is NULL
				temp->left = NULL;
			}
		}
	}
}


struct node* insert(int n)
{
	node*tree=NULL;
 	if(c[n]!=-1&&n<sz)
	 {
  	tree=(node*)malloc(sizeof(node));
  	tree->left=insert(2*n+1);
  	tree->data=c[n];
  	tree->right=insert(2*n+2);
 }
 return tree;
}


int main()
{
	int n,i;
	cin>>n;
	f(i,n)
	s(c[i]);
	sz=n;
	struct node* root=insert(0);
	cout<<"Inorder : \n";
	inorder_wrec(root);ent;
	cout<<"Preorder : \n";
	preorder_wrec(root);ent;
	cout<<"Postorder : \n";
	postorder_wrec(root);ent;
	return 0;
}
