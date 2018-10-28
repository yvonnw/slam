#include <iostream>
#include <stdio.h>
using namespace std;
#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Cholesky>
#include <Eigen/QR>

int main(int argc, char** argv){
    // matrix_100_100*x = v_b
    //create matrix_100_100 and v_b
    Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> matrix_100_100(100, 100);
    matrix_100_100 = Eigen::MatrixXf::Random(100, 100);
    printf("matrix_100_100\n");
    cout << matrix_100_100 << endl;
    Eigen::Matrix<float, Eigen::Dynamic,1> v_b(100, 1);
    v_b = Eigen::MatrixXf::Random(100, 1);
    printf("v_b\n");
    cout << v_b << endl;

    // QR 
    Eigen::Matrix<float, Eigen::Dynamic, 1> x_qr(100, 1);    
    x_qr = matrix_100_100.colPivHouseholderQr().solve(v_b);
    printf("x_qr\n");
    cout << x_qr << endl;


    // cholesky
    Eigen::Matrix<float, Eigen::Dynamic, 1> x_cholesky(100, 1);
        //create symmetric matrix
    for (int i=0; i<100; i++){
        for (int j=0; j<100; j++){
            if (i == j){
                matrix_100_100(i,j)=300+i;
            }
            else{
                matrix_100_100(i,j)=i+j;
            }
        }
    }
    cout << "symmetric matrix" << endl;
    cout << matrix_100_100 << endl;   

    x_cholesky = matrix_100_100.llt().solve(v_b);
    printf("x_cholesky\n");
    cout << x_cholesky << endl;

    return 0;
}

