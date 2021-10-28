#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string itoa_v(int val, int base);
int atoi_v(string valstr, int base);

int main(int argc, char* argv[]) {
    if(argc < 3) return -1;

    int val = atoi(argv[1]);
    int base = atoi(argv[2]);

    string s = itoa_v(val, base);
    int v = atoi_v(s, base);
    cout << val << " in base " << base << ": " << s << endl;
    cout << s << " string base " << base << ": " << v << endl;
    return 1;
}

string itoa_v(int val, int base) {
    string s;
    vector<char> glyphs(64);
    unsigned uval = 0;

    int i = 0;
    for(; i < 10; i++) {
        glyphs[i] = '0' + i;
    }
    for(; i < 36; i++) {
        glyphs[i] = 'A' + i - 10;
    }
    for(; i < 62; i++) {
        glyphs[i] = 'a' + i - 10 - 26;
    }
    glyphs[62] = '-';
    glyphs[63] = '_';

    if(val == 0) {
        return "0";
    }
    if (base > 64 || base < 2) { 
        return "error";
    }

    int sign = 1;
    if(val < 0) {
        sign = -1;
    }
    uval = sign * val;

    //What needs to happen
    //take the val and get the remainder when divided by base
    //Index into the glyphs for that base, and push_front that character
    //divide the val by base. If not zero, continue.

    while(uval > 0) {
        int n = uval % base;
        uval = uval / base; 
        char g = glyphs[n];
        s = g + s;
    }

    if (sign == -1) {
        s = '-' + s;
    }

    return s;
}

int atoi_v(string valstr, int base = 10) {

    //What needs to happen
    //take the most significant char
    //find its int value by looking it up
    //multiply the current outVal by base, and add the new value
    //repeat until you get to end
    if(base < 2 || base > 64) { return -1;}

    int i = 0;
    vector<char> glyphs(256);

    for(; i < 10; i++) {
        glyphs['0' + i] = i;
    }
    for(; i < 36; i++) {
        glyphs['A' + i - 10] = i;
    }
    for(; i < 62; i++) {
        glyphs['a' + i - 10 - 26] = i;
    }
    glyphs['-'] = 62;
    glyphs['_'] = 63;

    int outVal = 0;
    for(int k = 0; k < valstr.length(); k++) {
        char g = valstr[k];
        int n = glyphs[g];
        outVal = n + outVal*base;
    }

    return outVal;
}