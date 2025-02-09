#include <iostream>
using namespace std;

class Hero{
    //properies
    public:
    int health;
    char level;

    void print(){
        cout << "Level is : " << level<< endl;
    }
};

class hero2{

    private: 
    string name;

    public:
    int health;
    int level;
    
    void print(){
        cout << "Name of her02 is " << name << endl;
    }

    //name can not be accessed outside this cass, so to access the name outside the class we   
    //can use getter() and setter() method.

    string getName(){
        return name;
    }

    void setName(string str){
        name =  str;
    }
};

int main(){

    Hero Ramesh;
    Ramesh.health = 70;
    Ramesh.level = 'A';
    cout << "Ramesh Health is " << Ramesh.health << endl;
    cout << "RAemsh Level is " << Ramesh.level << endl;

    hero2 Sonu;
    Sonu.health = 90;
    Sonu.level = 5;
    cout << "Sonu Health is " << Sonu.health << endl;
    cout << "Sonu Level is " << Sonu.level << endl;
    Sonu.setName("Rohan");
    cout << "name is " << Sonu.getName() << endl;
}