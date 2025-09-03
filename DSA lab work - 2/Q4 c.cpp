#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string r="";
    for(char c:s) if(!strchr("aeiouAEIOU",c)) r+=c;
    cout<<r;
}
