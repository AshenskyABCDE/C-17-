#include <iostream>
#include <vector>
// c++11 的初始化列表
class Foo{
public:
    int value_a;
    int value_b;
    Foo(int a ,int b) : value_a(a) , value_b(b) {};
};

struct node{
    int a, b;
};

struct Person {
    std::string name;
    int age;
    Person(const std::string & n,int a) : name(n) , age(a){
        std::cout<<"Creating Person: " << name <<" , "<<age<<std::endl;
    }
    ~Person(){
        std::cout<<"Destroyed Person"<<std::endl;
    }
};
struct Point {
    int name;
    int age;
};

class NewFoo{
public:
    std::vector<int> voc;
    NewFoo(std::initializer_list<int> list){
        for(std::initializer_list<int> :: iterator it = list.begin();it != list.end() ;it++){
            voc.push_back(*it);
        }
    }
    NewFoo(std::vector<int> vec) : voc(vec){
        voc=vec;
    }
};
std::vector<int> voc = {1,2,3,4,123,456,123};
int main(){
    Foo foo(1,2);
    int a[10] = {};
    std::vector<int> voc = {1,2,3,4,123,456,123};
    std::vector<int> vec {1,2,3,4,5};
    node z ={1,2};
    node zz {1,2};
    std::cout <<z.a<<'\n';
    Person p={"adsfs",1};
    Person v("adsfs",1);
    /*
        什么叫引出的列表初始化
        之前的C++11 有的初始化是() 有的是{}
        现在有了列表初始化 就可以赋值方便了
    */

    //Point ttt = {.age = 100, .name = 123}; C++20
    NewFoo vectorfoo2 (voc);//构造函数 进行 拷贝构造进行赋值
    for(auto x : vectorfoo2.voc){
        std::cout << x << std::endl;
    }
    NewFoo vectorfoo = {1,2,3,4,5};//列表初始化 从而初始化上更方便一些
    for(auto x : vectorfoo.voc){
        std::cout << x << std::endl;
    }
    std::cout <<" --------------- "<<std::endl;
    vectorfoo = {5,6,7,8,9,10}; // 编译成功 通过列表初始化可重新赋值
    for(auto x : vectorfoo.voc){
        std::cout << x << std::endl;
    }//更改赋值成功
    vectorfoo2 = (voc); //拷贝赋值
    vectorfoo2 = {1,2,3,4,5};//拷贝赋值
}