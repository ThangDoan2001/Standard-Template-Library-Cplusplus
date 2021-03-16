#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int ctoi(char c)
{
    return c - '0';
}

string addStrings(string num1, string num2) {

    stringstream ss;
    int s1 = num1.length() - 1;
    int s2 = num2.length() - 1;

    int carry = 0;
    for (; s1 >= 0 && s2 >= 0; --s1, --s2)
    {
        int res = (ctoi(num1[s1]) + ctoi(num2[s2])) + carry;
        carry = 0;

        if (res >= 10)
        {
            ss << res % 10;
            carry = 1;
        }
        else
        {
            ss << res;
        }
    }

    while (s1 >= 0)
    {
        int res = ctoi(num1[s1--]) + carry;
        carry = 0;

        if (res >= 10)
        {
            ss << res % 10;
            carry = 1;
        }
        else
        {
            ss << res;
        }
    }

    while (s2 >= 0)
    {
        int res = ctoi(num2[s2--]) + carry;
        carry = 0;

        if (res >= 10)
        {
            ss << res % 10;
            carry = 1;
        }
        else
        {
            ss << res;
        }
    }

    if (carry)
    {
        ss << carry;
    }

    string res = ss.str();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string a = "123";
    string b = "789";
    string c = addStrings(a, b);
    cout << c;
}
