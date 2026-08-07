#include <iostream>
#include <queue>

using namespace std;


struct Village{
    public:
        double load;
        double population;
        int clinics;

        Village(double l , double p ,int c){
            load = l;
            population = p;
            clinics = c;
        }

        bool operator<(const Village &other)const{
            return load < other.load;
        }
        bool operator>(const Village &other)const{
            return load > other.load;
        }
};

//can pass this in the pq instead of overloading operator < 
/*
struct Compare {
    bool operator()(const Village& a, const Village& b) const {
        return a.load > b.load;
    }
};
*/

int main(){

    int n;
    int k;

    cin >> n;

    priority_queue<Village> pq;


    for(int i = 0;  i< n ; i++){
        double temp;
        cin >> temp;
        Village v(temp, temp , 1);
        pq.push(v);
    }

    cin >> k;


    k -= n;

    while(k--){
        Village mostLoadV = pq.top();
        double mostLoad =mostLoadV.load;
        double population = mostLoadV.population;
        double clinicsAlloc = mostLoadV.clinics + 1;
        pq.pop();
        mostLoadV.load = population/ (clinicsAlloc );
        mostLoadV.clinics = clinicsAlloc;
        pq.push(mostLoadV);

    }

    cout << pq.top().load << endl;

    

 
}

