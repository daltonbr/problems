/* Virtual Functions
https://www.hackerrank.com/challenges/virtual-functions/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// For each object being created of the Professor or the Student class,
// sequential id's should be assigned to them starting from 1.
//Solve this problem using virtual functions, constructors and static variables.
// You can create more data members if you want.

//Person::id = 0;

class Person
{
    //int Person::id = 0;

    protected:        
        string name;
        int age;
    public:
        //Person();
        virtual void getdata()
        { cout<< "getdata base class" <<endl; }

        virtual void putdata()
        { cout<< "putdata base class" <<endl; }
};

class Professor : public Person
{    
    private:        
        int publications;
        int cur_id;

    public:
        Professor()
        {
            cout << "Professor created" << endl;
        }

        Professor (string _name, int _age, int _publications)
        {
            name = _name;
            age = _age;
            publications = _publications;
            //cur_id = Person::id;
        }

        void getdata()
        {
            cout<< "getdata Professor class: " <<endl;
            cin >> name;
            cin >> age;
            cin >> publications;
            // get name, age and publications
        }

        void putdata()
        {
            // print name, age, publications and cur_id                        
            cout << "putdata Professor class" << endl;                            
            cout << name << " " << age << " " << publications << endl;
            //cout << name << endl;
        }

};

class Student : public Person
{
    //int marks[]; // array of size 6. type?
    private:
       int cur_i;

    public:
        Student()
        {
            cout << "Student created" << endl;
        }

        Student (string _name, int _age)
        {
            name = _name;
            _age = age;
        }

        void getdata()
            {
                // get name, age and the marks
                cout<< "getdata Person class" <<endl;
                cin >> name;
                cin >> age;                
            }
            void putdata()
            {
                //print name, age, sum of the marks and the cur_id            
                cout << "putdata Student class" << endl;
                cout << name << " " << age << endl;
            }
};

// This code bellow is supplied and "locked"
// int main(){

//     int n, val;
//     cin>>n; //The number of objects that is going to be created.
//     Person *per[n];

//     for(int i = 0;i < n;i++){

//         cin>>val;
//         if(val == 1){
//             // If val is 1 current object is of type Professor
//             per[i] = new Professor;

//         }
//         else per[i] = new Student; // Else the current object is of type Student

//         per[i]->getdata(); // Get the data from the user.

//     }

//     for(int i=0;i<n;i++)
//         per[i]->putdata(); // Print the required output for each object.

//     return 0;

// }

int main()
{
    Person *Prof;
    Person *Stud;

    Prof = new Professor("Dalton", 35, 0);
    Stud = new Student("Jesse", 18);

    //Prof = new Professor;
    //Stud = new Student;

    Prof->putdata();
    Stud->putdata();

    Prof->getdata();
    Prof->putdata();

    Stud->getdata();
    Stud->putdata();
    return 0;
}