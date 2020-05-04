#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Codec {
    static const int INT_SIZE = 4;
        
    string intToString(int l)
    {
        // 0004 -> "0004"
        string s(INT_SIZE, 0);
        for(int i=0; i < INT_SIZE; i++)
        {
            s[INT_SIZE-i-1] = l & 0xFF;
            l >>= 8;
        }

        return s;
    }
    
    int stringToInt(const string s)
    {
        int n = 0;
       for (int i=0; i < INT_SIZE; i++)
       {
           n >>= 8;
           n |= (unsigned char)s[i];  
       }   
       return n;
    }
    
public:

     
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded="";
        for(string s : strs)
        {
            int len = s.size();
            string lenstr = intToString(len);
            encoded += lenstr + s; 
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        int pos = 0;
        while (pos < s.length())
        {
            int len = stringToInt(s.substr(pos, INT_SIZE));
            pos +=INT_SIZE;
            string str = s.substr(pos, len);
            res.push_back(str);
            pos += str.size();
        }
        
        return res;
    }
};

int main()
{
   // Your Codec object will be instantiated and called as such:
   Codec codec;
   vector<string> strs{"hello", "world", "eye", "for", "an", "eye", 
                        "leaves", "everyone", "with", "good", "ears"};
   vector<string> res = codec.decode(codec.encode(strs));
   for(auto s: res)
   {
       cout << s << endl;
   }

   return 0;
}