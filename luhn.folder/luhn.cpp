#include "luhn.h"

bool isValidFormat(char card[])
{
    bool valid = true;
    int i = 0;
    while (card[i] != '\0')
    {
        if (card[i] < '0' || card[i] > '9')
        {
            valid = false;
        }
        i++;
    }
    if (i != 16)
    {
        valid = false;
    }
    return valid;
}

bool checkLuhn(char card[])
{
    // Go from right to left, double every second digit
    int sum = 0;
    int i = 15;
    while (i >= 0)
    {
        int digit = card[i] - '0';
        if ((15 - i) % 2 == 1)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                digit = digit - 9;
            }
        }
        sum = sum + digit;
        i--;
    }
    return sum % 10 == 0;
}
