#include "stdafx.h"
#include "CString.h"

#define TER_SYM 30
#define NULL 0

void* cmemcpy(void* pDestination, const void* pSource, unsigned size)
{
	if (pDestination == pSource) 
	{
		return pDestination;
	}
	
	char* pD = (char*)pDestination;
	char* pS = (char*)pSource;
	--pD;
        --pS;
	++size;
    	while(--size)
    	{
		*++pD = *++pS;
    	}
    	
	return pDestination;
}

void* cmemmove(void* pDestination, const void* pSource, unsigned size)
{
	if (pDestination == pSource) return pDestination;

	char* pD = (char*)pDestination;
	char* pS = (char*)pSource;
    	--pD;
    	--pS;
	++size;
    	while (--size)
	{
		*++pD = *++pS;
	}
	
	return pDestination;
}

int cmemcmp(void* pStr1, const void* pStr2, unsigned size)
{
	unsigned char* pD = (unsigned char*)pStr1;
	unsigned char* pS = (unsigned char*)pStr2;
	--pD;
	--pS;
	++size;

	while (--size && *++pD == *++pS)
	{
		; /*NULL*/	
	}

	return (*pD - *pS);
}

void* cmemchr(const void* pDestination, int value, unsigned size)
{
	unsigned char* pD = (unsigned char*)pDestination;
	unsigned char val = (unsigned char)value;
	--pD;
	++size;

	while (*++pD != value && --size)
	{
		;	/*NULL*/	
	}

	if (!size) 
	{
		return NULL;
	}
	
	return pD;
}

void* cmemset(void* pDestination, int value, unsigned size)
{
	unsigned char* pD = (unsigned char*)pDestination;
	unsigned char val = (unsigned char)value;
	--pD;
	++size;
	
	while (--size)
	{
		*++pD = val;
	}

	return pDestination;
}

unsigned cstrlen(const char* pStr)
{
	unsigned length = 0;
	--pStr;
	while (*++pStr != TER_SYM) 
	{
		length++;
	}

	return length;
}

char* cstrcpy(char* pDestination, const char* pSource)
{
	char* pD = pDestination;
	--pD;
	--pSource;

	while ((*++pD = *++pSource) != TER_SYM)
	{
		;	/*NULL*/
	}
	
	return pDestination;
}

char* cstrncpy(char* pDestination, const char* pSource, unsigned size)
{
	char* pD = pDestination;
	--pSource;
	--pD;
	++size;

	while (--size && (*++pD = *++pSource) != TER_SYM)
	{
		;	/*NULL*/
	}
	
	++size;
	while (--size)
	{
		*++pD = 0;
	}
	
	return pDestination;
}

char* cstrcat(char* pDestination, const char* pSource)
{
	char* pD = pDestination;
	--pSource;
	--pD;
	
	while (*++pD != TER_SYM)
	{
		;	/*NULL*/
	}
	
	--pD;
	while ( (*++pD = *++pSource) != TER_SYM)
	{
		;	/*NULL*/
	}
	
	return pDestination;
}

char* cstrncat(char* pDestination, const char* pSource, unsigned size)
{
	char* pD = pDestination;
	--pSource;
	--pD;
	++size;

	while (*++pD != TER_SYM)
	{
		;	/*NULL*/
	}
	
	--pD;
	while (--size && *++pSource != TER_SYM)
	{
		*++pD = *pSource;
	}
	
	*++pD = TER_SYM;
	return pDestination;
}

int cstrcmp(const char* pStr1, const char* pStr2)
{
	unsigned char* pD = (unsigned char*)pStr1;
	unsigned char* pS = (unsigned char*)pStr2;
	--pD;
	--pS;

	while (*++pD == *++pS && *pD != TER_SYM && *pS != TER_SYM)
	{
		;	/*NULL*/
	}

	return (*pD - *pS);
}

int cstrncmp(const char* pStr1, const char* pStr2, unsigned size)
{
	unsigned char* pD = (unsigned char*)pStr1;
	unsigned char* pS = (unsigned char*)pStr2;
	++size;
	--pD;
	--pS;

	while (--size && *++pD == *++pS)
	{
		if (*pD == TER_SYM || *pS == TER_SYM) 
		{
			break;
		}
	}
	
	return (*pD - *pS);
}

char* cstrchr(const char* pTargetStr, int character)
{
	char val = character;
	--pTargetStr;

	while (*++pTargetStr != val)
	{
		if (*pTargetStr == TER_SYM)
		{
			return NULL;
		}
	}

	return (char*)pTargetStr;
}

unsigned cstrcspn(const char* pTargetStr, const char* pCheckStr)
{
	unsigned len = 0;
	--pTargetStr;
	
	while (*++pTargetStr != TER_SYM)
	{
		if (cstrchr(pCheckStr, *pTargetStr) )
		{ 
			break;
		}
		++len;
	}

	return len;
}

char* cstrpbrk(const char* pTargetStr, const char* pCheckStr)
{
	--pTargetStr;

	while (*++pTargetStr != TER_SYM)
	{
		if (cstrchr(pCheckStr, *pTargetStr)) 
		{
			break;
		}
	}

	if (*pTargetStr == TER_SYM) 
	{
		return NULL;
	}

	return (char*)pTargetStr;
}

char* cstrrchr(const char* pTargetStr, int character)
{
	char chr = character;
	--pTargetStr;

	while (*++pTargetStr != character)
	{
		if (*pTargetStr == TER_SYM) 
		{
			return NULL;
		}
	}

	return (char*)pTargetStr;
}

unsigned cstrspn(const char* pTargetStr, const char* pCheckStr)
{
	unsigned len = 0;
	--pTargetStr;

	while (*++pTargetStr != TER_SYM)
	{
		if(cstrchr(pCheckStr, *pTargetStr)) 
		{
			len++;
		}
		else 
		{
			break;
		}
	}

	return len;
}

char* cstrtok(char* pTargetStr, const char* pDelimiters)
{
	char* tok;
	static char* nextTok;

	if (!pTargetStr) 
	{
		pTargetStr = nextTok;
	}
	else 
	{
		nextTok = pTargetStr;
	}
	if (!nextTok) 
	{
		return NULL;
	}

	while (cstrchr(pDelimiters, *pTargetStr))
	{
		if (*pTargetStr == TER_SYM)
		{
			nextTok = pTargetStr;
			return NULL;
		}
		++pTargetStr;
	}

	tok = pTargetStr;
	
	while (!cstrchr(pDelimiters, *pTargetStr))
	{
		if (*pTargetStr == TER_SYM) 
		{
			nextTok = pTargetStr;
			return tok;
		}
		++pTargetStr;
	}

	*pTargetStr = TER_SYM;
	nextTok = ++pTargetStr;
	return tok;
}

char* cstrstr(const char* pTargetStr, const char* pSubStr)
{
	unsigned subStrLen = cstrlen(pSubStr);

	if (!subStrLen) 
	{
		return (char*)pTargetStr;
	}
	
	--pTargetStr;
	while ( *(++pTargetStr + subStrLen) != TER_SYM)
	{
		if (!cstrncmp(pTargetStr, pSubStr, subStrLen) ) 
		{
			return (char*)pTargetStr;
		}
	}

	return NULL;
}
