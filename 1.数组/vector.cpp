#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<int>& v) {
	for (vector<int>::iterator it =v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}
void remove1(vector<int>& v, int index) {
	v.erase(v.begin() + index);//本质是通过移动大量的数据 后面覆盖前面 效率低
}
void remove2(vector<int>& v, int index) {
	swap(v[index], v.back());
	v.pop_back();
}
int main() {
	vector<int> v = { 2,4,0,8 };
	cout << v.capacity() << endl;
	v.push_back(7);
	cout << v.capacity() << endl;
	cout << "begin:->" << *v.begin() << endl;
	cout << "end:->" << *(v.end() - 1) << endl;

	cout << "front:" << v.front() << endl;
	cout << "back:" << v.back() << endl;

//1.插入 push_back 尾部插入 insert 传入的是迭代器  迭代器相当于指针
	vector<int> v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	v1.insert(v1.begin(), 8);
	v1.insert(v1.begin() + 1, 9);
//2.删除 pop_back 尾部删除  erase 和insert一样 clear 全部删除
	v1.pop_back();

	v1.erase(v1.begin() + 1);
 
//3.capacity 是容量 size 是大小
	vector<int> v2 = { 985,211 };
	printVector(v2);
	cout << "v2.size:" << v2.size() << endl;
	cout << "v2.capacity:" << v2.capacity() << endl;
	 
	//capacity 按1.5被扩容 是向下取整 3*1.5=4.5 capacity是4
	v2.push_back(3);
	cout << "v2.size:" << v2.size() << endl;
	cout << "v2.capacity:" << v2.capacity() << endl;
  //这里有一个判断  如果你的size是小于newcapacity的 那么返回newcapacity 反之容量大小为size 这样效率更快
	//入伙resize在变小 capacity并不会缩容
	v2.resize(18);
	cout << "v2.size:" << v2.size() << endl;
	cout << "v2.capacity:" << v2.capacity() << endl;

 //4.swap 内存交换 是直接呼唤内存
	vector<int> v3 = { 2,4,0,8 };
	vector<int> v4= { 5,6,7,8,9 };

	v3.swap(v4);
	printVector(v3);
	printVector(v4);
	cout << v3.capacity() << endl;
	cout << v4.capacity() << endl;
//缩容
	v3.resize(1000);
	v3.resize(6);
	cout << v3.capacity() << endl;
	vector<int>x(v3);//拷贝函数 会拷贝size大小
	cout << x.capacity() << endl;
	vector<int>(v3).swap(v3);//匿名函数 相当于省略了x
	cout << v3.capacity() << endl;

// 内存清理  clear并不会清理内存 只会把size变小

	v3.clear(); 
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;
	vector<int>({}).swap(v3);

	cout<< v3.capacity() << endl;
// 5.空间预留 reserve 提前分配空间  提高效率  reserce 修改capacity resize 修改size
// 

	vector<int> v5;
	v5.reserve(100); 
	cout << v5.capacity() << endl;
// 6.高效删除 同样也可以高效插入 但是只能用于 不要求顺序
	
	remove1(v3, 2);//时间复杂是On 
	remove2(v3,2);//时间复杂是1
//7.数据排序
	bool cmp(int a, int b) {

		return a > b;// > 递减排序 < 递增排序  默认递增排序
	 }
	sort(v3.begin(), v3.end(), cmp);



	return 0;
}