#include<iostream>
#include<string>
using namespace std;
const int N = 100;
int a[N], n;
char b[N], m;

int main() {
	
	
	char ch = getchar();
	while (ch != '\n') {
		if ('0' <= ch && ch <= '9') {
			int x = 0;
			while ('0' <= ch && ch <= '9')
				x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
			a[n++] = x;
		}
		else if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
			b[m++] = ch, ch = getchar();
		else ch = getchar();
	}
	for (int i = 0; i < n; i++) {
		if (i != n - 1)
			cout << a[i] << " ";
		else
			cout << a[i] << endl;
	}
		
	
	/*for (int i = 0; i < m; i++)
		cout << b[i] << " ";*/
	return 0;

}

