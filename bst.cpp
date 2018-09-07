#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   node *left;
   node *right;
}*root;

class bst
{
   public:
    node *insert(node *root,int data)
   {
        if(root==NULL)
         {
             root=new node[1];
             root->data=data;
             root->left=NULL;
             root->right=NULL;
             return root;
         }
        if(root->data>data)
        {
             root->left=insert(root->left,data);
        }
        else if(root->data<data)
        {
             root->right=insert(root->right,data);
        }
        return root;
   }
   node *findmin(node *root)
   {
        node *temp=root;
	while(temp->left!=NULL)
	   temp=temp->left;
	return temp;
   }
   node *findmax(node *root)
   {
        node *temp;
        if(root->right==NULL)
        {
             temp=root;
        }
        else
        {
             findmax(root->right);
        }
   }
   node *delet(node *root,int data)
   {
        node *temp;
        if(root==NULL)
	{
	   cout<<"Element not found\n";
	   return NULL;
	}
	else if(data>root->data)
	{
              root->right=delet(root->right,data);
	}
	else if(data<root->data)
	{
              root->left=delet(root->left,data);
	}
	else
	{
	   if(root->left&&root->right)
	   {
               temp=this->findmin(root->right);
	       root->data=temp->data;
	       root->right=delet(root->right,root->data);
	   }
	   else 
           {
	       temp=root;
	       if(root->right==NULL)
		  root=root->left;
	       else
	          root=root->right;
	       delete temp;
	   }
	}
         return root;
   }
   void inorder(node *root)
   {
       if(root==NULL)
         return;
       else
       {
           inorder(root->left);
	   cout<<root->data<<endl;
	   inorder(root->right);
        }
   }
};

int main()
{
        bst t;
        node *ad,*root=NULL;
        root=t.insert(root,2);
	root=t.insert(root,4);
	root=t.insert(root,1);
        t.inorder(root);
        ad=t.findmin(root);
        cout<<ad->data<<endl;
        root=t.delet(root,2);
	t.inorder(root);
        root=t.insert(root,7);
        return 0;
}
                                                                                                                                                                                                                                                                                                           
