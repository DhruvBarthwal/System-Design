//Dependency Inversion Principle
#include <iostream>
using namespace std;

//Abstraction
class IDevice{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual ~IDevice() = default;
};

//Low level modules
class Light : public IDevice{
    public :
        void turnOn() override{
            cout<<"Light is On\n";
        }
        void turnOff() override{
            cout<<"Light is OFF.\n";
        }
};
class Fan : public IDevice{
    public:
        void turnOn() override{
            cout<<"Fan is ON.\n";
        }
        void turnOff() override{
            cout<<"Fan is OFF.\n";
        }
};

//High level modules
class Button{
    private:
        IDevice* device;  //depends on abstraction

    public:
        Button(IDevice* dev) : device(dev){}

        void pressOn(){
            device->turnOn();
        }
        void pressOff(){
            device->turnOff();
        }
};

int main(){
    Light myLight;
    Fan myFan;
    Button lightButton(&myLight);
    Button fanButton(&myFan);

    cout<<"Using Light Button: \n";
    fanButton.pressOn();
    fanButton.pressOff();

    return 0;
}
