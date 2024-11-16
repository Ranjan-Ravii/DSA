#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int maxlength = 0;
    int start = 0;
    unordered_set<char> charSet;

    int j = 0;
    int i = 0;

    while (j < s.size())
    {
        if (charSet.find(s[j]) == charSet.end())
        {
            charSet.insert(s[j]);
            j++;
            if (j - i > maxlength)
            {
                maxlength = j - i;
                start = i;
            }
        }
        else
        {
            charSet.erase(s[i]);
            i++;
        }
    }
    for (int i = start; i < start + maxlength; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return maxlength;
}

int main()
{
    string str = "bbbbcdef";
    int ans = lengthOfLongestSubstring(str);
    cout << ans;
}