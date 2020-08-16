
#include<iostream>
using namespace std;

template<typename T,typename F>
class node{
	private:
		T r;
		T d;
		F x;
		node<T,F> *left;
		node<T,F> *right;
		node<T,F> *parent;
	public:
		node(){
			left=NULL;
			right=NULL;
			parent=NULL;
			
		}
		int size=0;
		void setr(T y)
		{r=y;}
		T getr()
		{return r;}
		void setd(T y)
		{d=y;}
		T getd()
		{return d;}
		void setx(F y)
		{x=y;}
		F getx()
		{return x;}
		void setleft(node<T,F> *p)
		{left=p;}
		node<T,F> *getleft()
		{return left;}
		void setright(node<T,F> *q)
		{right=q;}
		node<T,F> *getright()
		{return right;}
		void setparent(node<T,F> *r)
		{parent=r;}
		node<T,F> *getparent()
		{return parent;}
		
};
template<typename T,typename F>
class avl{
	public:
		node<T,F> *root;
		avl()
		{
			root=new node<T,F>;
			root=NULL;
		}
		int search1(T r);
		int insert1(T r,T d,F x);
		int remove1(T r);
		int search2(F x);
		int insert2(T r,T d,F x);
		int remove2(F x);
		int height(node<T,F> *root);
		int height_diff(node<T,F> *q);
		int leftleft(node<T,F> *w);
		int leftright(node<T,F> *e);
		int rightright(node<T,F> *r);
		int rightleft(node<T,F> *t);
		int balance(node<T,F> *y);
		int countright(node<T,F> *q,F y);
		int countleft(node<T,F> *q,F y);
	};
template<typename T,typename F>
int avl<T,F>:: height(node<T,F> *q)  		// finds length of the path;
{  
    int h=0;
    if (q == NULL)  
        return 0;  
    else
    {  
        			
        int l_height = height(q->getleft());  
        int r_height = height(q->getright());  
        				
        if (l_height> r_height)  
             h=(l_height + 1);  
        else h=(r_height + 1);  
    } 
    return h; 
} 


