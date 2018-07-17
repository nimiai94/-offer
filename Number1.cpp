// Number1.cpp: 定义控制台应用程序的入口点。
//类的大小的计算，实际是类的对象的大小的计算。1、对齐。2、空类定义大小为1，但是当空类被继承时，不算大小；当空类被当成普通数据成员时，大小为1。3、类的对象的大小和成员函数和静态成员无关，因为这些东西是类所有对象共有的。4、当类中含有虚函数或者虚继承时，类保留一份虚函数表，类对象复制一份虚函数表指针。

#include "stdafx.h"

class A {

};
class B {
	char c;
	virtual int func(){}
};
class C {
	char c;
	virtual int func1() {}
	virtual int func2(){}
};
class D :public B, public C {
	//char C;
	A aa;
	virtual int func() {}
	virtual int func2() {}
	virtual int func3() {}
	
};
int main()
{
	printf("A %d\n", sizeof(A));
	printf("B %d\n", sizeof(B));
	printf("C %d\n", sizeof(C));
	printf("D %d\n", sizeof(D));
	getchar();
    return 0;
}

