#include <bits/stdc++.h>
using namespace std;

int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}

int main()
{
    string s;
    cin >> s;

    int flag = 0;
    int count = 0;
    int n = s.length();
    if (n < 7)
    {
        cout << "NO" << endl;
    }
    else
    {
        string str1 = "0000000";
        string str2 = "1111111";

        if (isSubstring(str1, s) || isSubstring(str2, s))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
