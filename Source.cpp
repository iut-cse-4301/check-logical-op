#include<iostream>

using namespace std;

class TestOP {
	bool res;
	int i;
	bool foo(int i);
public:
	TestOP() :i(-13) {}

	TestOP(int i) :i(i) {}
	TestOP(char* c) : i(strlen(c)) {}

	bool operator||(TestOP ob) {
		this->res = this->foo(this->i);
		this->res = this->foo(ob.i) || this->res;
		return this->res;
	}

	int operator+(TestOP ob) {
		return ob.i + this->i;
	}

	bool operator||(bool res) {
		this->res = this->foo(this->i);
		this->res = this->res || res;
		return this->res;
	}
	bool operator||(char* c) {
		this->res = this->foo(this->i);
		this->res = this->foo(strlen(c)) || this->res;
		return this->res;
	}


	bool operator&&(bool res) {
		this->res = this->foo(this->i);
		this->res = this->res && res;
		return this->res;
	}

	bool operator&&(TestOP ob) {
		this->res = this->foo(this->i);
		this->res = this->foo(ob.i) && this->res;
		return this->res;
	}

	friend bool operator||(bool res, TestOP ob);
	friend bool operator&&(bool res, TestOP ob);
};

bool operator||(bool res, TestOP ob) {
	ob.res = ob.foo(ob.i);
	ob.res = ob.res || res;
	return ob.res;
}


bool operator&&(bool res, TestOP ob) {
	ob.res = ob.foo(ob.i);
	ob.res = ob.res && res;
	return ob.res;
}


bool TestOP::foo(int i) {
	cout << i << ' ';
	return (i % 2) ? true : false;
}

int main() {

	TestOP ob1(1), ob2(2), ob5(5), ob3(3), ob4(4), ob6(6), ob8(8);
	if (ob1 && ob2 && ob3 || ob5 && ob3 || ob1) {
		cout << "\nevaluated\n";
	}

	if (ob3 || (char *)"ab") {
		cout << "\nevaluated\n";
	}
	cout << ob6 + (char *)"ab";

	getchar();
	return 0;
}