// Program 10-17: Using pointers to dynamically allocate structures
// and class objects.
#include <iostream>
#include <string>
using namespace std;

// Person class...
class Person
{
private:
	string name;
	int age;
public:
	Person(string name1, int age1)
	{
		name = name1;
		age = age1;
	}
	string getName() { return name; }
	int getAge() { return age; }
};

// Rectange structure...
struct Rectangle
{
	int width, height;
};

int main()
{
	Rectangle *pRect = nullptr;
	Person *pPerson = nullptr;

	// Local object passed through a pointer...
	Rectangle rect;
	pRect = &rect;
	(*pRect).height = 12;
	pRect->width = 10;
	cout << "Area of the 1st rectangle is "
		<< pRect->height * pRect->width;

	// Dynamically allocated object accessed through pointer...
	pRect = new Rectangle;
	pRect->height = 6;
	pRect->width = 5;
	cout << "\nArea of the 2nd rectangle is "
		<< pRect->height * pRect->width;
	delete pRect;
	pRect = nullptr;

	// Dynamically allocated object accessed through pointer...
	pPerson = new Person("Miguel E. Gonzalez", 73);
	cout << "\n\nThe person's name is " << pPerson->getName();
	cout << "\n The person's age is " << pPerson->getAge() << endl;
	delete pPerson;
	pPerson = nullptr;

	return 0;
}