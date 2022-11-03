#include <iostream>
#include "funcs.h"

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift)
{
    if(rshift < 0)
    {
        while(rshift < 0)
        {
            rshift += 26;
        }
    }

    int place = int(c);
    
    for(int i=0; i < rshift; i++)
    {
        place += 1;

        if(c >= 'A' && c <= 'Z' && place > 90)
        {
            place = 65;
        }

        if(c >= 'a' && c <= 'z' && place > 122)
        {
            place = 97;
        }
    }
    return char(place);
}

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift)
{
    if(rshift < 0)
    {
        while(rshift < 0)
        {
            rshift += 26;
        }
    }

    std::string s = "";
    for(int i=0; i<plaintext.length(); i++)
    {
        char newChar = plaintext[i];
        if(isalpha(newChar))
        {
            newChar = shiftChar(plaintext[i], rshift);
        }
        s += newChar;
    }

    return s;
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
    int newShift = 0;

    while (newShift < rshift)
    {
        newShift += 26;
    }

    newShift -= rshift;

    std::string s = "";
    for(int i=0; i<ciphertext.length(); i++)
    {
        char newChar = ciphertext[i];
        if(isalpha(newChar))
        {
            newChar = shiftChar(ciphertext[i], newShift);
        }
        s += newChar;
    }

    return s;
}

