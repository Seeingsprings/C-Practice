#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    int stock;
    double price;

public:
    Book(string a, string b, int c, double d) : title(a), author(b), stock(c), price(d) {}

    string get_title() const {
        return title;
    }
    string get_author() const {
        return author;
    }
    int get_stock() const {
        return stock;
    }
    void set_stock(int t) {
        stock = t;
    }
    double get_price() const {
        return price;
    }
    void set_price(double n)  {
        price=n;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void add(const Book& book) {
        books.push_back(book);
    }

    void show() const {
        if (books.empty()) {
            cout << "不存在这本书，请重新输入" << endl;
            return;
        }
        cout << left << setw(30) << "书名"
             << setw(20) << "作者"
             << setw(10) << "库存"
             << setw(10) << "价格" << endl;
        cout << string(70, '-') << endl;
        for (const auto& book : books) {
            cout << left << setw(30) << book.get_title()
                 << setw(20) << book.get_author()
                 << setw(10) << book.get_stock()
                 << setw(10) << fixed << setprecision(2) << book.get_price() << endl;
        }
    }

    void search(const string& title) const {
        bool found = false;
        for (const auto& book : books) {
            if (book.get_title() == title) {
                cout << left << setw(30) << "书名"
                     << setw(20) << "作者"
                     << setw(10) << "库存"
                     << setw(10) << "价格" << endl;
                cout << string(70, '-') << endl;
                cout << left << setw(30) << book.get_title()
                     << setw(20) << book.get_author()
                     << setw(10) << book.get_stock()
                     << setw(10) << fixed << setprecision(2) << book.get_price() << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "未找到书 '" << title << "'。" << endl;
        }
    }

    void borrow(const string& title) {
        for (auto& book : books) {
            if (book.get_title() == title) {
                if (book.get_stock() > 0) {
                    book.set_stock(book.get_stock() - 1);
                    cout << "成功借阅 " << title << ", 剩余: " << book.get_stock() << " 本" << endl;
                } else {
                    cout << title << " 借阅失败，库存不足" << endl;
                }
                return;
            }
        }
        cout << "未找到 " << title << "，请重新输入" << endl;
    }

    void returnbook(const string& title) {
        for (auto& book : books) {
            if (book.get_title() == title) {
                book.set_stock(book.get_stock() + 1);
                cout << title << " 归还成功，目前馆内剩余 " << book.get_stock() << " 本" << endl;
                return;
            }
        }
        cout << "未找到 " << title << "，请重新输入" << endl;
    }

    void remove(const string &title){
        auto t = remove_if(books.begin(),books.end(),[&](const Book&book){
            return book.get_title()==title;

        });
        if(t!=books.end()){
            books.erase(t,books.end());
            cout<<"删除成功"<<title<<endl;
        
        }else {
            cout<<"删除失败,请重新尝试"<<endl;
        }
    }

    void change(const string &title,int stock,double price){
      
        for(auto &book :books){
            if(book.get_title()==title){
                if (book.get_title() == title) {
                    if (stock != 0) {
                        book.set_stock(stock);
                    }
                    if (price != 0) {
                        book.set_price(price);
                    }
                cout<<"修改成功"<<endl;
                
                
            }
        }
    }
    show();
}
};

void menu() {
    cout << " ___________________________________________________________________________________________________________" << endl;
    cout << "                                       恭喜你找到宝藏！                                                    " << endl;
    cout << "                                        欢迎进入藏经阁!                                                     " << endl;
    cout << " ___________________________________________________________________________________________________________" << endl;
    cout << "                                                                                                          " << endl;
    cout << "                                  富家不用买良田，书中自有千钟粟。                                               " << endl;
    cout << "                                  安居不用架高堂，书中自有黄金屋。                                               " << endl;
    cout << "                                  出门无车毋须恨，书中有马多如簇。                                               " << endl;
    cout << "                                  娶妻无媒毋须恨，书中有女颜如玉。                                               " << endl;
    cout << "                                  男儿欲遂平生志，勤向窗前读六经。                                               " << endl;
    cout << " ___________________________________________________________________________________________________________" << endl;

    cout << "操作说明：" << endl;
    cout << "0 - 退出系统";
    cout << " 1 - 显示库存";
    cout << " 2 - 查询图书";
    cout << " 3 - 借阅图书";
    cout << " 4 - 归还图书";
    cout << " 5 - 增加图书";
    cout <<"6-删除图书" ;
    cout << " 7 - 修改图书信息" << endl;
    cout << "请输入操作：";
}




int main() {
    Library library;

    // 载入书
    library.add(Book("吾国与吾民", "林语堂", 80, 10));
    library.add(Book("苏轼传", "林语堂", 89, 10));
    library.add(Book("楞伽经", "达摩", 60, 10));
    library.add(Book("易筋经", "达摩", 60, 9));
    library.add(Book("射雕英雄传", "金庸", 50, 9));
    library.add(Book("神雕侠侣", "金庸", 40, 9));
    library.add(Book("倚天屠龙记", "金庸", 40, 9));
    library.add(Book("简爱", "夏洛蒂·勃朗特", 40, 9));
    library.add(Book("百年孤独", "加西亚·马尔克斯", 40, 9));
    library.add(Book("战争与和平", "列夫·托尔斯泰", 40, 9));
    library.add(Book("计算机程序设计艺术", "高德纳", 60, 10));

    int chose;
    string title, author;
    int stock;
    double price;

    do {
        menu();
        cin >> chose;
        cin.ignore();

        switch (chose) {
            case 0:
                cout << "叉出去！" << endl;
                break;
            case 1:
                library.show();
                break;
            case 2:
                cout << "输入要查询的书名：";
                getline(cin, title);
                library.search(title);
                break;
            case 3:

                cout << "请输入要借阅的书名：";

                getline(cin, title);
                library.borrow(title);
                break;
            case 4:
                cout << "请输入要归还的书名：";
                getline(cin, title);
                library.returnbook(title);
                break;
            case 5:
                cout << "请输入书名：";
                getline(cin, title);
                cout << "请输入作者：";
                getline(cin, author);
                cout << "请输入数量：";
                cin >> stock;
                cout << "请输入价格：";
                cin >> price;
                library.add(Book(title, author, stock, price));
                library.show();
                break;
            case 6:
                cout<<"输入你要删除的书名：";
                getline(cin,title);
                library.remove(title);
                break;
            case 7:
                cout<<"输入你要修改的书名,如果不修改请输入0 ";
                getline(cin,title);
                cout<<"输入你要修改的库存,如果不修改请输入0 ";
                cin>>stock;
                cout<<"输入你要修改的价格,如果不修改请输入0 ";
                cin>>price;
                library.change(title,stock,price);
                break;

            default:
                cout << "出现问题，请重新输入。" << endl;
                break;
        }
    } while (chose != 0);

    return 0;
}  