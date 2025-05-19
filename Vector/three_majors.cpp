#include <iostream>
#include<iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include<cstring>
#include<string>
using namespace std;

class Student{
    protected:
    int  id;
    string name;
    double EnglishScore;
    double MathScore;

    public:
    Student(){}
    virtual ~Student(){}
    virtual void Input()=0;
    virtual void Show()=0;
};

string GenerateName(){
    vector<char> words;
    for(char c = 'a'; c <= 'z'; ++c){
        words.push_back(c);
    }
 
    int nameLength = rand() % 3 + 6;//(8-6+1)+6也就是6到8
    string name;
    for(int i=0;i<nameLength;++i){
        int k=words.size();//26
        int index=rand()%k;//0-26
        char capital=words[index];
        if(i==0){
            capital=toupper(capital);//首字母大写
        }
        name+=capital;


    }
    return name;
}

void line(){
    for(int i=0;i<12;++i){
        cout<<"*******";
    }
    cout<<endl;
}


class ComputerScienceStudent:public Student{
    protected:
    double AIScore;

    public:
    ComputerScienceStudent(){}
    ~ComputerScienceStudent(){}
    void Input()override{
        id=rand()%(324166999-324166000+1)+324166000;
        // name="Student"+to_string(id);
        name=GenerateName();
        EnglishScore=static_cast<double>(rand())/RAND_MAX*100;
        MathScore=static_cast<double>(rand())/RAND_MAX*100;
        AIScore=static_cast<double>(rand())/RAND_MAX*100;
    }

    void Show()override{
        double AverageScore=(EnglishScore+MathScore+AIScore)/3.0;
        cout<<setprecision(1)<<fixed<<"专业:计算机技术与科学"<< "\t学号:"<<id<<"\t姓名:"<<name<<endl<<"英语成绩:"<<EnglishScore
        <<"\t高等数学成绩:"<<MathScore<<"\t人工智能成绩:"<<AIScore<<"\t平均成绩:"<< AverageScore<<endl;
        line();
    }
};

class NetworkEngineeringStudent:public Student{
    protected:
    double ComputerWebScore;

    public:
    NetworkEngineeringStudent(){}
    ~NetworkEngineeringStudent(){}
    void Input()override{
        id=rand()%(324166999-324166000+1)+324166000;
        name=GenerateName();
        EnglishScore=static_cast<double>(rand())/RAND_MAX*100;
        MathScore=static_cast<double>(rand())/RAND_MAX*100;
        ComputerWebScore=static_cast<double>(rand())/RAND_MAX*100;
    }

    void Show()override{
        double AverageScore=(EnglishScore+MathScore+ComputerWebScore)/3.0;
        cout<<setprecision(1)<<fixed<<"专业:网络工程"<< "\t学号:"<<id<<"\t姓名:"<<name<<endl<<"英语成绩:"<<EnglishScore
        <<"\t高等数学成绩:"<<MathScore<<"\t网络工程成绩:"<<ComputerWebScore<<"\t平均成绩:"<<AverageScore<<endl;
        line();
    
    }
};

class SoftwareEngineeringStudent:public Student{
    protected:
    double SoftwareEngineeringScore;
    
    public:
    SoftwareEngineeringStudent(){}
    ~SoftwareEngineeringStudent(){}
    void Input()override{
        id=rand()%(324166999-324166000+1)+324166000;
        name=GenerateName();
        EnglishScore=static_cast<double>(rand())/RAND_MAX*100;
        MathScore=static_cast<double>(rand())/RAND_MAX*100;
        SoftwareEngineeringScore=static_cast<double>(rand())/RAND_MAX*100;
    }

    void Show()override{
        double AverageScore=(EnglishScore+MathScore+SoftwareEngineeringScore)/3.0;
        cout<<setprecision(1)<<fixed<<"专业:软件工程"<< "\t学号:"<<id<<"\t姓名:"<<name<<endl<<"英语成绩:"<<EnglishScore
        <<"\t高等数学成绩:"<<MathScore<<"\t软件工程成绩:"<<SoftwareEngineeringScore<<"\t平均成绩:"<<AverageScore<<endl;
        line();
    }
    
};


int main(){
    
    srand(time(nullptr));
    Student*students[400];
    for(int i=0;i<400;++i){
        int random=rand()%3;
        switch(random){
            case 0:
            students[i]=new ComputerScienceStudent();
            break;
            case 1:
            students[i]=new NetworkEngineeringStudent();
            break;
            case 2:
            students[i]=new SoftwareEngineeringStudent();
            break;
        }
        students[i]->Input();
    }

    for(int i=0;i<400;++i){
        cout<<setfill('0')<<setw(3)<<i+1<<"  ";
        students[i]->Show();
    }


    for(int i=0;i<400;++i){
        delete students[i];
    }


}