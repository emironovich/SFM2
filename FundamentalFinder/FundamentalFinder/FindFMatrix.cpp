#include "pch.h"
#include "coeffsFinders.h"
#include <Eigen/Dense>
#include <complex>
#include <vector>

using namespace std;
using namespace Eigen;

vector<MatrixXd> FindFMatrix(double * x, double * y, double * xx, double * yy) {
	MatrixXd M(10, 16); // coefficient matrix for ten equations and sixteen monomials
	fillM(M, x, y, xx, yy);

	//M.colPivHouseholderQr(); //???? пофиг
	gaussElimination(M); // THIS DOES NOT WORK OF COURSE


	MatrixXd Q(10, 6); // this is the "leftovers" of gaussian elimination
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 6; j++) {
			Q(i, j) = M(i, j + 10);
		}
	}
	hi();
	VectorXd poly = find_coefficients(Q);


	MatrixXd C = MatrixXd::Zero(10, 10); //the companion matrix
	C(0, 9) = poly(0) / poly(10); // todo find out the way of numeration
	for (int i = 1; i < 10; i++) {
		C(i, i - 1) = 1;
		C(i, 9) = poly(i) / poly(10);
	}

	//find its eigenvalues = roots of poly
	VectorXcd cValues = C.eigenvalues();
	vector<double> roots; //let's deal with real numbers for now

	for (int i = 0; i < 11; i++) {
		if (imag(cValues(i)) == 0)
			roots.push_back(real(cValues(i)));
	}



	//find lambda 1 (lambdas apparently)
	vector<double> L1_vector;
	for (int i = 0; i < roots.size(); i++) {
		L1_vector.push_back(find_L1(roots[i]));
	}

	//find lambda 2 (lambdas apparently)
	vector<double> L2_vector;
	for (int i = 0; i < L1_vector.size(); i++) {
		L2_vector.push_back(find_L2(L1_vector[i]));
	}


	vector<MatrixXd> F_vector;
	for (int i = 0; i < L1_vector.size(); i++) {
		double L1 = L1_vector[i];
		double L2 = L2_vector[i];
		Matrix3d F;
		//find F[2][3] supposing that F[3][3] = 1
		F(2, 3) = findF23(Q, L1, L2);
		F(3, 3) = 1;

		//find all the other coefficents of the matrix F

		VectorXd X(6);
		X(0) = L2 * F(2, 3);
		X(1) = F(2, 3);
		X(2) = F(3, 3);
		X(3) = L1 * F(3, 3);
		X(4) = L2 * F(3, 3);
		X(5) = L1 * L2 * F(3, 3);

		F(1, 1) = (Q.row(0) * X)(0);
		F(1, 2) = (Q.row(1) * X)(0);
		F(2, 1) = (Q.row(2) * X)(0);
		F(2, 2) = (Q.row(3) * X)(0);
		F(3, 1) = (Q.row(5) * X)(0);
		F(3, 2) = (Q.row(7) * X)(0);
		F(1, 3) = (Q.row(9) * X)(0);


	}
	return F_vector;
}