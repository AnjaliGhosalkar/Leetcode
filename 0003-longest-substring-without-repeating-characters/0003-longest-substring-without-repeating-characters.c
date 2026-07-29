#include <stdio.h>

int lengthOfLongestSubstring(char *s)
{
    int last[256], i;

    for(i = 0; i < 256; i++)
        last[i] = -1;

    int left = 0, maxLength = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(last[(unsigned char)s[i]] >= left)
            left = last[(unsigned char)s[i]] + 1;

        last[(unsigned char)s[i]] = i;

        if(i - left + 1 > maxLength)
            maxLength = i - left + 1;
    }

    return maxLength;
}


