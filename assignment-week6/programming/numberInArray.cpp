
#include <iostream>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0 ; i< n ; i++){
        int temp; cin >> temp;

        v.push_back(temp);
    }

    vector<int> bitFreq(32 , 0);

    for(int i: v){


        int el = i;
        
        for(int bit = 31 ;bit >=0 ; bit--){
            int setBit= el &1;
            bitFreq[bit ] += setBit;
            el >>= 1;

        }

    }

    int ans = 0;

    for(int i = 0 ; i < bitFreq.size(); i++){
        int freq = bitFreq[i];
        if(freq % 3 != 0){ 

            ans |= 1;
        }

        if(i != bitFreq.size() -1) ans <<= 1;
        

    }

    cout << ans << endl; 

}