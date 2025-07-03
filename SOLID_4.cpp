//Interface Segregation Principle
#include <iostream>
using namespace std;

//Interfaces
class IPrinter{
    public: 
        virtual void print() = 0;
        virtual ~IPrinter() = default;
};
class IScanner{
    public:
        virtual void scan() = 0;
        virtual ~IScanner() = default;
};
class IFax{
    public:
        virtual void fax() = 0;
        virtual ~IFax() = default;
};
//Implementation

//Old Printers only support printing
class OldPrinter : public IPrinter{
    public:
        void print() override{
            cout<<"OldePrinter : Printing document...\n";
        }
};
//MultiFunctionPrinter supports all features
class MultiFunctionPrinter : public IPrinter, public IScanner, public IFax{
    public:
        void print() override{
            cout<<"MFP : Printing document...\n";
        } 
        void scan() override{
            cout<<"MFP : Scanning document...\n";
        }
        void fax() override{
            cout<<"MFP: Faxing document...\n";
        }
};
//Scanner only supports scanning
class SimpleScanner :public IScanner{
    public:
        void scan() override{
            cout<<"SimpleScanner : Scanning document...\n";
        }
};
int main(){
    IPrinter* printer = new OldPrinter();
    printer->print();

    //Using MFP
    MultiFuntionPrinter mfp;
    mfp.print();
    mfp.scan();
    mfp.fax();

    //Using SimpleScanner
    IScanner* scanner = new SimpleScanner();
    scanner->scan();

    //Clean up
    delete printer;
    delete scanner;

    return 0;
}
