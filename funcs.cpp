#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <cfloat>
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

// Caesar cipher decryption
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

//find distance
double distance(std::vector<double> engFreq, std::vector<double> wordFreq)
{
    double d = 0.0;

    for(int i = 0; i < 26; i++)
    {
        d += (engFreq[i] - wordFreq[i])*(engFreq[i] - wordFreq[i]);
    }
    d = sqrt(d);
    
    return d;
}

int letterIndex(char c)
{
    int lowerLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int upperLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for(int j = 0; j < 26; j++)
    {
        if(isupper(c))
        {
            if(c == upperLetters[j])
            {
                return j;
            }

        }

        else
        {
            if(c == lowerLetters[j])
            {
                return j;
            }
        }
    }
    return 26; //for non-letters
}

int phraseLetters(std::string s)
{
    int num = 0;

    for(int j=0; j<s.length(); j++)
    {
        if(isalpha(s[j])) //excluding special characters
        {
            num++;
        }
    }
    return num;
}

std::string solve(std::string encrypted_string)
{
    std::string shifted_strings[26];
    std::vector<double> englishFrequencies = {0.082, 0.015, 0.027, 0.047, 0.13, 0.022, 0.02, 0.062, 0.069, 0.0016, 
                                                0.0081, 0.04, 0.027, 0.067, 0.078, 0.019, 0.0011, 0.059, 0.062, 
                                                0.096, 0.027, 0.0097, 0.024, 0.0015, 0.02, 0.0078};
    std::vector<double> letterFrequencies = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
                                            0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    int numLetters = phraseLetters(encrypted_string);
    int index = 0;
    double min = DBL_MAX;
    double mins[26];
    int currIndex = 0;
    int minIndex = 0;

    for(int i=0; i<26; i++)
    {
        for(int j=0; j<encrypted_string.length(); j++)
        {
            if(isalpha(encrypted_string[j])) //excluding special characters
            {
                index = letterIndex(encrypted_string[j]);
                letterFrequencies[index] += 1.0;
            }
        }

        for(int k=0; k<26; k++)
        {
            letterFrequencies[k] = letterFrequencies[k] / numLetters;
        }

        if(distance(englishFrequencies, letterFrequencies) < min)
        {
            min = distance(englishFrequencies, letterFrequencies);
            mins[currIndex] = min;
            shifted_strings[currIndex] = encrypted_string;
            currIndex++;
        }
         encrypted_string = encryptCaesar(encrypted_string, 1);
    }

    for(int p = 0; p < 26; p++)
    {
        if(min == mins[p])
        {
            minIndex = p;
        }
    }

    return shifted_strings[minIndex];
    return "";
}