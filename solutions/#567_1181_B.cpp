#include <bits/stdc++.h>

using namespace std;

string number1 = "";
string number2 = "";

bool check()
{
    // cout << number1 << " " << number2 << " ";
    if (number2.size() > number1.size()) {
        return true;
    } else if (number2.size() < number1.size()){return false;}

    for (int i=0; i<number1.size(); i++) {
        if (number2[i]-'0' > number1[i]-'0') {
            return true;
        } else if (number2[i]-'0' < number1[i]-'0') {
            return false;
        } else {
            continue;
        }
    }
    return true;
}

int ans[100005]={0};
void summ() {
    // cout << number1 <<  " " << number2 << " ";
    if (number2.size() > number1.size()){
        string num3 = number1;
        number1 = number2;
        number2 = num3;
    }
    int x = number2.size();
    int y = number1.size() - number2.size();
    int r = 0;
    for (int i=x-1; i>=0; i--) {
        int a = number1[i + y]-'0' + number2[i]-'0';
        a = a + r;
        r = 0;
        
        if (a>9) {
            a-=10;
            r=1;
        }
        ans[i + y + 1] = a;
    }
    for (int i = y-1; i>=0; i--) {
        int a = number1[i] - '0';
        a=a+r;
        r=0;
        if (a>9) {
            a-=10;
            r=1;
        }
        ans[i + 1] = a;
    }
    if (r) {
        ans[0] = 1;
    }
    return;
}

int main() {
    int n; 
    cin >> n;
    string str;
    cin >> str;
    if (str[n/2]=='0') {
        int x=n, y;
        for (int i=n/2; i<n; i++) {
            if (str[i]!='0') {
                x=i;
                break;
            }
        }
        for (int i=n/2; i>=0; i--) {
            if (str[i]!='0') {
                y=i;
                break;
                
            }   
        }
        for (int i=0; i<x; i++) {
            number1 += str[i];
        }
        for (int i=y; i<n; i++) {
            number2 += str[i];
        }
        if (check()) {
            number2="";
            for (int i=x; i<n; i++) {
                number2 += str[i];
            }
        }
        else {
            number1="";
            for (int i = 0; i < y; i++) {
                number1 += str[i];
            }
            
        }
    } else {
        for (int i=0; i<(n+1)/2; i++) {
            number1 += str[i];
        }
        for (int i = n/2; i<n; i++) {
            number2 += str[i];
        }
        if (check()) {
            number2="";
            for (int i=(n+1)/2; i<n; i++) {
                number2 += str[i];
            }
        }
        else {
            number1="";
            for (int i = 0; i < n/2; i++) {
                number1 += str[i];
            }
        }
    }
    summ();
    int x;
    int y = number1.size()+1;
    if (ans[0]) x=0;
    else x=1;
    for (int i=x; i<y; i++) {
        cout << ans[i];
    }
    return 0;
}