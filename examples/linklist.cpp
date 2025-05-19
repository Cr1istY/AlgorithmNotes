#include <iostream>
#include <time.h>

using namespace std;

struct Node {
	Node(int data = 0) :data_(data), next_(nullptr) {};
	int data_;
	Node* next_;
};

class Clink {
public:
	Clink() {
		head_ = new Node();
	}

	~Clink() {



	}

public:
	// 尾插法
	void insertTail(int val) {
		// 先找到链表的末尾节点，再生成新节点。

		Node* p = head_;

		while (p->next_ != nullptr) {
			p = p->next_;
		}

		Node* node = new Node(val);
		p ->next_ = node;
	}

	// 头插法
	void insertHead(int val) {
		Node* node = new Node(val);
		Node* p = head_->next_;
		head_->next_ = node;
		node->next_ = p;
	}

	// 链表打印
	void showLinkList() {
		Node* p = head_->next_;
		while (p != nullptr) {
			cout << p->data_ << "  ";
			p = p->next_;
		}
		if (head_->next_ == nullptr) {
			cout << "the linkList in empty!";
		}

	}

	// 按值删除链表的节点
	bool deleteNode(int val) {
		Node* p = head_->next_;
		Node* q = head_;
		while (p != nullptr) {
			if (p->data_ == val) {
				q->next_ = p->next_;
				delete p;
				return true;
			}
			else {
				p = p->next_;
				q = q->next_;
			}
		}
		return false;
	}
	void removeAllNode(int val) {
		while (deleteNode(val)) {
		}
	}

	void searchNode(int val) {
		Node* q = head_->next_;
		int locate = 0;
		while (q != nullptr) {
			if (q->data_ == val) {
				cout << locate << " ";
			}
			locate++;
			q = q->next_;
		}
	}


private:
	Node* head_;

};

int main() {
	Clink link;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int val = rand() % 100;
		link.insertTail(val);
		cout << val << "  ";
	}
	link.insertHead(1);
	link.insertHead(1);
	cout << endl;

	link.showLinkList();
	
	cout << endl;

	int j = 0;
	while (j >= 0) {
		cin >> j;
		link.searchNode(j);
		link.showLinkList();
	}
	
	
	return 0;
}

