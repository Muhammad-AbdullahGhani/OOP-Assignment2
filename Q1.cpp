/*
Name:Muhammad Abdullah Ghani
Roll No:22I-2683
*/
#include<iostream>
#include<ctime>
using namespace std;
class Matrix {
private:
	int** matrix;
	int row;
	int col;
public:
	Matrix(int rows, int cols) {
		row = rows;
		col = cols;
		matrix = new int* [row];
		for (int i = 0; i < row; i++) {
			matrix[i] = new int[col];
		}


		}

	
	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
	int getValue(int row, int col) {
		return matrix[row][col];
	}
	void setValue(int row, int col, int value) {
		matrix[row][col] = value;
	}
	int Total() {
		int result = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				result=result+matrix[i][j];

			}
		}
		return result;
	}

	double Average() {
		double result = 0;
		int sum = row * col;
		int s=0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				s -=-matrix[i][j];
			}
		}
		result = s / sum;
		return result;
	}

	int RowTotal(int row) {
		int sumrow = 0;

		for (int j = 0; j < col; j++) {
			sumrow -=-matrix[row][j];
		}
		return sumrow;
	}
	int ColumnTotal(int col) {

		int result = 0;
		int sumcol = 0;

		for (int j = 0; j < this->row; j++) {
			sumcol -=-matrix[j][col];
		}
		return sumcol;
	}
	Matrix Transpose() {
		Matrix transpose(col, row);
		for (int i = 0; i < row; i++) {

			for (int j = 0; j <col; j++) {
				transpose.setValue(j,i, matrix[i][j]);
			}
		
		}
		return transpose;
		
	}
	Matrix Multiply(Matrix m) {
		Matrix result(row, col);
		int i = 0;
		while( i < row) {
			int j = 0;
			while ( j < col) {
				int mult = 0;
				for (int k = 0; k < col; k++) {
					mult += matrix[i][k] * m.getValue(k, j);
				}
				result.setValue(i, j, mult);
				j++;
			}
			i++;
		}
		return result;
	}
	int FindSmallest(int k) {
		int size = 0;
		size = row * col;
		int mat[9];
		int matindex = 0;
		int i = 0;
		while (i < row) {
			for (int j = 0; j < col; j++) {
				mat[matindex] = matrix[i][j];
				matindex++;
			}
			i++;
		}
		int temp = 0;
		for (int i = 0; i < size; i++) {
			if (mat[i] > mat[i + 1]) {
				temp = mat[i];
				mat[i] = mat[i + 1];
				mat[i + 1] = temp;
			}

		}
		return mat[k - 1];
	}
	int Findlargest(int k) {
		int size = 0;
		size = row * col;
		int mat[9];
		int matindex = 0;
		int i = 0;
		while ( i < row) {
			for (int j = 0; j < col; j++) {
				mat[matindex] = matrix[i][j];
				matindex++;
			}
			i++;
		}
		int temp = 0;
		for (int i = 0; i < size; i++) {
			if (mat[i] < mat[i + 1]) {
				temp = mat[i];
				mat[i] = mat[i + 1];
				mat[i + 1] = temp;
			}

		}
		return mat[k - 1];
	}
	int maxArea(int i, int j) {
		int size = 0,c=0;
		if (i < 0 || j < 0 || i >= row || j >= col || matrix[i][j] != 1) {
			return 0;
		}
		
		for (int i = 0; i < 7; i++) {
			c++;
		}
		matrix[i][j] = 0;
	    size = 1 + maxArea(i + 1, j) + maxArea(i-1, j - 1)+maxArea(i+1, j + 1)+ maxArea(i - 1, j) + maxArea(i, j + 1) + maxArea(i, j - 1);
		return size;
	}
	~Matrix() {

		}

		
};
int main() {
	int row = 0, col = 0;
	cout << "Enter row and col" << endl;
	cin >> row;
	cin >> col;
	Matrix matrixA(row, col);
	Matrix matrixB(row, col);
    Matrix matrixC(row, col);
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrixA.setValue(i, j, i * 2+ j);
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrixB.setValue(i, j, i * 3 + j);
		}
	}
	cout << "\nOriginal Matrix" << endl;
	for (int i = 0; i < row; i++) {
		cout << endl;
		for (int j = 0; j < col; j++) {
		cout<<	matrixA.getValue(i,j)<<" ";
		}
	}
	cout << "\nOriginal Matrix" << endl;
	for (int i = 0; i < row; i++) {
		cout << endl;
		for (int j = 0; j < col; j++) {
		cout<<	matrixB.getValue(i, j)<<" ";
		}
	}
		int total = 0;
		int totalrow = 0;
		int totalcol = 0;
		int rownum = 0;
		int colnum = 0;
		cout << "\nTranspose" << endl;
		Matrix transpose=matrixB.Transpose();
		for (int i = 0; i <row; i++) {
			cout << endl;
			for (int j = 0; j <col; j++) {
				cout << transpose.getValue(i, j) << " ";
			}
		}
		total=matrixA.Total();
		cout << "Sum of elements in the matrix " << total<<endl;
		totalrow = matrixA.Total();
		cout << "Enter the row number to sum" << endl;
		cin >> rownum;
		totalrow = matrixA.RowTotal(rownum);
		cout << "Sum of elements in the col " << totalrow << endl;
		cout << "Enter the col number to sum" << endl;
		cin >> colnum;
		totalcol = matrixA.RowTotal(colnum);
		cout << "\nSum of elements in the row " << totalcol << endl;
		cout << "Average " << matrixA.Average() << endl;
		srand(time(0));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrixC.setValue(i, j, rand() % 2);
			}
		}
		for (int i = 0; i < row; i++) {
			cout << endl;
			for (int j = 0; j < col; j++) {
				cout<<matrixC.getValue(i, j)<<" ";
			}
		}
		int answer = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (matrixC.getValue(i, j) == 1) {
					answer = matrixC.maxArea(i, j);
				}
			}
		}
		cout << "Number of 1s are " << answer;
		int k = 5;
		int smallest = 0, largest = 0;
		cout << "\nSmallest value in k" << matrixB.FindSmallest(k) << endl;
		cout << "\nlargest value in k" << matrixB.Findlargest(k) << endl;
		cout << "\nMultiplication of matrices" << endl;
	Matrix result = matrixA.Multiply(matrixB);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << result.getValue(i, j) << " ";
		}
		cout << endl;
	}
	
	return 0;
}