#include <iostream>
using namespace std;

string table =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

string toBin(int dec, int k){
   
    string bin = "";
    while(k--){
        bin = ((char)('0' + (dec & 1 ))) + bin;
        dec >>= 1;
    }

    return bin;
}

string toDecnBin(string str){
    string bin = "";

    for(int i =0 ; i < str.length() ; i++){

        int dec = str[i];
        
        bin += toBin(dec, 8);
        


    }
    return bin;

}

string encoding(string bin){

    string encoded = "";

    int i = 0 ; 
    while(i < bin.length()){
        int j= 0;
        int sixBits = 0;
        while(j < 6){
            if(i + j >= bin.length()){
                bin += '0';
            }
            
            sixBits  |= (bin[i + j] - '0');
            
            if(j != 5 ) sixBits <<= 1;
            j++;
        
        }
        i += 6;
        encoded += table[sixBits];
    }
    return encoded;

}

int main(){
    string input = "";
    cin >> input;

    string bin = "";

    int i =0;
    while(i < input.size()){
        string temp = "";
        int j = 0;
        while( j < 3 && i + j < input.size() ){
            temp += input[ i + j];
            j++;
        }

        i += 3;
        string binChunk = toDecnBin(temp);
        
        bin += binChunk;
    }

    string ans = encoding(bin);

    while(ans.length() % 4 != 0) ans += '=';
    cout << ans << endl;
    

}  