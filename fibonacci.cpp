#include <iostream>

using namespace std;

int fibRecursion(int n) {
    if (n <= 1)
        return n;
    else
        return ( fibRecursion(n - 1) + fibRecursion(n - 2) );
}
void fibDynamic(int n){
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    cout << "\nFibonacci Series using Dynamic Programing :";
    cout << " " << arr[0] << " " << arr[1];
    for(int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        cout << " " << arr[i];
    }
}
// helper function
void multiply(int mat1[2][2], int mat2[2][2]){
    // multiply
    int x = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int y = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int z = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int w = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];
    // assigning
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}
void powering(int mat[2][2], int n) {

    if (n == 0 || n == 1)
        return;
    // log n complexity
    int orgnl[2][2] = {{1, 1}, {1, 0}};

    powering(mat, n / 2);
    multiply(mat, mat);

    if (n % 2 != 0)
        multiply(mat, orgnl);
}
int fibMatrix(int n) {
    if (n == 0)
        return 0;

    int mat[2][2] = {{1, 1}, {1, 0}};
    powering(mat, n - 1);

    return mat[0][0];
}

int main() {
    int x = -1;
    cout << "1.Recursion \n2.Divide and Conquer (matrix multiplication) \n3.Dynamic Programming \n0.Exit \n";
    while(true) {
        while(x < 0 || x > 3) {
            cout << "\nSelect algorithm [1,3] 0 to exit:";
            cin >> x;
        }
        if(x == 0)
            return 0;
        int n;
        cout << "Enter the number of elements in the series :";
        cin >> n;
        if (x == 1) {
            cout << "\nFibonacci Series using Recursion :";
            int i = 0;
            while (i < n) {
                cout << " " << fibRecursion(i);
                i++;
            }
            cout << "\n";
        } else if(x == 2) {
            cout << "\nFibonacci Series using Divide and Conquer (matrix multiplication) :";
            int i = 0;
            while (i < n) {
                cout << " " << fibRecursion(i);
                i++;
            }
            cout << "\n";
        } else if(x == 3) {
            fibDynamic(n);
        }
        else if(x == 0)
            return 0;

        x = -1;
    }
}
