#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

template <class T>
class Queue
{

    public: 
     void enqueue(T item)
     {
         main.push(item);   
     }

     T dequeue()
     {
         if (not main.size()) exit(-1);

         while(main.size())
         {
             auto item = main.top();
             main.pop();
             aux.push(item);
         }     

         auto val = aux.top();
         aux.pop();

         while (aux.size())
         {
             T item = aux.top();
             aux.pop();
             main.push(item);
         }
        
         return val;   
     }

    private:
     stack<T> main;
     stack<T> aux;
};

int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    Queue<string> qs;

    qs.enqueue("apple");
    qs.enqueue("google");
    qs.enqueue("skylabs");

    cout << qs.dequeue() << endl;
    cout << qs.dequeue() << endl;

    return 0;
}