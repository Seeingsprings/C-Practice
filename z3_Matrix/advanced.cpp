#include <iostream>
#include<cstdio>
#include<algorithm>
#include <fstream>
#include <vector>
#include<ctime>
#include<cstdlib>
#include<stdexcept>
using namespace std;

class Matrix{
    private:
    vector<vector<int>> data;
    int rows,cols;
    public:
    Matrix(int r=0,int c=0):rows(r),cols(c){
        data.resize(rows,vector<int>(cols,0));
    }

    void randomize(int min=0,int max=100){
        for(auto& row:data){
            for(auto& elem:row){
                elem=min+rand()%(max-min+1);
            }
        }
    }

    vector<int>& operator[](int i) {return data[i];}
    const vector<int>& operator[](int i)const {return data[i];}

    // 矩阵加法
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("矩阵维度不匹配，无法相加");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + other[i][j];
            }
        }
        return result;
    }
    //因为这里返回的是result ，所以A还是保持不变
    //如果把other加到原来上，return*this，A就等于A+B

     // 矩阵转置
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = data[i][j];
            }
        }
        return result;
    }

     // 输出矩阵
    friend ostream& operator<<(ostream& os, const Matrix& mat) {
        for (const auto& row : mat.data) {
            for (int elem : row) {
                os << elem << "\t";
            }
            os << endl;
        }
        return os;
    }

};

int main() {
    srand(time(nullptr));
    
    int rows, cols;
    cout << "输入矩阵A的行数和列数: ";
    cin >> rows >> cols;
    Matrix A(rows, cols);
    A.randomize(1, 10);  // 随机生成1-10之间的元素
    cout << "矩阵A:" << endl << A << endl;
    cout << "A的转置:" << endl;
    cout << A.transpose() << endl;

    cout << "输入矩阵B的行数和列数: ";
    cin >> rows >> cols;
    Matrix B(rows, cols);
    B.randomize(1, 10);
    cout << "矩阵B:" << endl << B << endl;

    cout << "A + B:" << endl;
    cout << (A + B) << endl;


    cout << "矩阵A:" << endl << A << endl;
}