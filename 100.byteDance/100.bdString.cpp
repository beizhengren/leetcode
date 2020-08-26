//
// Created by wyz on 20-8-25.
//
#include <string>
#include <iostream>
using namespace std;

void getString(int n){

    for(int i = 0; i < n; ++i){
        string s, res;
        cin >> s;
        res = s[0];
        int state = 0;
        for(int j = 1; j < s.size(); ++j){
            switch(state){
                case 0:{
                    if(s[j] != s[j-1] ){ break;}
                    if(s[j] == s[j-1]) {state = 1; break;}

                }
                case 1:{
                    if(s[j] == s[j-1]) continue;
                    if(s[j] != s[j-1] ) {state = 2; break;}
                }
                case 2:{
                    if(s[j] == s[j-1]) continue;
                    if(s[j] != s[j-1] ) {state = 0; break;}
                }
            }
           res += s[j];
        }
        cout << res << endl;
    }
}

int main(){
    int n;
    cin >> n;
    getString(n);
}
