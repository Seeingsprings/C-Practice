#include  <iostream>
using namespace std;

class Matrix{
    private:
    int matrix[3][3];

    public:
    Matrix(){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                matrix[i][j]=0;
            }
        }
    }

    Matrix operator+(const Matrix&other)const{
        Matrix result;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                result.matrix[i][j] =matrix[i][j]+other.matrix[i][j];
            }
        }
        return result;
    }

    friend istream&operator>>(istream&in,Matrix&ma){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                in>>ma.matrix[i][j];
            }
    }
    return in;
}

    friend ostream&operator<<(ostream&out,Matrix&ma){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                out<<ma.matrix[i][j]<<" ";
            }
        out<<endl;
    }
    return out;

}
};

int main(){
    Matrix m1,m2,m3;
    cout<<"请输入m1:"<<endl;
    cin>>m1;
    cout<<"请输入m2:"<<endl;
    cin>>m2;

    m3=m1+m2;
    cout<<"m1+m2的结果:"<<endl;
    cout<<m3<<endl;

    return 0;
}