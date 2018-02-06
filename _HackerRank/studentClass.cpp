/* Concepts: class, getters, setters, stringstream
https://www.hackerrank.com/challenges/c-tutorial-class/problem
*/

#include <iostream>
#include <sstream>
using namespace std;

class Student
{
    private:
        int _age;
        string _first_name;
        string _last_name;
        int _standard;
    public:
        void set_age(int age)
        {
            _age = age;
        }
    
        int get_age()
        {
            return _age;
        }
    
        void set_first_name(string first_name)
        {
            _first_name = first_name;
        }
    
        string get_first_name()
        {
            return _first_name;
        }
    
        void set_last_name(string last_name)
        {
            _last_name = last_name;
        }
    
        string get_last_name()
        {
            return _last_name;
        }
    
        void set_standard(int standard)
        {
            _standard = standard;
        }
    
        int get_standard()
        {
            return _standard;
        }
    
        string to_string()
        {
            ostringstream output_ss;   // output stream
            output_ss << _age << "," << _first_name << "," << _last_name << "," << _standard;            
            return output_ss.str();
        }
};

int main()
{
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
