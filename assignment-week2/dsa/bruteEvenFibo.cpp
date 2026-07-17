#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int a = 0;
    int b = 1;
    if(argc != 2){
        cout << "Invalid" << endl;
        return -1;
    }
    int n = stoi(argv[1]);
    int sum = 0; 
    while(b <= n){
        if(b % 2 == 0) sum += b;

        int temp = a;
        a = b;
        b = a + temp;
    }

    cout << sum << endl;
    return 0;
}