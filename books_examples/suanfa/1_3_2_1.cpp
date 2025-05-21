/*
* 定容栈：
* 实现以下方法：
* void push(Item item) - 添加元素
* Item pop() - 出栈一个元素
* boolean isEmpty() - 检验栈是否为空
* int size() - 查看栈有多少元素
*/
#include<iostream>
using namespace std;


template<typename T>
class EasyStack {
private:
	T* arr; // 存储栈元素的数组
	int top; // 栈顶指针
	int length; // 栈的容量
public:

	EasyStack(int l) {
		length = l;
		arr = new T[length];
		top = -1; // 初始化栈为空
	}
	~EasyStack() {
		delete arr;
	}


public:
	void push(T item) {
		if (top == length - 1) {
			cout << "Stack Overflow!" << endl;
			return;
		}
		
		top += 1;
		arr[top] = item;
	}

	T pop() {
		if (top == -1) {
			cout << "Stack is Empty!" << endl;
			return -1;
		}
		int temp = top;
		top -= 1;
		return arr[temp];
	}

	bool isEmpty() {
		return top == -1;
	}

	int size() {
		return top + 1;
	}
};

#if 1

int main() {
	EasyStack<int> es(5);
	es.push(5);
	es.push(4);
	es.push(3);
	es.push(2);
	es.push(1);

	cout << es.isEmpty() << endl;

	for (int i = 0; i < 5; i++) {
		cout << es.pop() << endl;
	}
	cout << es.isEmpty() << endl;
	
}


#endif


