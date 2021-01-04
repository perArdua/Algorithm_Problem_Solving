#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string Add(string &s1, string &s2){
        string result(max(s1.size(), s2.size()), '0');
        bool carry = false;
        for (int i = 0; i < result.size(); i++){
            int temp = carry;
            carry = false;
                if (i < s1.size())
                        temp += s1[s1.size() - i - 1] - '0';
                if (i < s2.size())
                        temp += s2[s2.size() - i - 1] - '0';
                if (temp >= 10)
                {
                        carry = true;
                        temp -= 10;
                }
                result[result.size() - i - 1] = temp + '0';
        }
        if (carry)
                result.insert(result.begin(), '1');
        return result;
}

//bigInteger 곱셈 구현
string Multiply(string &s1, string &s2)
{
        string result = "0";
        for (int i = 0; i < s2.size(); i++)
        {
                string line(s1);
                int carry = 0;
                for (int j = s1.size() - 1; j >= 0; j--)
                {
                        int temp = carry;
                        carry = 0;
                        temp += (s1[j] - '0')*(s2[s2.size() - i - 1] - '0');
                        if (temp >= 10)
                        {
                                carry = temp / 10;
                                temp %= 10;
                        }
                        line[j] = temp + '0';
                }
                if (carry > 0)
                        line.insert(line.begin(), carry + '0');
                line += string(i, '0');
                result = Add(result, line);
        }
        return result;
}

//bigInteger 지수승 구현
string power(string &s1, int p)
{
        if (p == 1)
                return s1;

        string result = power(s1, p - 1);
        result = Multiply(result, s1);
        return result;
}

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string A;
        int B;
        cin >> A >> B;
        //소수점 위치를 찾고
        string::iterator finder = find(A.begin(), A.end(), '.');
        int idx = 0;
        //소수점을 지워준다
        if (finder != A.end())
        {
                idx = A.end() - finder - 1;
                A.erase(finder);
        }
        //소수점이 추가될 위치를 저장하고
        idx *= B;
        string result = power(A, B);
        //소수점이 존재한다면 소수점을 추가해준다
        if (idx > 0)
                result.insert(result.end() - idx, '.');
        cout << result << "\n";
        return 0;
}