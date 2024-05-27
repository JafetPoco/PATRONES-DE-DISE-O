#include <iostream>

using namespace std;

class Servicio {
public:
    virtual void ejecutar() = 0;
    virtual ~Servicio() {}
};

class ServicioConcretoA : public Servicio {
public:
    void ejecutar() override {
        cout << "Ejecutando ServicioConcretoA" << endl;
    }
};

class ServicioConcretoB : public Servicio {
public:
    void ejecutar() override {
        cout << "Ejecutando ServicioConcretoB" << endl;
    }
};

class Cliente {
private:
    Servicio* servicio;
public:
    Cliente(Servicio* srv) : servicio(srv) {}

    void realizarTarea() {
        servicio->ejecutar();
    }
};

int main() {
    Servicio *servicioA = new ServicioConcretoA();
    Servicio *servicioB = new ServicioConcretoB();

    Cliente clienteA(servicioA);
    clienteA.realizarTarea();
    
    Cliente clienteB(servicioB);
    clienteB.realizarTarea();
    
    delete servicioA;
    delete servicioB;

    return 0;
}
