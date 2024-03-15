//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
public:
    Node* reverse(Node* head)
    {
        Node* prevPtr=NULL;
        Node* currPtr=head;
        Node* nextPtr;
        while(currPtr!=NULL)
        {
            nextPtr=currPtr->next;
            currPtr->next=prevPtr;
            prevPtr=currPtr;
            currPtr=nextPtr;
        }
        return prevPtr;
    }
    Node* merge(Node* l1, Node* l2) 
    {
        Node* dummy=new Node(-1);
        Node* tail =dummy;
        while (l1 && l2) 
        {
            if (l1->data < l2->data) 
            {
                tail->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
    void sort(Node **head) 
    {
        
         Node* odd=*head;
         Node* even=(*head)->next;
         Node* evenStart=even;
         while(even->next!=NULL)
         {
             odd->next=even->next;
             odd=odd->next;
             even->next=odd->next;
             if(odd->next!=NULL)
             {
                even=even->next;
             }
         }
         odd->next = nullptr;
         Node* newHead = reverse(evenStart);
         *head = merge(*head, newHead);
         
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends