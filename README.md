The files here are used to solve a linear system(for very larger matrices too),and for matrix diagonalisation.
The system heavily relies on the armadillo libraries which can be easily installed(for ubuntu,you can use the software centre).
Since I used the Ubuntu 14.04 OS ,you may follow the commands I used to get things running:

g++ Matrix.cpp linear_system_solver.cpp -o solve -O2 -larmadillo && ./solve filename

filename is the file to read the matrix represented as [A b] in the file,in other words the dimension of the matrix as stored in file is
N*(N+1).
