#include <iostream>
#include <string>
using namespace std;
#define MAX 100
char s[MAX];
int t = -1;
int main() {
    string str;
    cin >> str;
    bool ok = true;
    for(int i = 0; i < str.size(); i++) {
        if(str[i]=='('||str[i]=='['||str[i]=='{') s[++t]=str[i];
        else {
            if(t==-1) { ok=false; break; }
            char c=s[t--];
            if((str[i]==')'&&c!='(')||(str[i]==']'&&c!='[')||(str[i]=='}'&&c!='{')) { ok=false; break; }
        }
    }
    if(t!=-1) ok=false;
    cout << ok;
}
