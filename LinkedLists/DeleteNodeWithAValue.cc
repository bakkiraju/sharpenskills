#include <iostream>
#include <memory>

using namespace std;

struct LinkedListNode
{
    int val;
    struct LinkedListNode *next;
    LinkedListNode(int val) : val{val}, next{nullptr} {}
    ~LinkedListNode(){ cout << "Deleting node with value " << val << endl;}
};

void deleteNode(LinkedListNode **head, int val)
{
    if (head == NULL)
        return;
    LinkedListNode *prev = nullptr, *temp = *head;
    while (temp)
    {
        if (temp->val == val)
        {
            if (temp == *head)
            {
                *head = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = *head;
            }
            else 
            {
                prev->next = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = prev->next;
            }
        }

        prev = temp;
        if (temp)
        temp = temp->next;
    }
}
void printLL(LinkedListNode *head)
{
    LinkedListNode *temp = head;
    while (temp)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void insert(LinkedListNode *head, int val)
{
    if (head == NULL)
    {
        head = new LinkedListNode(val);
    }
    else
    {
        LinkedListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = new LinkedListNode(val);
    }
}

int main()
{
    LinkedListNode *head = new LinkedListNode(10);
    // insert(head, 20);
    // insert(head, 30);
    // insert(head, 20);
    // insert(head, 30);
    // insert(head, 20);
    // insert(head, 20);
    // insert(head, 40);
    // printLL(head);
  //  deleteNode(&head, 10);
    printLL(head);
    delete(head);
  //  deleteNode(&head,40);
  //  printLL(head);
    return 0;
}