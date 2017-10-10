#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

//class to create an array
class IntArray 
{
    public:
        IntArray(int size);
        ~IntArray();
        int & operator[](int i) const;
        int size() const;
        void fill(int k);
        int * begin();
        int * end();

    private:
        int len;
        int * data;
};

//First, Class will allow access to main function to use IntArray to create new array and determine how large the array will be . 
//Second, Initializes data pointer to become an array, not sure yet. 
IntArray::IntArray(int size) 
{
    len = size;
    data = new int[size];
}

//initializes the IntArray Constructor
IntArray::~IntArray() 
{
}

//overloading index operator to search array for i, still confused on operators.. 
int & IntArray::operator[](int i) const
{
    return data[i];
}

//saves the constant length of the array
int IntArray::size() const
{
    return len;
}

//allows the storing of values inside the index of array type. It fills all index spots with same number in constructed array
void IntArray::fill(int n) 
{
    for (int i = 0; i < len ; i++) 
    {
        data[i] = n;
    }
}

//pointers used on begin & end functions to allows reference to personal array,Pointers will be used to test if they function properly in main.
int * IntArray::begin() 
{
    return data;
}

//will be used to test if pointers function 
int * IntArray::end() 
{
    return data + len;
}


int main(int argc, char * args[]) 
{
        IntArray a(3);

        a[0] = 10;
        a[1] = 11;
        a[2] = 12;

        assert(a[0] == 10);
        assert(a[1] == 11);
        assert(a[2] == 12);
        assert(a.size() == 3);
        a.fill(5);
        assert(a[0] == 5);
        assert(a[1] == 5);
        assert(a[2] == 5);
        a[0] = 3;
        a[1] = 1;
        a[2] = 2;
        sort(a.begin(), a.end());
        assert(a[0] == 1);
        assert(a[1] == 2);
        assert(a[2] == 3);
        int * it = a.begin();
        assert(*it == 1);
        ++it;
        assert(*it == 2);
        ++it;
        assert(*it == 3);
        ++it;
        assert(it == a.end());

        cout << "All tests passed." << endl;
        
        return 0;
}
