#include <iostream>
using namespace std;

int main()
{

    // int num = 5;
    // int *ptr = &num;
    // cout << *ptr << endl;

    // // accessing same value using diffrent pointer
    // int i = 10;

    // int *p = &i;
    // int *q = &i;
    // cout << p << " " << *p << endl;
    // cout << q << " " << *q << endl;

    // // pointer does not create a copy.

    // int x = 12;
    // int y = x;
    // cout << "x before : " << x << endl;
    // y++;
    // cout << "x after : " << x << endl;

    // // in above situation there is a cpoy created so value is same. lets see for pointer

    // int age = 15;
    // int *ptrAge = &age;
    // cout << "age before : " << age << endl;
    // (*ptrAge)++;
    // cout << "age after : " << age << endl;

    // // how to copy a pointer to another pointer

    // int salary = 100;

    // int *ptrSalary = &salary;
    // int *ptrSalaryCopy = ptrSalary;

    // cout << ptrSalary << " - " << ptrSalaryCopy << endl;
    // cout << *ptrSalary << " - " << *ptrSalaryCopy << endl;

    // *ptrSalary = ++(*ptrSalary);

    // cout << *ptrSalary << endl;
    // cout << *ptrSalaryCopy << endl;

    int *ptr = 0;
    int a = 10;
    *ptr = a;

    cout << *ptr << endl;
}