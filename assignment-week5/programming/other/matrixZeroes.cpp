// #include <iostream>
// using namespace std;

// // void convert(int i , int j , vector<vector<int>> &m){

// //     for(int  k= 0; k < m.size() ; k++){
// //        if(m[k][j] != 0) m[k][j] = INT_MAX;
// //     }
// //     for(int k = 0 ; k < m[0].size() ; k++){
// //        if(m[i][k] != 0) m[i][k] = INT_MAX;
// //     }
// // }

// int main(){

//     int n,m;
//     cin >> n;
//     cin >> m;
//     vector<vector<int>> matrix;
//     for(int i =0 ; i < n ; i++){
//         vector<int> temp;
//         for(int j =0 ; j < m ; j++){
//             int t; cin >> t;
//             temp.push_back(t);
//         }
//         matrix.push_back(temp);
//     }

//     for(int i =0 ; i < n ; i++){
//         for(int j = 0 ; j < m ; j++){
//             if(matrix[i][j] == 0){

//                 matrix[i][0] = 0;
//                 matrix[0][j] = 0;
//             }
//         }
//     }

//     for(int i = 1 ; i < n ; i++){
//         for(int j = 1 ; j < m ; j++){
//             if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0; 
//             cout << matrix[i][j] << " ";
         
//         }
//         cout << endl;
//     }



// }

#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        matrix.push_back(temp);
    }

    bool firstRowZero = false;
    bool firstColZero = false;

    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    if (firstColZero) {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}