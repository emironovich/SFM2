#pragma once
#include <Eigen/Dense>
#include <complex>
#include <utility>  


using namespace Eigen;
using namespace std;

void findCoefficientsForL2Poly(double * L2, MatrixXd Q, double L_1);
void findCoefficientsForF23(double ** F, MatrixXd Q, double L_1, double L_2);
double find_0_coefficient(MatrixXd Q);
double find_1_coefficient(MatrixXd Q);
double find_2_coefficient(MatrixXd Q);
double find_3_coefficient(MatrixXd Q);
double find_4_coefficient(MatrixXd Q);
double find_5_coefficient(MatrixXd Q);
double find_6_coefficient(MatrixXd Q);
double find_7_coefficient(MatrixXd Q);
double find_8_coefficient(MatrixXd Q);
double find_9_coefficient(MatrixXd Q);
double find_10_coefficient(MatrixXd Q);
VectorXd find_coefficients(MatrixXd Q);
void gaussElimination(MatrixXd & M);
double find_L1(double values);
pair<double, double> find_L2(double L1);
void fillM(MatrixXd M, double * x, double * y, double * xx, double * yy);
double findF23(MatrixXd Q, double L1, double L2);
Matrix3d findF(MatrixXd Q, double L1, double L2);