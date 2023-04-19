#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main(){
    // C++ 17 的 if - statement 语法尝试。
    std::vector<int> vec = {1,2,3,4};
    const std::vector<int>::iterator itr = std::find(vec.begin(),vec.end(),2);
    if (itr != vec.end()){
        *itr = 3;
    }
    const std::vector<int>::iterator itr2 = std::find(vec.begin(),vec.end(),3);
    if(itr2 != vec.end()){
        *itr2 = 4;
    }
    for(std::vector<int> ::iterator it = vec.begin() ; it != vec.end() ; it++){
        std::cout << *it << '\n';
    }
    // C++ 17 可以在if 里 写语句
    if(const std::vector<int> :: iterator it = std::find(vec.begin(),vec.end(),3);it != vec.end()){
        *it = 4;
    }

    /*
        C++17 可能这样写
        int val = getnum();
        if(val){

        }else{

        }
        C++17 可以写成
        if(int val = getnum();val){

        }else{

        }
    */

   std::set<std::pair<std::string,int>> set1;
   std::pair<std::string,int> itemsToAdd[5]{{"hello",1},{"world",1},{"world",2},{"hello",1},{"world",2}};
   if(set1.insert({"hello",1})){
    std::cout<<"test"<<std::endl;
   }
   for(auto &p : itemsToAdd){
    if (const auto [iter , inserted] = set1.insert(p);inserted){//set1.insert返回的是pair<iterator,bool>
        std::cout<<iter->first<<"--- "<<iter->second<<'\n';
    }else{
        std::cout<<iter->first<<"~~~"<<iter->second<<'\n';
    }
   }

}