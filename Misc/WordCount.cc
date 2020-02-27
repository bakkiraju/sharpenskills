#include<iostream>

using namespace std;

int main()
{
    char str[] = "   Hello world,  I     love     Apple  ";

    char *p = str;
    int state = 0;
    int wc = 0;

    while (*p)
    {
        if (*p == ' ' || *p == ',')
        { 
            state = 1;
        }
        else if (state == 1)
        {
            state = 0;
            ++wc;
        }
        
        p++; 
    }

    cout << wc << endl;

    return 0;
}