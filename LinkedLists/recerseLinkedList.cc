/* Reversing a linked list */
#include <iostream>

using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value) { this->value = value; }
};

LinkedList *reverseLinkedList(LinkedList *head)
{
    if (head == NULL)
        return NULL;

    LinkedList *p1 = NULL;
    LinkedList *p2 = head;
    LinkedList *p3 = p2->next;

    if (p3 == NULL)
        return p2;

    while (p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p2->next;
    }

    if (p3 == NULL)
    {
        p2->next = p1;
    }

    return p2;
}

void printLL(LinkedList *head)
{
    LinkedList *t = head;
    while (t)
    {
        cout << t->value << "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    LinkedList *head = new LinkedList(1);
    LinkedList *one = new LinkedList(2);
    LinkedList *two = new LinkedList(3);
    LinkedList *three = new LinkedList(4);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = NULL;

    LinkedList *rev = reverseLinkedList(head);
    printLL(rev);

    return 0;
}