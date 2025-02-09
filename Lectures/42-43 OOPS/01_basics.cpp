#include <iostream>
using namespace std;

//creation of class
class Hero{
    // properties of hero class
    int health;
    int level;
};

class Hero2{
    // properties of hero class
    //  int health;
    //  int level;
};

int main(){

    // creating object of hero class
    Hero Ramesh;

    cout << "size of the class is : " << sizeof(Hero) << endl;
    cout << "size of the class if class is empty: " << sizeof(Hero2) << endl;
}