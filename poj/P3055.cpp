#include <stdio.h>
#include <iostream>
#include <string>
int t;
string a, b;
bool cmp(string a, string b) {
	int va = 0, vb = 0;
	for (int i = 0; i < a.size(); i++) {
		va |= 1 << a[i] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		vb |= 1 << a[i] - '0';
	}
	
}
int main() {


}