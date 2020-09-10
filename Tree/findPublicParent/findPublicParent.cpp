// write your code here cpp
#include<iostream>

using namespace std;

void findPublicParent()
{
	int i(0), j(0);
    
    while(cin >> i >> j){
        while (i != j)
	    {
		    i > j ? i >>= 1 : j >>= 1;
	    }
	    cout << i << endl;
    }
}

int main()
{
    findPublicParent();
    return 0;
}


