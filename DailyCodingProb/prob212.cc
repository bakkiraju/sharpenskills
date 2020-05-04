/* 
This problem was asked by Dropbox.
Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....
Given a column number, return its alphabetical column id. For example, given 1, return "A". Given 27, return "AA".
*/

/*
   A=1
   Z=26

   27 = 27/26, 27%26 = 1,1 -> AA
   53 = 53/26, 53%26 = 2,1 -> AAA
   54 = 54/26, 54%26 = 2,2 -> AAB                             
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i = 79;

    int q =  i / 26;
    int r =  i % 26;

    for(int j=0; j < q; j++)
    {
        cout << 'A';
    }

    cout << static_cast<char>('A'+r-1) << endl;

    return 0;
}