#include<iostream>
using namespace std;

class Shape{
    public:
        virtual Shape* Clone() = 0;
        virtual void draw() const = 0;
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double r) : radius(r){}
        Shape* Clone() override {
            return new Circle(*this);
        }

        void draw() const override {
            cout<<"Circulo con radio "<<radius<<endl;
        }
};

class Rectangle : public Shape {
    private:
        double ancho;
        double largo;
    public:
        Rectangle(double a, double l): ancho(a), largo(l){}
        Shape* Clone() override {
            return new Rectangle(*this);
        }

        void draw() const override {
            cout<<"Rectangulo con ancho "<<ancho<<" y largo "<<largo<<endl;
        }
};

int main(){
    Circle circulo(3.4);
    Rectangle rectangulo(3.2, 4.1);

    Shape* clon_circulo = circulo.Clone();
    Shape* clon_rectangulo = rectangulo.Clone();

    cout<<"Objetos Originales: "<<endl;
    circulo.draw();
    rectangulo.draw();
    cout<<"Objetos Clon: "<<endl;
    clon_circulo->draw();
    clon_rectangulo->draw();

    return 0;
}

