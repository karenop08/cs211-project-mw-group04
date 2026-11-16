#include <iostream>
using namespace std;

int main()
{
    char card[100];

    cout << "Luhn checksum checker\n";
    cout << "Enter a 16-digit number (q to quit): ";

    while (cin >> card)
    {
        // Throw away the rest of the line (extra spaces or words)
        cin.ignore(1000, '\n');

        // Quit if the input is exactly q
        if (card[0] == 'q')
        {
            if (card[1] == '\0')
            {
                cout << "Goodbye.\n";
                return 0;
            }
        }

        // Format check: exactly 16 characters and all of them digits
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

        if (valid == false)
        {
            cout << "Input format error: enter exactly 16 digits (0-9), no spaces.\n";
        }
        else
        {
            // Luhn check: go from right to left, double every second digit
            int sum = 0;
            i = 15;
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

            if (sum % 10 == 0)
            {
                cout << "Format OK. Luhn checksum passes.\n";
            }
            else
            {
                cout << "Format OK. Luhn checksum fails.\n";
            }
        }
        cout << "Enter a 16-digit number (q to quit): ";
    }

    cout << "\nGoodbye.\n";
    return 0;
}
