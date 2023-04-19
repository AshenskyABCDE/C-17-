#include <stdexcept>
#include <iostream>
using namespace std;
double fun(double x,double y){
    if(y == 0){
        throw y;
    }
    throw "afsds";
}
void testTryCatch(){
    double res;
    try{
        res = fun(2,3);
        cout<<"The result of x/y is : "<<res<<endl;
        res = fun(4,0); // 抛出一个异常之后便不在运行
    } catch(double){
        cerr<<"error of dividing zero.\n";
    } catch(const char*){
        cerr<<"srgde\n";
    }
}

void out_of_range_Exception(){
    try{
        throw std::out_of_range("");
    } catch (std::exception& e){
        std::cout << 1;
    } catch (std::out_of_range& e){
        std::cout << 2;
    }
    //输出1
    //抛出out_of_range异常，
}
int main(){
    out_of_range_Exception();
    //-------------
    // try {
    //     throw "exception";
    // }catch (const char *e){
    //     printf("%s\n",e);
    // }

    // try {
    //     throw 3.14;
    // }catch (const double e){
    //     printf("%.2f\n",e);
    // }
    /*
    
    */
}