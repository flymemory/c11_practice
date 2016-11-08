// RVOandMove.cpp : Defines the entry point for the console application.
// This part is test Return Value Optimized and std::move
#include <iostream>
#include <vector>

using namespace std;

struct BigHugeObj
{
	int a = 0;
	BigHugeObj() { cout << "constructor" << endl; }
	BigHugeObj(BigHugeObj&) { cout << "copy constructor" << endl; }
	BigHugeObj(BigHugeObj&& b) { cout << "moved" << endl;  a = b.a; }
	~BigHugeObj() { cout << "destructor" << endl; }
};

BigHugeObj GetBigHugeObj(int condition)
{
	BigHugeObj aObj;

	aObj.a = 1;

	return aObj;


}

vector<BigHugeObj> GetBigHugeObjArray(int condition)
{
	int aa = 11;
	vector<BigHugeObj> BOs = vector<BigHugeObj>(1);
	vector<BigHugeObj> bBOs = vector<BigHugeObj>(1);
	int a = 1;

	if (condition > 1)
	{
		BOs[0].a = 2;
		return BOs;
	}
	else
	{
		bBOs[0].a = 3;
		return bBOs;
	}
}

//int main()
//{
//	// When you need move assignment at user-defined type, add the && constructor.
//	BigHugeObj o = GetBigHugeObj(1);
//	cout << o.a << endl;
//
//	// All standard container support RVO.
//	//vector<BigHugeObj> os = GetBigHugeObjArray(1);
//	//cout << os[0].a << endl;
//
//	cout << "-------------------------" << endl;
//	BigHugeObj oo = o;
//
//	return 0;
//}
//
