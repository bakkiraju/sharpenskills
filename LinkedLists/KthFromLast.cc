#include <iostream>

using namespace std;

typedef struct _Node
{
    int val;
    struct _Node *next;
} Node;

void appendList(Node **head, int n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
        exit(-1);

    newNode->val = n;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->val << "-->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

Node *kthFromLast(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k <= 0)
        return NULL;
    Node *m1 = head, *m2 = head;

    while (m2->next != NULL && k > 0)
    {
        m2 = m2->next;
        k--;
    }

    if (m2 == head && k <= 0)
    {
        return NULL;
    }

    while (m2->next != NULL)
    {
        m2 = m2->next;
        m1 = m1->next;
    }

    if (m1 == head)
    {
        return m1;
    }

    return m1->next;
}

int main()
{
    Node *head = NULL;
    appendList(&head, 10);
    appendList(&head, 20);
    appendList(&head, 30);
    appendList(&head, 40);
    appendList(&head, 50);
    appendList(&head, 60);

    printLL(head);

    Node *kthLast = kthFromLast(head, 3);

    if (kthLast)
        cout << kthLast->val << endl;

    kthLast = kthFromLast(head, 6);

    if (kthLast)
        cout << kthLast->val << endl;

    Node *head1 = NULL;

    appendList(&head1, 1);

    kthLast = kthFromLast(head1, 1);

    if (kthLast)
        cout << kthLast->val << endl;

    return 0;
}
