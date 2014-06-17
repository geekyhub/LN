#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <string>
#include <cstdlib>
#include <armadillo>

using namespace std;
using namespace arma;



int main(int argc,char **argv){
	
	Matrix A(argv[1]);
	cout<<A.dimension()<<endl;
	A.mat_diag();
	A.mat_solve();


	return EXIT_SUCCESS;
}