template<typename T,typename F>             //calculating the difference between the height of left
int avl<T,F>::height_diff(node<T,F> *b)     // subtree an right subtree of a node  
{
	int balance_factor=height(b->getleft())-height(b->getright());
	return balance_factor;
}
template<typename T,typename F>
int avl<T,F>::leftleft(node<T,F> *z)      //does right roation inorder to rebalance the tree
{
	node<T,F> *n1=z;
	node<T,F> *y=z->getleft();
	node<T,F> *x=y->getleft();
	if(z->getparent()!=NULL)
	{
		 if(z->getparent()->getright()==z)
	        {
			z->getparent()->setright(y);
			y->setparent(z->getparent());
	        }
	        else
	        {
			z->getparent()->setleft(y);
			y->setparent(z->getparent());
	     	}
		if(y->getright()!=NULL)
		{
			z->setleft(y->getright());
			y->getright()->setparent(z);
		}
		else
			z->setleft(NULL);
		y->setright(z);
		z->setparent(y);
	}
	else
	{
		root=y;
		y->setparent(NULL);
		if(y->getright()!=NULL)
		{
			z->setleft(y->getright());
			y->getright()->setparent(z);
		}
		else
			z->setleft(NULL);
		y->setright(z);
		z->setparent(y);
	}
	if(z->getleft()!=NULL)
	{
		z->size=(z->size)-(y->size)+(z->getleft()->size);
		y->size=(x->size)+(z->size)+1;

	}
	else
	{
		z->size=(z->size)-(y->size);
		y->size=(x->size)+(z->size)+1;
	}
}
template<typename T,typename F>
int avl<T,F>::rightright(node<T,F> *z)           // does left roation inorde to rebalance the tree
{
	node<T,F> *n1=z;
	node<T,F> *y=z->getright();
	node<T,F> *x=y->getright();
	if(z->getparent()!=NULL)
	{
		 if(z->getparent()->getleft()==z)
	        {
			z->getparent()->setleft(y);
			y->setparent(z->getparent());
	        }
	        else
	        {
			z->getparent()->setright(y);
			y->setparent(z->getparent());
	     	}
		if(y->getleft()!=NULL)
		{
			z->setright(y->getleft());
			y->getleft()->setparent(z);
		}
		else
			z->setright(NULL);
		y->setleft(z);
		z->setparent(y);
	}
	else
	{
		root=y;
		y->setparent(NULL);
		if(y->getleft()!=NULL)
		{
			z->setright(y->getleft());
			y->getleft()->setparent(z);
		}
		else
			z->setright(NULL);
		y->setleft(z);
		z->setparent(y);
	}
	if(z->getright()!=NULL)
	{									//changes the size of the accorging to the roatation
		z->size=(z->size)-(y->size)+(z->getright()->size);
		y->size=(x->size)+(z->size)+1;
	}
	else
	{
		z->size=(z->size)-(y->size);
		y->size=(x->size)+(z->size)+1;
	}
}
template<typename T,typename F>
int avl<T,F>::leftright(node<T,F> *z)
{
	node<T,F> *n1=z;
	node<T,F> *y=z->getleft();
	node<T,F> *x=y->getright();
	z->setleft(x);
	x->setparent(z);
	if(x->getleft()!=NULL)
	{
		y->setright(x->getleft());
		x->getleft()->setparent(y);
	}
	else
		y->setright(NULL);
	x->setleft(y);
	y->setparent(x);
	if(y->getright()!=NULL)
	{
		y->size=(y->size)-(x->size)+(y->getright()->size);
		x->size=(x->size)-(y->getright()->size)+(y->size);
	}
	else
	{
		y->size=(y->size)-(x->size);
		x->size=(x->size)+(y->size);
	}
	leftleft(z);
}
template<typename T,typename F>
int avl<T,F>::rightleft(node<T,F> *z)
{
	node<T,F> *n1=z;
	node<T,F> *y=z->getright();
	node<T,F> *x=y->getleft();
	z->setright(x);
	x->setparent(z);
	if(x->getright()!=NULL)
	{
		y->setleft(x->getright());
		x->getright()->setparent(y);
	}
	else
		y->setleft(NULL);
	x->setright(y);
	y->setparent(x);
	if(y->getleft()!=NULL)
	{
		y->size=(y->size)-(x->size)+(y->getleft()->size);
		x->size=(x->size)-(y->getleft()->size)+(y->size);
	}
	else
	{
		y->size=(y->size)-(x->size);
		x->size=(x->size)+(y->size);
	}
	rightright(z);
}
template<typename T,typename F>         			 // depending upon the balance factor of unbalanced node
int avl<T,F>::balance(node<T,F> *z)     			 // calls different to roations to restore balancing
{
	if(height_diff(z)>1&&height_diff(z->getleft())==1)
	{
		leftleft(z); 
	}
	if(height_diff(z)<-1&&height_diff(z->getright())==-1)
	{
		rightright(z);
	}
	
	if(height_diff(z)>1&&height_diff(z->getleft())==-1)
	{
		leftright(z);
	}
	
	if(height_diff(z)<-1&&height_diff(z->getright())==1)
	{
		rightleft(z);
	}
}
template<typename T,typename F> 
int avl<T,F>::search2(F x)                       // searches the node having value equal to a given x coordinate
{
	node<T,F> *temp=root;
	while(temp!=NULL)
	{
		if(temp->getx()==x)
			return 1;
		else if(temp->getx()>x)
			temp=temp->getleft();
		else
			temp=temp->getright();
	}
	if(temp==NULL)
		return 0;
	return 0;
}


