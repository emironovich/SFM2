#include "pch.h"
#include <Eigen/Dense>
#include <iostream>
#include <complex>

using namespace Eigen;

void findCoefficientsForL2Poly(double * L2, MatrixXd & Q, double L_1) {}
void findCoefficientsForF23(double ** F, MatrixXd & Q, double L_1, double L_2) {}
double find_0_coefficient(MatrixXd Q) { return 0; }
double find_1_coefficient(MatrixXd Q) { return 0; }
double find_2_coefficient(MatrixXd Q) { return 0; }
double find_3_coefficient(MatrixXd Q) { return 0; }
double find_4_coefficient(MatrixXd Q) { return 0; }
double find_5_coefficient(MatrixXd Q) { return 0; }
double find_6_coefficient(MatrixXd Q) { return 0; }
double find_7_coefficient(MatrixXd Q) { return 0; }
double find_8_coefficient(MatrixXd Q) { return 0; }
double find_9_coefficient(MatrixXd Q) { return 0; }
double find_10_coefficient(MatrixXd Q) { return 0; }
double find_L2(double L1) { return 0; }
double find_L1(double values) { return 0; }

void gaussElimination(MatrixXd & M) {
	for (int i = 0; i < 10; i++) {
		double t = M(i, i);
		for (int j = i; j < 16; j++) {
			M(i, j) /= t;
		}
		for (int j = 0; j < 10; j++) {
			if (j == i)
				continue;
			t = M(j, i);
			for (int k = i; k < 16; k++) {
				M(j, k) = M(j, k) / t - M(i, k);
			}
		}
	}
}
double findF23(MatrixXd & Q, double L1, double L2) { return 0; }
VectorXd find_coefficients(MatrixXd Q) {
	VectorXd poly(11);
	poly(0) = find_0_coefficient(Q);
	poly(1) = find_1_coefficient(Q);
	poly(2) = find_2_coefficient(Q);
	poly(3) = find_3_coefficient(Q);
	poly(4) = find_4_coefficient(Q);
	poly(5) = find_5_coefficient(Q);
	poly(6) = find_6_coefficient(Q);
	poly(7) = find_7_coefficient(Q);
	poly(8) = find_8_coefficient(Q);
	poly(9) = find_9_coefficient(Q);
	poly(10) = find_10_coefficient(Q);
	return poly;
}
void fillM(MatrixXd M, double * x, double * y, double * xx, double * yy) {
	for (int i = 0; i < 10; i++) { // THIS IS PROBABLY WRONG

		//f11, f12, f21, f22, l1f31, f31, l1f32, f32, l2f13, f13, l2f23, f23, f33, l1f33, l2f33, l1l2f33
		//0 1 4 5 8 9 10 11 2 3 6 7 15 13 14 12

		M(i, 0) = x[i] * xx[i];  //  f_1_1, 
		M(i, 1) = x[i] * yy[i]; // f_1_2, 
		M(i, 2) = xx[i] * y[i]; // f_2_1; 
		M(i, 3) = y[i] * yy[i]; // f_2_2; 	
		M(i, 4) = xx[i] * (pow(x[i], 2) + pow(y[i], 2)); //  L_1*f_3_1; 
		M(i, 5) = xx[i]; // f_3_1;
		M(i, 6) = yy[i] * (pow(x[i], 2) + pow(y[i], 2)); //  L_1*f_3_2; 
		M(i, 7) = yy[i]; // f_3_2;
		M(i, 8) = x[i] * (pow(xx[i], 2) + pow(yy[i], 2)); // L_2*f_1_3; 
		M(i, 9) = x[i]; // f_1_3; 
		M(i, 10) = y[i] * (pow(xx[i], 2) + pow(yy[i], 2)); // L_2*f_2_3; 
		M(i, 11) = y[i]; // f_2_3;
		M(i, 12) = 1; // f_3_3
		M(i, 13) = pow(x[i], 2) + pow(y[i], 2);  // L_1*f_3_3;
		M(i, 14) = pow(xx[i], 2) + pow(yy[i], 2);  //  L_2*f_3_3; 
		M(i, 15) = (pow(x[i], 2) + pow(y[i], 2))*(pow(xx[i], 2) + pow(yy[i], 2)); //  L_1*L_2*f_3_3; 	
	}
}

void hi() {
	std::cout << "Hello Liza!\n";
}