#include <iostream>
#define LEN 10

int len_foo(){
    int i = 2;
    return i;
}

constexpr int GetSize(int z){
	//cout << 1 << endl;只能有单一的return语句
	return z;
}
const int Fibonacci(int n){
	return (1 == n) ? 1 : ((2 == n) ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2));
}

constexpr int len_foo_constexpt(){
    return 5;
}

constexpr int fibonacci(const int n){
    //if(n==1) return 1; //C++14开始 内部可以使用分支等语句
    return n == 1 || n == 2 ? 1 : fibonacci(n-1) + fibonacci(n-2); 
}
void Test(){
    const int n = 5;
    int arr1[n];
    constexpr int m = 5;
    int arr2[m];
    int k;
    std::cin>>k;
    const int a = k;//正确，因为a是运行时常量，k在运行时才知道
    //constexpr int b = k;//错误，b是编译时常量，k在运行时才知道
}
int main(){
    char arr_1[10];
    char arr_2[LEN];
    int len = 10;
    // char arr_3[len];
    const int len_2 = len + 1;
    constexpr int len_2_constexpr = 1 + 2 + 3;
    //char arr_4[len_2];
    char arr_4[len_2_constexpr];

    char arr_5(len_foo()+5);

    const int *p1 = nullptr;//p1是指向整形常量的指针
    constexpr int *p2 = nullptr;//p2是指向整型的常量指针

    int n =fibonacci(15);// 尽管是在编译器运算的，但是存在记忆体并赋值这个过程仍是在运行是进行的
    std::cout << n << '\n';

    int fib[] = {
		Fibonacci(11), Fibonacci(22),
		Fibonacci(13), Fibonacci(24),
		Fibonacci(15), Fibonacci(26),
	};
    for (const auto elem : fib){
		std::cout << elem << std::endl;
	}
}