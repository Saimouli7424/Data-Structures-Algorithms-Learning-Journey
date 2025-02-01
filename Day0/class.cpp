#include<bits/stdc++.h>
using namespace std;
class Vehicle{
    protected:
    string model;
    int year;
    Vehicle(string model,int year)
    {
        this->model=model;
        this->year=year;
    }
};

class Car : public Vehicle{
    public:
    Car(string mode,int yea): Vehicle(mode,yea){}
    void printDetails(){
        cout<<"Car Model: "<<model<<endl;
        cout<<"Car Year: "<<year<<endl;
    }
};

int main(){
    Car car("Lamborghini",2024);
    car.printDetails();
    return 0;
}