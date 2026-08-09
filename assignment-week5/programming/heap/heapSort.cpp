#include <iostream>
using namespace std;







int main(){

    int n;
    vector<int> arr;
    cin >> n;

    for(int i = 0 ;i < n ; i++){
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    priority_queue<int, vector<int> , greater<int>> pq;

    for(int i= 0;  i< n; i++){
        pq.push(arr[i]);
    }
    int it = 0;
    while(!pq.empty()){
        int el = pq.top();
        pq.pop();
        arr[it++] = el;
    }
    for(int i =0 ; i < n ; i++) cout << arr[i] << " ";
    cout <<endl;


}