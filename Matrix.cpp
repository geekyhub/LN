#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <string>
#include <cstdlib>
#include <armadillo>


using namespace std;
using namespace arma;

Matrix::Matrix(string file){
	filename = file;
}

Matrix::~Matrix(){}
int Matrix::dimension(){
	ifstream fp;
	fp.open(filename.c_str());
	string dummy;//dummy string to temporarily store a line
	int count = 0;

	if (!fp){
		cerr<<"open";
		exit(EXIT_FAILURE);
	}

	while(fp){
		if(getline(fp,dummy))
			count++;
	}
	fp.close();
	return count;
}

/*reading matrix from file and making it accessible for later*/
mat Matrix::readfileMat(){
	mat B;
	B.load(filename);
	return B;
}

/*using the armadillo/lapack functions this function
finds the eigen values and corresponding vectors of a given square matrix
*/
void Matrix::mat_diag(){
	mat Aa = readfileMat();
	int DIM  = dimension()-1;
	mat A = Aa.cols(0,DIM);
	mat eigvecs;
	vec eigvals;
	eig_sym(eigvals,eigvecs,A);
	cout<<"Eigen Values of given matrix are: \n"<<eigvals<<endl;
	cout<<"Eigen Vectors of given matrix are: \n"<<eigvecs<<endl;
	
}

void Matrix::mat_solve(){
	int DIM  = dimension();
	mat A = readfileMat();
	mat B = A.cols(0,DIM-1);
	vec b = A.col(DIM);
	cout<<"The solution to the given system is: \n"<<solve(B,b)<<endl;
}