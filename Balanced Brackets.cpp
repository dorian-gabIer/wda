#include <bits/stdc++.h>
using namespace std;
string isBalanced(string s)
{
    std::stack<char> st;
    
    for(auto c : s)
    {
        switch (c) {
            case '{':
            case '[':
            case '(':
                st.push(c);
                break;
            case '}':
            case ']':
                if ( st.empty() || st.top() != c-2 )
                {
                    return "NO";
                }
                st.pop();
                break;
            case ')':
                if ( st.empty() || st.top() != c-1 )
                {
                    return "NO";
                }
                st.pop();
                break;
        }
    }
    return st.empty() ? "YES" : "NO";
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);
        string result = isBalanced(s);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
