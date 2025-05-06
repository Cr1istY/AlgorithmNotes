// 01_数组 - 定义一个可扩容的数组

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

// 双指针，解决字符串逆序的问题
void Reverse(char arr[], int size) {
	char* p = arr;
	char* q = arr + size - 1;
	while (p < q) {
		*p = *p ^ *q;
		*q = *p ^ *q;
		*p = *p ^ *q;
		p++;
		q--;
	}
}

void main() {
	char arr[] = "hello, world!";
	Reverse(arr, strlen(arr));
	cout << arr << endl;
}



#if 0
class Array {
public:
	Array(int size = 10) : mCur(0), mCap_(size) {
		mpArr = new int[mCap_]();
	}
	
	~Array() {
		delete[]mpArr;
		mpArr = nullptr;
	}

public:
	void pushBack(int val) {
		//if (mCap_ == mCur) {
		//	expand(2 * mCap_);
		//}
		checkCap();
		mpArr[mCur] = val;
		mCur++;
	}
	// 末尾增加元素
	void popBack() {
		if (mCur > 0) {
			mCur--;
		}
		else {
			return;
		}
	}
	// 末尾删除元素
	void insert(int pos, int val) {
		if (pos < 0 || pos > mCur) {
			throw "pop in invalid!";
		}
		checkCap();
		for (int i = mCur - 1; i >= pos; i--) {
			mpArr[i + 1] = mpArr[i];
		}
		mpArr[pos] = val;
		mCur++;
	}
	// 按位置增加元素
	void erase(int pos) {
		if (pos >= mCur || pos < 0) {
			return;
		}
		for (int i = pos; i < mCur - 1; i++) {
			mpArr[i] = mpArr[i + 1];
		}
		mCur--;
	}
	// 根据位置删除
	int find(int val) {
		for (int i = 0; i < mCur; i++) {
			if (mpArr[i] == val) {
				return i;
			}
		}
		return -1;
	}
	// 查询，返回下标
	// 打印元素
	void show() {
		for (int i = 0; i < mCur; i++) {
			cout << mpArr[i] << "   ";
		}
		cout << endl;
	}

private:
	// 内部数组扩容
	void expand(int size) {
		int* p = new int[size];
		memcpy(p, mpArr, sizeof(int) * mCap_);
		delete[]mpArr;
		mpArr = p;
		mCap_ = size;
	}	
	void checkCap() {
		if (mCap_ == mCur) {
			expand(2 * mCap_);
		}
		else return;
	}
private:
	int* mpArr; // 堆上开辟的空间
	int mCap_;	// 数组的容量
	int mCur;	// 当前元素个数
};


int main(void) {
	Array arr;

	srand(time(0));
	for (int i = 0; i < 10; i++) {
		arr.pushBack(rand() % 100);

	}

	arr.show();
	
}
#endif


