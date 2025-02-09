#include <iostream>
using namespace std;

class Hero{

    public:
    string avtarName;
    int level;
    int power;

    Hero(){
        cout << "Constructor created!"<< endl;
    }
    
    Hero(int level){
        this->level = level;
    }

    Hero(int level, int power){
        this->level = level;
        this->power = power;
    }

    void print(){
        cout << "level : " << this->level << endl;
        cout << "power : " << this->power << endl;
    }
};


int main(){

    // Hero akshay;

    Hero tt(12);
    Hero sonu(24, 100);
    sonu.print();


    Hero newHero(sonu);
    newHero.print();
    
   
}