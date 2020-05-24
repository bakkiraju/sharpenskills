#include <iostream>
#include <bitset>

using namespace std;

void setBitsInRange(int &k, int l, int r)
{
    int mask1 = ((1 << (l)) - 1);
    int mask2 = ((1 << (r-1)) - 1);
    cout << bitset<8>(mask1) << " " << bitset<8>(mask2) << " " << bitset<8>(mask1^mask2) << endl; 

    k = k | (mask1 ^ mask2);
}

int main()
{
    int k = 17, l = 5 , r = 3;
    
    cout << bitset<8>(k) << endl;

    setBitsInRange(k, l, r);

    cout << bitset<8>(k) << endl;

    return 0;
}