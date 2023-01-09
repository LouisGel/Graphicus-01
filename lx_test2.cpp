// C++ program to create an array of
// objects and deleting it explicitly
#include <iostream>
using namespace std;

// Class
class Student
{

public:
    // Constructor
    Student()
    {
        cout << "Constructor is called!\n";
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor is called!\n";
    }

    // Function to display message
    void write()
    {
        cout << "Writing!\n";
    }
};

// Driver Code
int main()
{
    // Create an array of the object
    // dynamically
    Student *student = new Student[3];

    // Function Call to write()
    student[0].write();
    student[1].write();
    student[2].write();

    // De-allocate the memory
    // explicitly
    delete[] student;

    return 0;
}