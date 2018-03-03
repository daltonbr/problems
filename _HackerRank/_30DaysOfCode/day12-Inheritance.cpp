/*
https://www.hackerrank.com/challenges/30-inheritance/problem
*/

#include <iostream>
#include <vector>
using namespace std;

class Person
{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
        //Person() {};
		Person(string firstName, string lastName, int identification)
        {
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson()
        {
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student : public Person
{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student (string _firstName, string _lastName, int _id, vector<int> _testScores) :
        Person(_firstName, _lastName, _id), testScores(_testScores) {}

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        char calculate()
        {
            int sum = 0;
            for (int i = 0; i < testScores.size(); i++)
            {
                sum += testScores[i];
            }
            
            float average = (float)sum / (float)testScores.size();

            if (average >= 90) return 'O';
            if (average >= 80) return 'E';
            if (average >= 70) return 'A';
            if (average >= 55) return 'P';
            if (average >= 40) return 'D';
            return 'T';            
        }
};

int main()
{
	string firstName;
  	string lastName;
	int id;
  	int numScores;

	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	
    for(int i = 0; i < numScores; i++)
    {
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}

	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";

	return 0;
}