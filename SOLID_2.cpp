//Open Close Principle
//Single Responsiblity Principle
#include <iostream>
#include <vector>

using namespace std;

//Product class representing any item in eCommerce
class Product{
    public:
        string name;
        double price;

        Product(string name,double price){
            this->name = name;
            this->price = price;
        }
};

//1. Shopping Cart : Responsible for cart related business logic
class ShoppingCart{
    private:
        vector<Product*>products;  //Store heap allocated products
    
    public:
        void addProduct(Product*p){
            products.push_back(p);
        }
        const vector<Product*>& getProducts(){
            return products;
        }

        //Calculates total price in cart
        double calculateTotal(){
            double total = 0;
            for(auto p : products){
                total += p->price;
            }
            return total;
        }
};

//2. ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter{
    private:
        ShoppingCart* cart;
    
    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart =cart;
        }
        void printInvoice(){
            cout<<"Shopping Cart Invoice\n";
            for(auto p : cart->getProducts()){
                cout<<p->name<<"-$"<<p->price<<endl;
            }
            cout<<"Total : $"<<cart->calculateTotal()<<endl;
        }
};

//3. ShoppingCartStorage : Only responsible for saving cart in DB
class ShoppingCartStorage{
    private:
        ShoppingCart*cart;

    public:
        ShoppingCartStorage(ShoppingCart* cart){
            this->cart = cart;
        }
        void saveToDatabase(){
            cout<<"Saving shopping cart to database..."<<endl;
        }
};

//Abstract classes
class Persistance{
    private: 
        ShoppingCart* cart;
    
    public:
        virtual void save(ShoppingCart*cart) = 0; //Pure virtual function
};

class SQLPersistance : public Persistance{
    public:
        void save(ShoppingCart* cart) override {
            cout<<"Saving shopping cart to SQL DB..."<<endl;
        }
};

class MongoPersistance : public Persistance{
    public:
        void save(ShoppingCart* cart) override{
            cout<<"Saving shopping cart to MongoDB..."<<endl;
        }
};

class FilePersistance : public Persistance{
    public:
        void save(ShoppingCart* cart) override{
            cout<<"Saving shopping cart to file..."<<endl;
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistance* db = new SQLPersistance();
    Persistance* mongo = new MongoPersistance();
    Persistance* file = new FilePersistance();

    db->save(cart); //Save sql to database
    mongo->save(cart); //Save to MongoDB
    file->save(cart); //Save to file

    return 0;
}
