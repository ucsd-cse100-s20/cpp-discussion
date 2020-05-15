#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {

    /* &  : bitwise AND
     * |  : bitwise OR
     * ^  : bitwise XOR
     * >> : logicial shift right
     * << : logical shift left
     */


    // ascii-encoded representation
    unsigned char c1 = 65;    // 01000001 = 0x41 = 65, ascii - 'A'
    bitset<8> c1_bits(c1);
    cout << c1 << " : " << c1_bits << endl;

    // logicial shift left example
    unsigned char c2 = 0x3d;  // 00111101 = 0x3d = 61, ascii - '='
    bitset<8> c2_bits_before(c2);
    cout << c2 << " : " << c2_bits_before << endl;
    c2 <<= 1;                 // c2 = c2 LSL 1        01111010 = 0x7a = 122, ascii - 'z'
    bitset<8> c2_bits_shifted(c2);
    cout << c2 << " : " << c2_bits_shifted << " is equal to "<< c2_bits_before << " << 1" << endl;

    // XOR example
    unsigned char c3 = 0x57;
    bitset<8> c3_bits_before(c3);
    cout << c3 << " : " << c3_bits_before << endl;
    c3 ^= c2;                 // c3 = c3 XOR c2        
    bitset<8> c3_bits_xored(c3);
    cout << c3 << " : " << c3_bits_xored << " is equal to "<< c3_bits_before << " ^ " << c2_bits_shifted << endl;

    // AND examples
    unsigned char c4= 0b00110101;
    bitset<8> c4_bits_before(c4);
    cout << c4 << " : " << c4_bits_before << endl;
    unsigned char c4And1 = c4 & 1;                 // c4And1 = c4 & 00000001        
    bitset<8> c4_bits_and_1(c4And1);
    cout << c4And1 << " : " << c4_bits_and_1 << " is equal to "<< c4_bits_before << " & 1" << endl;
    unsigned char c4And0 = c4 & 0;                 // c4And0 = c4 & 00000000        
    bitset<8> c4_bits_and_0(c4And0);
    cout << c4And0 << " : " << c4_bits_and_0 << " is equal to "<< c4_bits_before << " & 0" << endl;


    // indexing using a char
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }

    int n = arr['0'];                 // '0' in decimal is 48, so this really does: int n = arr[48];
    cout << "n is : " << n << endl;   // n is 48
}
