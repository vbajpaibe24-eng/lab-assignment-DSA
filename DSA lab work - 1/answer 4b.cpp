#include <iostream>
using namespace std;

const int imax = 100;

void matrix_multiply(int arr[][imax],int brr[][imax],int r1, int r2, int c1, int c2){

    if (c1 != r2){
        cout << "Multiplication not possible";

    }
    else{
        int res[r1][c2];

        for (int i = 0;i < r1;i++){
            for (int j = 0;j < c2;j++){
                res[i][j] = 0;
                for (int k = 0; k < c1;k++){
                    res[i][j] += arr[i][k] * brr[k][j];

                }
            }
        }


    }


}

void create(int arr[][imax],int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0;j < c;j++){
            cin >> arr[i][j];
            cout << " ";
        }
    }
}

int main(){
    int r1,r2,c1,c2;

    cout << "Enter rows for first array: ";
    cin >> r1;
    
    cout << "Enter columns for first array: ";
    cin >> c1;

    int arr[r1][imax];

    create(arr,r1,c1);

    cout << "Enter rows for second array: ";
    cin >> r2;

    cout << "Enter columns for second array: ";
    cin >> c2;

    int brr[r2][imax];

    create(brr,r2,c2);

    matrix_multiply(arr,brr,r1,r2,c1,c2);
    return 0;

}