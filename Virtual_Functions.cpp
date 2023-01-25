#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class Professor : public Person{
    public:
        int publications;
        int cur_id;
        static int counter;
        Professor(){
            counter++;
            cur_id = counter;
        }
        void getdata(){
            cin >> name >> age >> publications;
        }
        void putdata(){
            cout << name << " " << age << " " << publications << " " << cur_id << "\n";
        }
};

class Student : public Person{
    public:
        int marks[6];
        int cur_id;
        static int counter;
        Student(){
            counter++;
            cur_id = counter;
        }
        int get_sum(){
            int sum = 0;
            for (int i=0; i<6; i++){
                sum += marks[i];
            }
            return sum;
        }
        void getdata(){
            cin >> name >> age;
            for (int i=0; i<6; i++){
                cin >> marks[i];
            }
        }
        void putdata(){
            cout << name << " " << age << " " << get_sum() << " " << cur_id << "\n";
        }
};

int Professor::counter = 0;
int Student::counter = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}