template <typename T,typename F>
int avl<T,F>::search1(T r)				// finds the node that stores registration 
							// number eqaul to the given r
{
	node<T,F> *temp=root;
	while(temp!=NULL)
	{
		if(temp->getr()==r)
			return 1;
		else if(temp->getr()>r)
			temp=temp->getleft();
		else
			temp=temp->getright();
	}
	if(temp==NULL)
		return 0;
	return 0;
}
template <typename T,typename F>
int avl<T,F>::insert2(T r,T d,F x)                      // inserts the node in the the tree which is balanced bst according to
{	
	node<T,F> *temp=root;                            // the x-coordinate of the cars
	//temp=root;
	node<T,F> *pre;
	node<T,F> *n=NULL;
	if(root==NULL)
	{
		n=new node<T,F>;
		n->setr(r);
		n->setx(x);
		n->setd(d);
		root=n;
		n->size++;
	}
	else
	{
		while(temp!=NULL)
		{
			pre=temp;
			if(temp->getx()>x)
				temp=temp->getleft();
			else
				temp=temp->getright();
		}
		n=new node<T,F>;
		n->setr(r);
		n->setd(d);
		n->setx(x);
		if(pre->getx()>x)
		{	pre->setleft(n);
			n->setparent(pre);
		}
		else
		{	pre->setright(n);
			n->setparent(pre);
		}
		node<T,F> *nd=n;
		while(nd!=NULL)
		{
			nd->size++;
			nd=nd->getparent();
		}

	}
	node<T,F> *temp1=n;						// checks balancing as a node is inserted
	while(temp1!=NULL)
	{
		int h=height_diff(temp1);
		if((h<-1) || (h>1)) 
		{
			balance(temp1);
			temp1=temp1->getparent();
		}
		else
			temp1=temp1->getparent();
	}
	return 1;
}

	
	
template <typename T,typename F>
int avl<T,F>::insert1(T r,T d,F x)                              // inserts the node in the the tree which is balanced bst according to
{	                                                        // the registration number of the car
	node<T,F> *temp=root;
	node<T,F> *pre;
	node<T,F> *n=NULL;
		if(root==NULL)
		{
			n=new node<T,F>;
			n->setr(r);
			n->setx(x);
			n->setd(d);
			root=n;
			n->size++;
		}
		else
		{
			while(temp!=NULL)
			{
				pre=temp;
				if(temp->getr()>r)
					temp=temp->getleft();
				else
					temp=temp->getright();
			}
			n=new node<T,F>;
			n->setr(r);
			n->setd(d);
			n->setx(x);
			if(pre->getr()>r)
			{	pre->setleft(n);
				n->setparent(pre);
			}
			else
			{	pre->setright(n);
				n->setparent(pre);
			}
			node<T,F> *nd=n;
			while(nd!=NULL)
			{                                               // stores the size of subtree rooted at a node
				nd->size++;
				nd=nd->getparent();
			}

		}
		node<T,F> *temp1=n;
		while(temp1!=NULL)					//after inserting the node , check whether parent is balanced or not
		{
			int h=height_diff(temp1);
			if((h<-1) || (h>1)) 
			{
				balance(temp1);
				temp1=temp1->getparent();
			}
			else
				temp1=temp1->getparent();
		}
		return 1;
}

