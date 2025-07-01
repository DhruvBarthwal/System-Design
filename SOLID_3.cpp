//Liskov Substitution Principle
#include <iostream>
using namespace std;

class Bird{
    public:
        virtual void eat(){
            cout<<"Bird is eating"<<endl;
        }
};
class FlyingBird : public Bird{
    public : 
    virtual void fly(){
        cout<<"Flying bird is flying"<<endl;
    }
};
class Sparrow : public FlyingBird{
    public :
        void fly() override{
            cout<<"Sparrow flies high!"<<endl;
        }
};
class Ostrich : public Bird{
    //No fly() function because Ostrich don't fly
};
void makeItFly(FlyingBird* bird){
    bird->fly();
}

int main(){
    Sparrow s;
    Ostrich o;
    
    cout<<"Calling makeItFly() with Sparrow"<<endl;
    makeItFly(&s);

    cout<<"\nCalling eat() on all birds: "<<endl;
    s.eat();
    o.eat();
    return 0;
}
