/*
https://www.hackerrank.com/challenges/box-it/problem
*/

#include<bits/stdc++.h>

using namespace std;

//Implement the class Box  
class Box
{
    //l,b,h are integers representing the dimensions of the box
    private:
        int length, breadth, height;

    public:            
        Box()
        {
            this->length = 0;
            this->breadth = 0;
            this->height = 0;
        }

        Box(int _length, int _breadth, int _height)
        {
            this->length = _length;
            this->breadth = _breadth;
            this->height = _height;
        }
        
        // could be auto generated - copy constructor
        Box(const Box& other)
        {
            this->length = other.length;
            this->breadth = other.breadth;
            this->height = other.height;
        }

        int getLength() { return this->length; }

        int getBreadth() { return this->breadth; }
        
        int getHeight () {return this->height; }

        // Return the volume of the box
        long long CalculateVolume() { return (long long)length * breadth * height; }

        //Overload operator < as specified
        bool operator<(Box& b)
        {
            if ((*this).length < b.length)
            {
                return true;
            }

            if ((*this).breadth < b.breadth && (*this).length == b.length)
            {
                return true;
            }

            if ((*this).height < b.height && (*this).breadth == b.breadth && (*this).length == b.length)
            {
                return true;
            }
            return false;
        }
        
        friend ostream& operator<<(ostream& out, Box& B)
        {
            out << B.length << " " << B.breadth << " " << B.height;
            return out;
        }

};

// suplied code stub
void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}