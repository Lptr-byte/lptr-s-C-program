#include <iostream>
using namespace std;
int temp[20], n;

int Hash(){
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(temp[i])
			res += (1 << (i - 1));
	return res;
}

int main(){
	int a = (1 << 3);
	printf("%d\n", a);
	cin >> n;
	for(int i = 1; i <= 15; i++){
		temp[i] = !temp[i];
		for(int i = 1; i <= 15; i++)
			cout << temp[i];
		cout << endl;
		cout << Hash() << endl;
		printf("%d\n", Hash());
	}
	return 0;
}
