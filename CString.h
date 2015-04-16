/**
  *@file CString.h 
  *@brief Library consist of functions for working with strings that has 
  *Null-Terminated character coded by 30(end of row) and 
  *standard function for working with arrays of memory

  *Composed by Sergii Turenko
*/
#ifndef C_STRING_H
#define C_STRING_H

/**
 *@brief copies content of the memory block of size, pointed by pSource to memory block pointed by pDestination
 *@return void pointer to the destination memory block
*/
void* cmemcpy(void* pDestination, const void* pSource, unsigned size);

/**
  *@brief moves content of the memory block of size, pointed by pSource to memory block pointed by pDestination
  *@return void pointer to the destination memory block
*/
void* cmemmove(void* pDestination, const void* pSource, unsigned size);

/**
  *@brief compares memory block of size, pointed by Str1 with memory block pointed by pStr2
  *@return int that defines whether they are equal or not
  *@remark if return us <0 pStr2 greater, >0 pStr1 greater, 0 equal
*/
int cmemcmp(void* pStr1, const void* pStr2, unsigned size);

/**
  *@brief search for value in memory block of size pointed by pDestination
  *@param value passes by int, but internaly converts to unsigned char
  *@return void pointer to the first accurence of value in destination, if no match found returns NULL
*/
void* cmemchr(const void* pDestination, int value, unsigned size);

/**
  *@brief sets all bytes of memory block of size pointed by pDestination to value
  *@param value passes by int, but internaly convert to unsigned char
  *@return void pointer to pDestination memory block
*/
void* cmemset(void* pDestination, int value, unsigned size);

/**
  *@brief copies string pointed by pSource, to string pointed by pDestination
  *@param pDestination must be large enough to containt all pSource string
  *@return char pointer to destination string
  *@warning end of string is character end of row, coded by 30
*/
char* cstrcpy(char* pDestination, const char* pSource);

/**
  *@brief function copies size characters of the string pointed by pSource to string pointed pDestination,
  *or before terminated character in pSource detected
  *@param pDestination must be large enough to
  *@return char pointer to destination string
*/
char* cstrncpy(char* pDestination, const char* pSource, unsigned size);

/**
  *@brief concatenates strings pointed by pDestination and pSource, concatenated string stores in pDestination
  *@param pDestination must be large enough to containt concatenated string
  *@return char pointer to destination string
*/
char* cstrcat(char* pDestination, const char* pSource);

/**
  *@brief concatenates string pointed by pDestination with first size characters of string pointed by pSource
  *@param pDestination must be large enough to contain concatenated string
  *@return char pointer to destination string
*/
char* cstrncat(char* pDestination, const char* pSource, unsigned size);

/**
*@brief compares strings pointed by pStr1 and pStr2
*@return int that defines whether they are equal or not
*@remark if return us <0 pStr2 greater, >0 pStr1 greater, 0 equal
*/
int cstrcmp(const char* pStr1, const char* pStr2);

/**
*@brief compares first size character of strings pointed by pStr1 and pStr2
*@return int that defines whether they are equal or not
*@remark if return us <0 pStr2 greater, >0 pStr1 greater, 0 equal
*/
int cstrncmp(const char* pStr1, const char* pStr2, unsigned size);

/**
  *@brief search first accurance of character in string pointed by pTargetStr
  *@param character passes as in but internaly converted to char
  *@return char pointer to the first accurance of character
*/
char* cstrchr(char* pTargetStr, int character);

/**
  *@brief counts length of string pointed by pTargetStr that not containt characters in string pointed by pCheckStr
  *@return unsigned number
*/
unsigned cstrcspn(const char* pTargetStr, const char* pCheckStr);

/**
  *@brief search first accurance in string poited by  pTargetStr any of the character in string pointed by pCheckStr
  *@return char pointer to first accurance if no characters finded returns NULL
*/
char* cstrpbrk(const char* pTargetStr, const char* pCheckStr);

/**
  *@brief returns the last accurance of character in string pointed by pTargetStr
  *@param character passes as int but internaly converted to char
  *@return char pointer to string
*/
char* cstrrchr(const char* pTargetStr, int character);

/**
  *@brief search tokens in string pointed by pTargetStr, that splited by delimiters in pDelimiters
  *@return char pointer to token
  *@remark first call o function with pTargetStr string not NULL, returns first 
  token splited by one of the delimiters, next accurance with NULL as pTargetStr
  retunrns next token, if no token left returns NULL
*/
char* cstrtok(char* pTargetStr, const char* pDelimiters);

/**
  *@brief returns initial number of character in pTargetStr that consists only of characters in pCheckStr
  *@return unsigned
*/
unsigned cstrspn(const char* pTargetStr, const char* pCheckStr);

/**
  *@brief returns first accurance of substring pointed by pSubStr in string pointed by pTargetStr
  *@return  char pointer to string
*/
char* cstrstr(const char* pTargetStr, const char* pSubStr);

/**
  *@brief returns length of string pointed by pStr, end of string defined as end of row character
*/
unsigned cstrlen(const char* pStr);

#endif /* C_STRING_H */