// Loop detection using Flyod algo by Dr.Knuth
#include <iostream>

using namespace std;

typedef struct _Node
{
    int val;
    struct _Node *next;
} Node;

Node *appendList(Node **head, int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
        exit(-1);

    newNode->val = n;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return newNode;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return newNode;
}

Node *findLoop(Node *head)
{
    Node *mouse = head->next;
    Node *snail = head;

    while (mouse != snail)
    {
        snail = snail->next; 
        mouse = mouse->next->next;
    }

    cout << mouse->val << endl;

    snail = head;

    while (mouse != snail)
    {
        snail = snail->next;
        mouse = mouse->next;
    }

    cout << mouse->val << endl;

    return mouse;
}

int main()
{
    Node *head = NULL;
    appendList(&head, 1);
    appendList(&head, 2);
    appendList(&head, 3);
    Node *junction = appendList(&head, 4);
    appendList(&head, 5);
    appendList(&head, 6);
    appendList(&head, 7);
    Node *end = appendList(&head, 8);
    end->next =  junction; 

    findLoop(head);

    return 0;
}