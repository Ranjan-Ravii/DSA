#include <iostream>
using namespace std;

int main()
{
    char ch = 'a';
    char st[5] = "abcd";
    // cout << ch << endl;
    // cout << st << endl;
    // cout << *st + 1 << endl;

    for (int i = 0; st[i] != '\0'; i++)
    {
        cout << st[i] << *(st) + i << *(i + st) << i[st];
    }

    return 0;
}