#include <iostream>
#include <type_traits>

void foo(char *);
void foo(int);

int main(){
    std::cout<< std::is_same<int,std::int32_t>::value << '\n';
    if (std::is_same<decltype(NULL), decltype(0)>::value)
        std::cout << "NULL == 0" << std::endl;
    if (std::is_same<decltype(NULL), decltype((void*)0)>::value)
        std::cout << "NULL == (void *)0" << std::endl;
    if (std::is_same<decltype(NULL), std::nullptr_t>::value)
        std::cout << "NULL == nullptr" << std::endl;
    foo(0);
    //foo(NULL); 编译失败
    foo(nullptr);
    /*
        这是因为有些编译器把NULL识别成0
        foo(NULL) -> foo(0) -> foo(int)
        而nullprt为了避免这种情况
    */
}

void foo(char *) {
    std::cout << "foo(char*) is called" << std::endl;
}
void foo(int i) {
    std::cout << "foo(int) is called" << std::endl;
}