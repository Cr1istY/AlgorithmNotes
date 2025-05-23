#include <iostream>

using namespace std;

class BinarySearch {
/*
* 0. 前提，数组必须是有序的（假设它是正序）
* 1. 先得出数组的整体大小
* 2. 从中间开始比较，若要找的数字比中间值大，则将头指针移到中间值
* 3. 返回第一步
*/
public:
	int search(int arr[], int i, int size) {
		int max = size - 1;
		int min = 0;
		int mid = (max + min) / 2;
		while (max >= min) {
			if (arr[mid] == i) {
				return mid;
			}
			else if (arr[mid] < i) {
				min = mid + 1;
				mid = (max + min) / 2;
			}
			else if (arr[mid] > i) {
				max = mid - 1;
				mid = (max + min) / 2;
			}
		}
		return -1;


	}

};


#if 0
int main() {
	BinarySearch bs;
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int j = bs.search(arr, -1, 10);
	cout << j << endl;

	return 0;
}
#endif

