#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) return 0;
	//  n cannot be an even number

	int **p = new int*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[n];
    }
    //  create a dynamic array to place the numbers

    int x = 0, y = n / 2;
    for (int i = 1; i <= n * n; i++) {
    	p[x][y] = i;
    	if (i % n != 0) {
    		x--;
    		y++;
    		if (x < 0)
    			x += n;
    		if (y >= n)
    			y = n - y;
    	} else {
    		x++;
    		if (x == n) x = x - n;
    	}
    }
    //  put the numbers according to the method

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        	cout << p[i][j];
        	if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
    //  print the magic square generated

    for (int i = 0; i < n; i++) {
        delete [] p[i];
    }
    delete [] p;
    //  delete the array
	return 0;
} 
