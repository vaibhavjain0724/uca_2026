#include <iostream>
using namespace std;


void findEOC(string &code , int &i){
    int n = code.length();
    while( i < n ){

        if(i < n - 1 && code[i] == '*' && code[i+1] == '/'){
            i+=2;
            return;
        } 

        i++;
    }
}


string removeComments( string &code ){
    int i = 0;
    int n = code.length();

    string codeWOcomments = "";

    while( i < n ){

        if( i + 1 < n && code[i] == '/' && code[i + 1] == '*'){
            i+=2;
            findEOC(code , i);
            continue;
        }
        
        else if( i + 1 < n && code[i] == '/' && code[i+1] == '/'){
            while(i < n && code[i] != '\n' )i++;
        }

        else {
            codeWOcomments += code[i];
            i++;
        }

        
    }
    return codeWOcomments;
}

int main(){
    string code;
    string line;

    while (getline(cin, line)) {
        code += line;
        code += '\n';
    }


    string ans = removeComments(code);
    cout << ans;
}