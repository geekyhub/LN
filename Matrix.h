#include <armadillo>
using namespace arma;
class Matrix{
	/*we need to read a matrix a from a file and then from that we will solve a linear system Ax = b
	find eigen vectors and values for A.*/
	private:
		std::string filename;
	public:
		Matrix(std::string);
		~Matrix();
		int dimension();
		mat readfileMat();
		void mat_diag();
		void mat_solve();

};