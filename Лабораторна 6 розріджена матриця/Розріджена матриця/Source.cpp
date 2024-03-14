#include <iostream>
#include <vector>

using namespace std;

struct MatrixElement
{
	MatrixElement* upper_element = this;
	MatrixElement* left_element = this;
	size_t row = 0;
	size_t column = 0;
	double value;
};

class SparseMatrix
{
	size_t rows_count;
	size_t cols_count;
	vector<MatrixElement> cols;
	vector<MatrixElement> rows;

	MatrixElement* get_previous_by_row(size_t row, size_t column)
	{
		MatrixElement* prev = &rows[row];
		while (prev->left_element->column > column)
		{
			prev = prev->left_element;
		}
		return prev;
	}

	MatrixElement* get_previous_by_col(size_t row, size_t column)
	{
		MatrixElement* prev = &cols[column];
		while (prev->upper_element->row > row)
		{
			prev = prev->upper_element;
		}
		return prev;
	}

	void add_value(MatrixElement* previous_by_row, MatrixElement* previous_by_col, 
		size_t row, size_t column, double value)
	{
		MatrixElement* new_element = new MatrixElement();
		new_element->row = row;
		new_element->column = column;
		new_element->value = value;
		new_element->left_element = previous_by_row->left_element;
		previous_by_row->left_element = new_element;
		new_element->upper_element = previous_by_col->upper_element;
		previous_by_col->upper_element = new_element;
	}

	void change_value(MatrixElement* previous_by_row, MatrixElement* previous_by_col,
		size_t row, size_t column, double value)
	{
		if (value == 0)
		{
			MatrixElement* elem_to_del = previous_by_row->left_element;
			previous_by_row->left_element = elem_to_del->left_element;
			previous_by_col->upper_element = elem_to_del->upper_element;
			delete elem_to_del;
		}
		else
		{
			previous_by_row->left_element->value = value;
		}
	}

public:
	SparseMatrix(size_t _rows_count, size_t _cols_count) : rows_count(_rows_count), cols_count(_cols_count)
	{
		cols.resize(cols_count + 1);
		rows.resize(rows_count + 1);
	}

	void set_value(size_t row, size_t column, double value)
	{
		MatrixElement* previous_by_row = get_previous_by_row(row, column);
		MatrixElement* previous_by_col = get_previous_by_col(row, column);
		bool element_in_matrix = previous_by_col->upper_element->row == row &&
		previous_by_col->upper_element->column == column;
		if (element_in_matrix)
		{
			change_value(previous_by_row, previous_by_col, row, column, value);
		}
		else
		{
			add_value(previous_by_row, previous_by_col, row, column, value);
		}
	}
	
	double get_value(size_t row, size_t column)
	{
		double ret_value = 0;
		MatrixElement* previous_by_col = get_previous_by_col(row, column);
		bool element_in_matrix = previous_by_col->upper_element->row == row &&
		previous_by_col->upper_element->column == column;
		if (element_in_matrix)
		{
			ret_value = previous_by_col->upper_element->value;
		}
		return ret_value;
	}
};

bool test1()
{
	SparseMatrix matr(5, 5);
	matr.set_value(1, 1, 11);
	matr.set_value(3, 2, 32);
	matr.set_value(3, 3, 33);
	matr.set_value(3, 2, 0);
	bool result = matr.get_value(1, 1) == 11 && 
		matr.get_value(3, 2) == 0 && 
		matr.get_value(3, 3) == 33 && 
		matr.get_value(5, 2) == 0;
	return result;
}

bool test2()
{
	SparseMatrix matr(3, 3);
	matr.set_value(1, 1, 12);
	matr.set_value(1, 2, 47);
	matr.set_value(1, 3, 53);
	matr.set_value(2, 2, 7);
	bool result = matr.get_value(1, 1) == 12 && 
		matr.get_value(2, 2) == 7 && 
		matr.get_value(1, 3) == 53;
	return result;
}

bool test3()
{
	SparseMatrix matr(3, 2);
	matr.set_value(1, 1, 783);
	matr.set_value(1, 2, 241);
	matr.set_value(3, 2, 999);
	bool result = matr.get_value(1, 1) == 783 && 
		matr.get_value(1, 2) == 241 && 
		matr.get_value(3, 2) == 999;
	return result;
}

int main()
{
	cout << "\tTest 1: " << (test1() ? "passed" : "failed") << endl;
	cout << "\tTest 2: " << (test2() ? "passed" : "failed") << endl;
	cout << "\tTest 3: " << (test3() ? "passed" : "failed") << endl;
	return 0;
}