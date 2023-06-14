//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program



/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   Node* tmp=root,*tmp2,*tmp3;
   
   while(tmp->next)
   {
       tmp2=tmp->next;
       tmp->next=tmp->next->next;
       tmp3=tmp;
       tmp2->next=NULL;
       while(tmp2&&tmp3)
       {
           if(tmp3->bottom&&tmp3->data<tmp2->data&&tmp3->bottom->data>tmp2->data)
           {
               Node* t=tmp3->bottom,*t2;
               tmp3->bottom=tmp2;
               t2=tmp2->bottom;
               tmp2->bottom=t;
               tmp2=t2;
               tmp3=tmp3->bottom;
           }
           else if(!tmp3->bottom)
           {
               tmp3->bottom=tmp2;
               break;
           }
           else
           {
               tmp3=tmp3->bottom;
           }
       }
       
    //   Node* p=root;
    //   while(p)
    //   {
    //       cout<<p->data<<" ";
    //       p=p->bottom;
    //   }
    //   cout<<endl;
   }
   return root;
}