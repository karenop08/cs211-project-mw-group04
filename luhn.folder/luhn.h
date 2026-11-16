#ifndef LUHN_H
#define LUHN_H

// Returns true if the text is exactly 16 characters and all are digits
bool isValidFormat(char card[]);

// Returns true if the 16-digit number passes the Luhn checksum
bool checkLuhn(char card[]);

#endif
