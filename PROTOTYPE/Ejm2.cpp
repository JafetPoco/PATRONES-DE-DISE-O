#include<iostream>
using namespace std;

class Auto{
    protected:
        string color;
        string modelo;
    public:
        virtual Auto* clonar() = 0;
        void set_color(const string _c) {color = _c;}
        void set_modelo(const string _m) {modelo = _m;}
        virtual string ver_auto() const = 0;
};

class Ford : public Auto{
    public:
        Auto* clonar() override {
            return new Ford(*this);
        }

        string ver_auto() const override {
            string info = "Carro Ford modelo: "+ modelo + ", color: " + color;
            return info;
        }
};

class Toyota : public Auto{
    public:
        Auto* clonar() override {
            return new Toyota(*this);
        }
        string ver_auto() const override {
            string info = "Carro Toyota modelo: "+ modelo + ", color: " + color;
            return info;
        }
};

int main(){
    Ford car1;
    car1.set_modelo("Mustang");
    car1.set_color("Rojo");

    Toyota car2;
    car2.set_modelo("Corolla");
    car2.set_color("Azul");

    Auto *car3 = car1.clonar();
    Auto *car4 = car2.clonar();

    cout<<"CLONES: "<<endl;
    cout<<car3->ver_auto()<<endl;
    cout<<car4->ver_auto()<<endl;

    return 0;
}