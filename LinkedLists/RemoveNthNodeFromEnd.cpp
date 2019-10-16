#include <bits/stdc++.h>

using namespace std;

struct LinkedList
{

    struct Node
    {
        int _val;
        struct Node *pNext;
        Node(int val)
        {
            _val = val;
            pNext = NULL;
        }
    };

    Node *head;

    Node *push(int newData)
    {
        Node *temp = new Node(newData);
        temp->pNext = head;
        head = temp;
        return head;
    }

    Node *deleteNthNode(int n) 
    {
        Node *first = head;
        Node *sec = head;

        for (int i=0; i < n; i++)
        {
            if (sec->pNext == NULL)
            {
                if (i == n-1)
                  head = head->pNext;  
                
                return head;
            }

            sec = sec->pNext;
        }
        while(sec->pNext != NULL)  
        {
           first = first->pNext;
           sec = sec->pNext;
        }

        first->pNext = first->pNext->pNext;
        return head;
    }

    void printList()
    {
        Node *temp = head;

        while (temp != NULL) {
          cout << temp->_val << " ";
          temp = temp->pNext;
        }
    }
};

int main()
{
    LinkedList *l = new LinkedList();
    l->head = l->push(7);
    l->head = l->push(10);
    l->head = l->push(8);
    l->head = l->push(11);

    l->deleteNthNode(4);

    l->printList();

    return 0;
}