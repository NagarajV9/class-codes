#include<iostream>
using namespace std;



class avl
{
   struct node
   {
       int data;
       node *left;
       node *right;
       int height;
   };
   node *root;
   node *insert(int x,node *t)
   {
       if(t==NULL)
       {
          t=new node;
	  t->left=NULL;
	  t->right=NULL;
	  t->data=x;
	  t->height=0;
       }
       else if(x>t->data)
	{
	  t->right=insert(x,t->right);
	  if(height(t->right)-height(t->left)==2)
	  {
		if(x>t->right->data)
	            t=singleleftrotate(t);
	  	else
	            t=doubleleftrotate(t);
	  }
	}
	else if(x<t->data)
	{
	     t->left=insert(x,t->left);
	     if(height(t->left)-height(t->right)==2)
	     {
	          if(x<t->left->data)
			t=singlerightrotate(t);
		  else
	               t=doublerightrotate(t);
	     }
	}
        t->height=max(height(t->left),height(t->right))+1;
	return t;
   }
    node *singleleftrotate(node* &t)
    {
       node *temp=t->right;
	t->right=temp->left;
	temp->left=t;
	t->height=max(height(t->left),height(t->right))+1;
	temp->height=max(height(temp->right),t->height)+1;
	return temp;
     }
     node *singlerightrotate(node* &t)
	{
	   node *temp=t->left;
	   t->left=temp->right;
	   temp->right=t;
	   t->height=max(height(t->right),height(t->left))+1;
	   temp->height=max(height(temp->left),t->height)+1;
	    return temp;
	}
	node *doubleleftrotate(node* &t)
	{
	   t->right=singlerightrotate(t->right);
	   return singleleftrotate(t);
	}
	node *doublerightrotate(node* &t)
	{
	   t->left=singleleftrotate(t->left);
	   return singlerightrotate(t);
	}
	node *findmin(node *t)
	{
	   if(t==NULL)
	     return NULL;
	   else if(t->left==NULL)
	     return t;
	   else
             return findmin(t->left);
	}
	node *findmax(node *t)
	{
	   if(t==NULL)
	      return NULL;
	   if(t->right==NULL)
	     return t;
	   else
	     return findmax(t->right);
	}
	node *remove(int x,node *t)
	{
            node *temp;
	   if(t==NULL)
	       return NULL;
	   else if(x>t->data)
	   {
	       t->right=remove(x,t->right);
	   }
	   else if(x<t->data)
	   {
	       t->left=remove(x,t->left);
	   }
	   else if(t->right&&t->left)
	       {
	          temp=findmin(t->right);
	          t->data=temp->data;
	          t->right=remove(t->data,t->right);
	       }
	       else
	       {
	          temp=t;
	          if(t->right==NULL)
	              t=t->left;
	          else
	              t=t->right;
	          delete temp;
	        }

	   }
	   if(t==NULL)
	     return t;
	   t->height=max(height(t->left),height(t->right))+1;
	
	   if(height(t->left)-height(t->right)==2)
	   {
	      if(height(t->left->left)-height(t->left->right)==1)
	      {
	         return singleleftrotate(t);
	      }
	      else
	          return doubleleftrotate(t);
	   }
	  else if(height(t->right)-height(t->left)==2)
	  {
	      if(height(t->right->right)-height(t->right->left)==1)
	          return singlerightrotate(t);
	      else
	          return doublerightrotate(t);
	  }
	  return t;
	}
	int height(node *t)
	{
	    return (t==NULL?-1:t->height);
	}
	void inorder(node *t)
	{
	   if(t==NULL)
	     return;
	   else
	   {
	      inorder(t->left);
	      cout<<t->data<<" ";
	      inorder(t->right);
	   }
	}
	public:
	avl()
	{
	   root=NULL;
	}
	void insert(int x)
	{
	   root=insert(x,root);
	}
	void remove(int x)
	{
	   root=remove(x,root);
	}
	void display()
	{
	   inorder(root);
	   cout<<endl;
	}
};

int main()
{
  avl t;
  t.insert(2);
  t.insert(5);
  t.insert(1);
  t.insert(6);
  t.insert(10);
  t.insert(29);
  t.insert(89);
  t.insert(3);
  t.insert(39);
  t.insert(7);
  t.display();
  t.remove(5);
  t.remove(89);
  t.remove(3);
  t.remove(29);
  /*t.remove(6);*/
  t.display();
  return 0;
}
