#include <iostream>
using namespace std;
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Cholesky>
#include <Eigen/QR>
#include <Eigen/Geometry>

int main(int argc, char** argv){

    Eigen::Quaternion<double> q1 = Eigen::Quaternion<double>(0.55, 0.3, 0.2, 0.2);  
    q1.normalize(); //must, unitize for following calculating
    Eigen::Matrix3d rotation_matrix_q1 = q1.toRotationMatrix(); 
    Eigen::Quaternion<double> q2 = Eigen::Quaternion<double>(-0.1, 0.3, -0.7, 0.2);
    q2.normalize();

    Eigen::Vector3d p1;
    p1 << 0.5, -0.1, 0.2;
    Eigen::Vector3d t1; 
    t1 << 0.7, 1.1, 0.2;
    Eigen::Vector3d t2;
    t2 << -0.1, 0.4, 0.8;

    Eigen::Vector3d p0;   //a' = R*a+t => a = R(-1)*(a'-t)
    p1 = p1 - t1;   
    p0 = rotation_matrix_q1.inverse()*p1;  

    Eigen::Vector3d p2;    
    p2 = q2*p0;
    p2 = p2 + t2;
    cout << "p2 = " << p2.transpose() << endl;

/*
    Eigen::Matrix<double, 1, 4> r1;
    Eigen::Matrix<double, 1, 4> r2;    
    Eigen::Matrix<double, 1, 4> r;
    r1 << 0.55, 0.3, 0.2, 0.2;
    r2 << -0.1, 0.3, -0.7, 0.2;
    r = r2-r1;
    cout << "r=" << r << endl;

    double r_arr[4];
    for (int i=0; i<4; i++){
        r_arr[i] = r(i);
        //cout << "r_arr=" << r_arr[i] << endl;
    }

    Eigen::Quaternion<double> delta_r = Eigen::Quaternion<double>(r_arr); 
    //Eigen::Quaternion<double> delta_r = Eigen::Quaternion<double>(0.65, 0, 0.9, 0);    
    cout << "delta_r = " << delta_r.coeffs() << endl;
    

    Eigen::Vector3d t1; 
    t1 << 0.7, 1.1, 0.2;
    Eigen::Vector3d t2;
    t2 << -0.1, 0.4, 0.8;
    Eigen::Vector3d p1;
    p1 << 0.5, -0.1, 0.2;    
    cout << "t1 = " << p1 << endl;
    cout << "t2 = " << p1 << endl;
    cout << "p1 = " << p1 << endl;

    
    Eigen::Vector3d delta_tt;
    //delta_tt = t2-t1;    
    delta_tt = t1-t2;
    cout << "delta_tt = " << delta_tt << endl;

    Eigen::Vector3d p2;
    p1 = p1 + delta_tt;
    p2 = delta_r*p1;
    cout << "p2 = " << p2 << endl;
*/
    return 0;
}