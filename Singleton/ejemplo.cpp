#include <iostream>

class Singleton{
    private:
        static Singleton* instance;
        Singleton();
        int var;
    public:
        static Singleton* getInstance();
        int getVariable(){return var;}
        void setVariable(int v){var=v;}
};
Singleton* Singleton::instance = nullptr;


Singleton* Singleton::getInstance(){
    if (instance == nullptr){
        instance = new Singleton();
    }
    return instance;
}
Singleton::Singleton(){}
int main(){
    Singleton* var_1 = Singleton::getInstance();
    var_1->setVariable(20);
    Singleton* var_2 = Singleton::getInstance();
    std::cout<<"Variable: "<<var_2->getVariable()<<std::endl;
}

