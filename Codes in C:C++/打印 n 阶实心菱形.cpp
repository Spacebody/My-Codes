/**
 * @author Spacenbody
 */

/*
	要求输出 n 阶实心菱形，仔细观察，分成上下两部分，
	前面 n 行用一个 (1)for 循环输出，
	后面 n-1 行用 (2)for 循环输出，
	下面会详细说明，当然该算法有很多值得改进的地方。	
 */

#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n; //要输入的值
	if(n <= 10 ) { //首先判断，题目要求 n<=10，如果错误，就执行 else 块内的的语句
		for (int i = 1; i <= n; i++) { //这是 (1)for，嵌套着两个小的 for循环
			for (int m = 0; m < n - i; m++) { //该循环用于输出空格
				cout << " "; 
			}
			for (int p = 0; p < 2 * i - 1; p++) { //该循环用于输出“*”
				cout << "*";
			}
			cout << "\n"; //执行完以上两个小的 for 循环之后，一行就输出完了，这时候要换行
		}  

		/*
			以上的循环次数等可以通过列表找到对应的关系，规律不难找。
		 */
		for (int i = n - 1; i > 0; i--) { 
			for (int m = 0; m < n - i; m++) {
				cout << " ";
			}
			for (int p = 0; p < 2 * i - 1; p++) {
				cout << "*";
			}
			cout << "\n";
		}
	}else{
		cout<<"Error"<<endl; //n 如果大于10，输出错误
	}

	return 0;
}