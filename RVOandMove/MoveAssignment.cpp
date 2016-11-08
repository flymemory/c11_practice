#include <iostream>
#include <vector>

using namespace std;

struct OPTest
{
public:
	int x, y, z;

	OPTest() { cout << "constructor" << endl; }
	OPTest(OPTest &) { cout << "copied" << endl; }
	OPTest(OPTest &&) { cout << "moved" << endl; }
	OPTest(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
	~OPTest() { cout << "destructor" << endl; }

	//OPTest operator +(OPTest& b) { 
	//	x += b.x; y += b.y; z += b.z;  
	//	cout << "1" << endl;
	//	OPTest result = *this;
	//	return result;
	//}
	//OPTest operator +(OPTest&& b) {
	//	x += b.x; y += b.y; z += b.z; 
	//	cout << "2" << endl;
	//	return *this;
	//}

};


OPTest operator +(const OPTest& a, const OPTest& b)
{
	OPTest result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;

	return result;
}




int main()
{
	OPTest a{ 1,1,1 };
	OPTest b{ 2, 3, 4 };
	OPTest aa{ 2, 3, 4 };

	cout << "--------------" << endl;

	OPTest c = a + b + aa;

	cout << a.x << endl;


	

	return 0;
}