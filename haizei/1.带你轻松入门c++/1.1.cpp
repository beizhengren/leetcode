//
// Created by wyz on 20-10-3.
//
/*
四种编程范式
*/

#include <iostream>
using namespace std;

//1.面向过程
int add1(int a, int b){
    return a + b;
}

//2.面向对象
class ADD{
public:
    int operator()(int a, int b){
        return a + b;
    }
};

//3.泛型编程

template <typename T, typename U>
auto add3(T a, U b){
    return a + b;
}

//4.函数式编程

auto add4 = [](int a, int b){
    return a + b;
};

int main(){
    ADD add2;
    cout << add1(3,4) << endl;
    cout << add2(3,4) << endl;
    cout << add3(3,4) << endl;
    cout << add4(3,4) << endl;
}
