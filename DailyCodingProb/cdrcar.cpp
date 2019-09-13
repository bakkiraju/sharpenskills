#include <iostream>

using namespace std;

typedef struct mypair
{
    std::pair<int,int> p;
    mypair(int i, int j) {
        p = std::make_pair(i,j);
    }

} cons;

int car(const cons &c)
{
    return c.p.first;
}

int cdr(const cons &c)
{
    return c.p.second;
}

int main()
{

    cout << car(cons(3,4)) << " " << cdr(cons(3,4)) << endl;
    return 0;
}