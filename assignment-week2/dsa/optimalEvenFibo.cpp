#include <iostream>
using namespace std;



int main(int argc , char* argv[]){
    if(argc != 2){
        cout << "invalid" << endl;
        return -1;
    }

    int n = stoi(argv[1]);

    int sum = 0;
    int a = 2;
    int b = 8;

    while (a <= n) {
        sum += a;

        int c = 4 * b + a;

        a = b;
        b = c;
    }
    cout << sum << endl;
}