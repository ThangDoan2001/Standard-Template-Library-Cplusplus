#include<iostream>
#include<string>
#include<stack>
using namespace std;

int reversals(string exp)
{
    const auto len = exp.length();

    if (len % 2) {
        return -1;
    }

    stack<char> s;

    for (const auto c : exp) {
        if (c == '}') {
            if (!s.empty() && s.top() == '{') {
                s.pop();
                continue;
            }
        }
        s.push(c);
    }

    int res = 0;
    while (!s.empty()) {
        const auto t1 = s.top();
        s.pop();
        const auto t2 = s.top();
        s.pop();
        if (t1 == t2) res += 1;
        else res += 2;
    }
    return res;
}

int main() {
    string aim = "}{{}}{{{";
    cout << reversals(aim);
    return 0;
}