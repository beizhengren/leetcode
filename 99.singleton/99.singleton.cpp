//
// Created by wyz on 2020/10/30.
//
#include <memory>
#include <iostream>
#include <string>
using namespace std;

class Random {
public:
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    static Random& GetInstace(const string& str){
        static Random instance(str);
        return instance;
    }

    static unique_ptr<Random>& Create(const string& str){
        static unique_ptr<Random> pInstance(new Random(str));

        return pInstance;
    }
    static float Float(){ return GetInstace("").IFloat();}
    static string Str(){ return GetInstace("").str_;}
private:
    Random(const string& str):str_(str){
        cout << "ctor" << endl;
    }
    float IFloat(){
        return f;
    }
    float f = 0.5f;
    string str_;
    Random(){ }
};

int main()
{
    auto& rand = Random::GetInstace("haha");
    auto f = Random::Float();
    cout << f << endl;
    cout << Random::Str() << endl;

    auto& ptr = Random::Create("hehe");
    cout << ptr->Float() << endl;
    cout << ptr->Str() << endl;
    return 0;
}