template<typename T,typename F>
int avl<T,F>::remove2(F x)
{                                        // deletes a node from the tree which is a balanced bst in x coordinate of car           
	node<T,F> *pre=NULL;
	node<T,F> *p=NULL;
	node<T,F> *prev=NULL;
    if(search2(x)==0)
		return 0;
    else
    {
	node<T,F> *temp=root;
	
	node<T,F> *t;
	node<T,F> *pre;
	while(temp!=NULL)
	{
		
		//t=temp;
		if(temp->getx()==x)
		{	p=temp;
			break;
		}
		else if(temp->getx()>x)
		{
			temp=temp->getleft();
		}
		else
		{
			temp=temp->getright();
		}
	}
	if(p->getright()==NULL)
	{								//if the node to be deleted has no right subtree
		if(p->getparent()==NULL)
		{
			root=p->getleft();
			if(p->getleft()!=NULL)
			{
				p->setleft(NULL);
			}
			delete(p);
		}
		else
		{
			prev=p->getparent();
			pre=p->getparent();
			if(p->getparent()->getright()==p)
			{
				p->getparent()->setright(p->getleft());
				if(p->getleft()!=NULL)
				{
					p->getleft()->setparent(p->getparent());
					
				}
				delete(p);
			}
			else
			{
				p->getparent()->setleft(p->getleft());
				if(p->getleft()!=NULL)
				{
					p->getleft()->setparent(p->getparent());
				}
				delete(p);
			}
		}
	}
	else							// if the node to be deleted has a right subtree;
	{
		t=p->getright();
		while(t->getleft()!=NULL)
		{ 
			t=t->getleft();
		}
		pre=t->getparent();

		p->setr(t->getr());
		if(t->getparent()->getleft()==t)
		{
			t->getparent()->setleft(t->getright());
			if(t->getright()!=NULL)
			{
				t->getright()->setparent(t->getparent());
			}
			delete(t);
		}
		else
		{
			t->getparent()->setright(t->getright());
			if(t->getright()!=NULL)
			{
				t->getright()->setparent(t->getparent());
			}
			delete(t);
			
		}
	}

	

	while(pre!=NULL)				//after removing the node check travel up to the root and check 
	{                                                // whether each node is balanced or not
		int h=height_diff(pre);
		if((h<-1) || (h>1)) 
		{
			balance(pre);
			pre=pre->getparent();
		}
		else
		{
			pre=pre->getparent();
		}
	}
}
}
	
	

