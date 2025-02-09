#include <iostream>
using namespace std;


class Car{
    private:
    int price;
    public:
    int gate;
    int power;

    int getPrice(){
        return price;
    }

    void setPrice(int carPrice){
        price = carPrice;
    }

};

int main(){
   
    // static allocation 
    Car hundai;
    hundai.setPrice(50000);
    hundai.gate = 4;
    hundai.power = 90;
    cout << "hundai car details" << endl;
    cout << "Price " <<  hundai.getPrice() << endl;
    cout << "Gate " << hundai.gate << endl;
    cout << "Power " << hundai.power << endl;

    // dynamic allocation
    Car *mahindra = new Car; 
    mahindra->gate = 5;
    mahindra->setPrice(1000000);
    mahindra->power = 96;

    cout << "Gate " << (*mahindra).gate << endl;
    cout << "power " << (*mahindra).power << endl;
    cout << "price " << (*mahindra).getPrice() << endl;
    //          OR
    cout << "Gate " << mahindra->gate << endl;
    cout << "power " << mahindra->power << endl;
    cout << "price " << mahindra->getPrice() << endl;

}