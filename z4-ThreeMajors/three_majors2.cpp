#include <iostream>
#include<iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

class Student{
    protected:
    int  id;
    string name;
    double EnglishScore;


    public:
    double MathScore;
    Student(){}
    virtual ~Student(){}
    virtual void Input()=0;
    virtual void Show()=0;
    virtual double GetAverageScore() const {
        return (EnglishScore + MathScore) / 2.0; // 默认实现，子类可以重写
    }
    virtual string GetMajor() const = 0; 
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

    double GetAverageScore() const override {
        return (EnglishScore + MathScore + AIScore) / 3.0; // 重写计算平均分
    }

    string GetMajor()const override{
        return"计算机技术与科学";
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
    double GetAverageScore() const override {
        return (EnglishScore + MathScore + ComputerWebScore) / 3.0; // 重写计算平均分
    }

    string GetMajor() const override {
        return "网络工程";
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
    double GetAverageScore() const override {
        return (EnglishScore + MathScore + SoftwareEngineeringScore) / 3.0; // 重写计算平均分
    }

    string GetMajor() const override {
        return "软件工程";
    }
};

void menu(){
    cout << "\n输入数字\n";
    cout << "1.只展示计科专业学生成绩\n";
    cout << "2. 只展示网络工程专业学生成绩\n";
    cout << "3. 只展示软件工程专业学生成绩\n";
    cout << "4. 根据平均成绩排序\n";
    cout << "5. 根据高等数学成绩排序\n";
    cout << "0. 退出\n";
    cout << "请选择操作(数字): ";
}

// 比较函数：按平均成绩排序
bool CompareByAverageScore(const Student* a, const Student* b) {
    return a->GetAverageScore() > b->GetAverageScore();
}

// 比较函数：按高等数学成绩排序
bool CompareByMathScore(const Student* a, const Student* b) {
    return a->MathScore > b->MathScore;
}



int main(){
    
    srand(static_cast<unsigned int>(time(nullptr)));
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

    // for(int i=0;i<400;++i){
    //     delete students[i];
    // }
    int choice;
    do{
    menu();
    cin>>choice;
    vector<Student*> filteredStudents; 
    if (choice == 1) {
        for (int i = 0; i < 400; ++i)
            if (students[i]->GetMajor() == "计算机技术与科学")
                filteredStudents.push_back(students[i]);
    } else if (choice == 2) {
        for (int i = 0; i < 400; ++i)
            if (students[i]->GetMajor() == "网络工程")
                filteredStudents.push_back(students[i]);
    } else if (choice == 3) {
        for (int i = 0; i < 400; ++i)
            if (students[i]->GetMajor() == "软件工程")
                filteredStudents.push_back(students[i]);
    }else if(choice==4||choice==5){
        for(int i=0;i<400;++i){
            filteredStudents.push_back(students[i]);
        }
    }
    
    if(choice==4){
        int index=1;
        sort(filteredStudents.begin(),filteredStudents.end(),CompareByAverageScore);
        for(const auto&student:filteredStudents){
            cout<<" "<<index++<<"\t";
            student->Show();

        }
    
    }else if(choice==5){
        int index=1;
        sort(filteredStudents.begin(),filteredStudents.end(),CompareByMathScore);
        for(const auto&student:filteredStudents){
            cout<<" "<<index++<<"\t";
            student->Show();

        }
    
    }else if (choice >= 1 && choice <= 3) {
        int index=1;
        for (const auto& student : filteredStudents){
            cout<<" "<<index++<<"\t";
            student->Show();
        } 
    } else if (choice == 0) {
        cout << "退出程序！" << endl;
    } else {
        cout << "无效选择，请重新输入！" << endl;
    }
    filteredStudents.clear();

}while (choice!=0);
   
    for(int i=0;i<400;++i){
        delete students[i];
    }
}