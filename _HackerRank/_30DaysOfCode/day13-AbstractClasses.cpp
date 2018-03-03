/*
https://www.hackerrank.com/challenges/30-abstract-classes/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// supplied class
class Book
{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a)
        {
            title=t;
            author=a;
        }
        virtual void display()=0;

};

// Write your MyBook class here
class MyBook : public Book
{
    private:
        int price;
    public:
    //   Class Constructor
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
        MyBook(string _title, string _author, int _price) :
            Book(_title, _author)
        {
            // this->title = _title;
            // this->author = _author;
            this->price = _price;
        }
        
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    void display()
    {
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Price: " << this->price << endl;
    }

};

// supplied code stub
int main()
{
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}
