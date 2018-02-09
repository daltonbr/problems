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

/*c++17 inline*/const int MARKS_ARRAY_SIZE = 6;

class Person
{
    protected:
        int cur_id;
        string name;
        int age;
    public:
        virtual void getdata() {};
        virtual void putdata() {};
};

class Professor : public Person
{
    private:        
        int publications;
        static int id;

    public:
        Professor() { cur_id = id++; }

        Professor (string _name, int _age, int _publications)
        {
            name = _name;
            age = _age;
            publications = _publications;            
        }

        // get name, age and publications
        void getdata()
        {
            cin >> name;
            cin >> age;
            cin >> publications;
        }

        // print name, age, publications and cur_id
        void putdata()
        {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;            
        }
};

class Student : public Person
{
    private:
        int marks[MARKS_ARRAY_SIZE];
        static int id;

        int marksSum()
        {
            int sum = 0;
            for (int i = 0; i < MARKS_ARRAY_SIZE; i++)
            { sum += marks[i]; }
            return sum;
        }

    public:
        Student() { cur_id = id++; }

        Student (string _name, int _age)
        {
            name = _name;
            _age = age;
        }

        // get name, age and the marks
        void getdata()
        {
            cin >> name;
            cin >> age;
            for (int i = 0; i < MARKS_ARRAY_SIZE; i++) { cin >> marks[i]; }
        }

        //print name, age, sum of the marks and the cur_id
        void putdata()
        {
            cout << name << " " << age << " " << marksSum() << " " << cur_id << endl;
        }
};

// Initializing static variables (must be outside of the class)
int Professor::id = 1;
int Student::id = 1;

// This code bellow is supplied and "locked"
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
