#include <iostream>
using namespace std;


void swim(){

}

void sink(vector<int> &v, int i, int size){
    if(i >= size) return ;


    int leftChild = (i * 2) + 1;
    int rightChild = (i* 2) + 2;

    if(leftChild >= size) return;
    int maxx = leftChild;
    if(rightChild < size && v[rightChild ] > v[leftChild]) maxx = rightChild; 
    
    if( v[maxx] <= v[i] ) return;


    swap( v[i] , v[maxx] );
    
    sink(v , maxx , size); 

}


void heapify(vector<int> &v){

    int size = v.size();

    for(int i= size/2 - 1; i>= 0 ; i-- ){

        sink(v, i, size );

    }

    for(int i = size - 1; i >= 0 ; i--){
        swap( v[0] , v[i]);
        sink(v , 0 , i);
    }


}


int main(){
    vector<int> v;
    int n; 
    cin >> n;
    for(int i =0 ; i< n ; i++){
        int temp;
        cin >>temp;
        v.push_back(temp);
    }
    heapify(v);
    
    for(int i : v) cout << i << " ";
    cout << endl;
}