template<typename T,typename F>
int avl<T,F>::remove1(T r)
{                                               // deletes a node from the tree which is a balanced bst according to registration number  of car 
	node<T,F> *pre=NULL;
	node<T,F> *prev=NULL;
	node<T,F> *p=NULL;
	node<T,F> *q=NULL;
    if(search1(r)==0)
		return 0;
    else
    {
	node<T,F> *temp=root;
	
	node<T,F> *t;
	node<T,F> *pre;
	while(temp!=NULL)
	{
		
		if(temp->getr()==r)
		{	p=temp;
			break;
		}
		else if(temp->getr()>r)
		{
			temp=temp->getleft();
		}
		else
		{
			temp=temp->getright();
		}
	}
	q=temp;
	if(p->getright()==NULL)
	{
		if(p->getparent()==NULL)
		{
			root=p->getleft();
			if(p->getleft()!=NULL)
			{
				p->setleft(NULL);
			}
			delete(p);
		}
		else
		{
			pre=p->getparent();
			prev=p->getparent();
			if(p->getparent()->getright()==p)
			{
				p->getparent()->setright(p->getleft());
				if(p->getleft()!=NULL)
				{
					p->getleft()->setparent(p->getparent());
					delete(p);
				}
					
			}
			else
			{
				p->getparent()->setleft(p->getleft());
				if(p->getleft()!=NULL)
				{
					p->getleft()->setparent(p->getparent());
				}
				delete(p);
			}
		}
	}
	else
	{
		t=p->getright();
		while(t->getleft()!=NULL)
		{ 
			t=t->getleft();
		}
		pre=t->getparent();
		prev=t->getparent();
		p->setr(t->getr());
		if(t->getparent()->getleft()==t)
		{
			t->getparent()->setleft(t->getright());
			if(t->getright()!=NULL)
			{
				t->getright()->setparent(t->getparent());
			}
			delete(t);
		}
		else
		{
			t->getparent()->setright(t->getright());
			if(t->getright()!=NULL)
			{
				t->getright()->setparent(t->getparent());
			}
			delete(t);
		}
	}

	

	while(pre!=NULL)
	{

		int h=height_diff(pre);
		if((h<-1) || (h>1)) 
		{
			balance(pre);
			pre=pre->getparent();
		}
		else
		{
			pre=pre->getparent();
		}
	}
}
}
template<typename T,typename F>
int avl<T,F>::countright(node<T,F> *q,F y)
{
	int count=0;                                                    // counts no. of cars which are right to a 
	while(q!=NULL)                                                  // car having unique registration number
	{								// if value of node is greaater than the given node then 
									// count increases by thr size of right child of current node +1 and we see 	
		if(q->getx()>y)						// left child
		{							//if value of node is less than the given value we go the right child of node
			if(q->getright()!=NULL)
			{
				count=count+(q->getright()->size)+1;
			}
			else
				count=count+1;
			q=q->getleft();
		}
		else if(q->getx()<y)
			q=q->getright();
		else
		{	if(q->getright()!=NULL)
				count=count+q->getright()->size;
	
				q=q->getleft();
		}
	}
	return count;

}
template<typename T,typename F>
int avl<T,F>::countleft(node<T,F> *q,F y)
{
	int count=0;
	while(q!=NULL)                                                  // counts no. of cars which are left to a 
	{                                                               // car having unique registration number
		if(q->getx()<y)                                         // if value of node is less than the given node then 
		{							// count increases by thr size of left child of current node +1 and we see 
			if(q->getleft()!=NULL)				// right child
			{						//if value of node is less than the given value we go the left child of node
				count=count+(q->getleft()->size)+1;
			}
			else
				count=count+1;
			q=q->getright();
		}
		else if(q->getx()>y)
			q=q->getleft();
		else
		{	if(q->getleft()!=NULL)
				count=count+q->getleft()->size;
			//if(q->getleft!=NULL)
				q=q->getright();
		}
	}
	return count;

}
int main()
{

	float q,w,e,g,h,p;				//we make three avl trees 
	int r,d;					// one stores the registration number
	float x,t;					// second stores the x coordinate of cars going in left to right direction
	int a,b=0,c;					// third stores the x coordinate of cars going in right to left direction
	avl<int,float> highway;
	avl<int,float> card0;
	avl<int,float> card1;
	int i,n,j;
	cin>>n;
	for(i=0;i<n;i++)
	{	cin>>c;
		if(c==1)
		{
			cin>>r>>x>>t>>d;
			//cout<<endl;
			a=highway.search1(r);
			if(d==0)
				b=card0.search2(x+t);
			else
				c=card1.search2(x-t);
			
			
			
				if(a==0&&c==0)
				{
						highway.insert1(r,d,x-t);
						card1.insert2(r,d,x-t);
				}
				
				if(a==0&&b==0)
				{
						highway.insert1(r,d,x+t);
						card0.insert2(r,d,x+t);
				}
			

			
		}
		if(c==2)
		{
			cin>>r>>t;
			a=highway.search1(r);
				c=card1.search2(x-t);
			if(d==0)
			{
				if(a==0&&b==0)
				{
						highway.insert1(r,d,x+t);
						card0.insert2(r,d,x+t);
						
						//cout<<"inserted  0"<<endl;
				}
			}
			if(a==1)
			{
				node<int,float> *temp=highway.root;
				while(temp!=NULL)
				{
					if(temp->getr()==r)
						//return temp;
						break;
					else if(temp->getr()>r)
						temp=temp->getleft();
					else
						temp=temp->getright();
				
				}
				highway.remove1(temp->getr());
				if(temp->getd()==0)
				{
					card0.remove2(temp->getx());
				
				}
				else
				{
					card1.remove2(temp->getx());
			
				}
			}
				
			
		}
		if(c==3)
		{
			cin>>r>>t;
			node<int,float>*t;
			node<int,float> *temp=highway.root;
			node<int,float> *temp0=card0.root;
			node<int,float> *temp1=card1.root;
			while(temp!=NULL)
			{
				if(temp->getr()==r)
						//return temp;
					break;
				else if(temp->getr()>r)
					temp=temp->getleft();
				else
					temp=temp->getright();
			}
			if(temp->getd()==1)
			{	
				while(temp1!=NULL)
				{
				if(temp1->getx()==temp->getx())
						//return temp;
					break;
				else if(temp1->getx()>temp->getx())
					temp1=temp1->getleft();
				else
					temp1=temp1->getright();
				}
				if(temp1->getparent()!=NULL)
				{
					if(temp1->getparent()->getleft()==temp)
					{
						if(temp1->getleft()!=NULL)
						{
							t=temp1->getleft();
							while(t->getright()!=NULL)
							{
								t=t->getright();
							}
							cout<<t->getr();
						}
					}
					else
					{
						cout<<temp1->getparent()->getr();
					}
				}
			}
			if(temp->getd()==0)
			{	
				while(temp0!=NULL)
				{
				if(temp0->getx()==temp->getx())
						//return temp;
					break;
				else if(temp0->getx()>temp->getx())
					temp0=temp0->getleft();
				else
					temp0=temp0->getright();
				}
				if(temp0->getparent()!=NULL)
				{
					if(temp0->getparent()->getleft()==temp0)
					{
						if(temp0->getleft()!=NULL)
						{
							t=temp0->getleft();
							while(t->getright()!=NULL)
							{
								t=t->getright();
							}
							cout<<t->getr();
						}
					}
					else
					{
						cout<<temp0->getparent()->getr();
					}
				}
			}
		}
		if(c==4)
		{
			cin>>r>>t;
			node<int,float>*t;
			node<int,float> *temp=highway.root;
			node<int,float> *temp0=card0.root;
			node<int,float> *temp1=card1.root;
			while(temp!=NULL)
			{
				if(temp->getr()==r)
						//return temp;
					break;
				else if(temp->getr()>r)
					temp=temp->getleft();
				else
					temp=temp->getright();
			}
			if(temp->getd()==1)
			{	
				while(temp1!=NULL)
				{
				if(temp1->getx()==temp->getx())
						//return temp;
					break;
				else if(temp1->getx()>temp->getx())
					temp1=temp1->getleft();
				else
					temp1=temp1->getright();
				}
				if(temp1->getparent()!=NULL)
				{
					if(temp1->getparent()->getright()==temp)
					{
						if(temp1->getright()!=NULL)
						{
							t=temp1->getright();
							while(t->getleft()!=NULL)
							{
								t=t->getleft();
							}
							cout<<t->getr();
						}
					}
					else
					{
						cout<<temp1->getparent()->getr();
					}
				}
			}
			if(temp->getd()==0)
			{	
				while(temp0!=NULL)
				{
				if(temp0->getx()==temp->getx())
						//return temp;
					break;
				else if(temp0->getx()>temp->getx())
					temp0=temp0->getleft();
				else
					temp0=temp0->getright();
				}
				if(temp0->getparent()!=NULL)
				{
					if(temp0->getparent()->getright()==temp0)
					{
						if(temp0->getright()!=NULL)
						{
							t=temp0->getright();
							while(t->getleft()!=NULL)
							{
								t=t->getleft();
							}
							cout<<t->getr();
						}
					}
					else
					{
						cout<<temp0->getparent()->getr();
					}
				}
			}
		}
	
		if(c==5)
		{
			cin>>r>>t;
			node<int,float> *temp=highway.root;
			node<int,float> *temp0=card0.root;
			node<int,float> *temp1=card1.root;
			while(temp!=NULL)
			{
				if(temp->getr()==r)
						//return temp;
					break;
				else if(temp->getr()>r)
					temp=temp->getleft();
				else
					temp=temp->getright();
			}
			p=temp->getx();
			g=card1.countleft(temp1,p);
			h=card0.countleft(temp0,p);
			if(g+h>0)
				cout<<g+h<<endl;
			else
				cout<<"-1"<<endl;
		}						

		if(c==6)
		{
			cin>>r>>t;
			node<int,float> *temp=highway.root;
			node<int,float> *temp0=card0.root;
			node<int,float> *temp1=card1.root;
			while(temp!=NULL)
			{
				if(temp->getr()==r)
						//return temp;
					break;
				else if(temp->getr()>r)
					temp=temp->getleft();
				else
					temp=temp->getright();
			}
			p=temp->getx();
			g=card1.countright(temp1,p);
			h=card0.countright(temp0,p);
			if(g+h>0)
				cout<<g+h<<endl;
			else
				cout<<"-1"<<endl;
		}						

				

	}


}







