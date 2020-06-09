#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;


bool isPalindrome(string line) {
	size_t length = line.length();

	for(size_t i = 0; i < length/2; i++){
		if (line[i] != line[length - i - 1]) {
			return false;
		}
		else return true;
	}
}

int main() {

    string line;

    ifstream in("file.txt");
    if (in.is_open())
    {
        getline(in, line);
    }
    in.close();

    string line2 = line;
    
    line2.erase(remove_if(line2.begin(), line2.end(), not1(ptr_fun(isalpha))), line2.end());
    transform(line2.begin(), line2.end(), line2.begin(), tolower);

    
    if (isPalindrome(line2))
        cout << "phrase " << line << " is palindrome";
    else 
        cout << "phrase " << line << " isn't palindrome";
    
	return 0;
}