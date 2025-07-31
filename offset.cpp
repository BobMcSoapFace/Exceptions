#include <cctype>
#include <iostream>
using namespace std;

// empty exception class declarations
class invalidCharacterException {};
class invalidRangeException {};

char character(char start, int offset){
    if(!isalpha(start)){
        throw invalidCharacterException();
    }
    bool charUpper = isupper(start);
    start = tolower(start);
    if(start + offset < 'a' || start + offset > 'z'){
        throw invalidRangeException();
    }
    return charUpper ? toupper(start + offset) : start + offset; 
}
int main(){
    try {
        cout << "1" << ". " << character('Z', -1) << endl;
        cout << "2" << ". " << character('a', 5) << endl;
        cout << "3" << ". " << character('y', 4) << endl;
    } catch(invalidRangeException){
        cout << "Invalid range!" << endl;
    } catch(invalidCharacterException) {
        cout << "Invalid character!" << endl;
    }
    
    return 0;
}