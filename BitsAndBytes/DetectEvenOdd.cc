#include <iostream>
#include <bitset>

using namespace std;

template<size_t SIZE>
bool isOdd(bitset<SIZE> n)
{
   if (n[0])
     return true;
   else
     return false;
}

int main()
{
    bitset<32> b = 21;
    cout << isOdd<32>(b) << endl;
    return 0;
}