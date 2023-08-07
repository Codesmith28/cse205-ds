#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> wordDict = {"a", "b", "bbb", "bbbb"};
    string s = "bb";                                                                                                                                                                                                                                                                                                                                                                    

    bool flag = true;

    for (auto it : wordDict)
    {
        auto idx = s.find(it);
        if (idx != string::npos)
        {
            s.erase(idx, it.size());
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "true";
    else
        cout << "false";

    return 0;
}