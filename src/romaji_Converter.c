#include <stdio.h>
#include <string.h>

#include "romaji_Converter.h"



void remove_spaces(char* str) {
    int i = 0, j = 0;

    // Iterate over the string and copy non-space characters
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];  // Copy non-space character to the new position
        }
        i++;
    }
    
    str[j] = '\0';  
}

int split_into_pairs(const char* paragraph, char pairs[][MAX_PAIR_SIZE]) {
    int pairIndex = 0;


    if (strlen(paragraph)==1)
    {
        pairs[pairIndex][0] = paragraph[0];
        pairs[pairIndex][1] = '\0';
        return 1;
    }
    
    
    // Loop to create pairs
    int increment = 2;
    for (int i = 0; paragraph[i] != '\0' && paragraph[i+1] != '\0' ; i += increment) {
        increment = 2;
        pairs[pairIndex][0] = paragraph[i];
        pairs[pairIndex][1] = paragraph[i+1];
        pairs[pairIndex][2] = '\0';
        if (paragraph[i]=='c' && paragraph[i+1]=='h')
        {
            pairs[pairIndex][2] = paragraph[i+2];
            pairs[pairIndex][3] = '\0';
            increment=3;
        }
        else if (paragraph[i]=='n' && (paragraph[i+1]!='o' && paragraph[i+1]!='i' && paragraph[i+1]!='a' && paragraph[i+1]!='e' && paragraph[i+1]!='u' ))
        {
            pairs[pairIndex][1] = '\0';
            increment=1;
           
        }
        else if (paragraph[i]=='s' && paragraph[i+1]=='h')
        {
            pairs[pairIndex][2] = paragraph[i+2];
            pairs[pairIndex][3] = '\0';
            increment=3;
        }
        else if ((paragraph[i]=='n' && paragraph[i+1]=='y') || (paragraph[i]=='k' && paragraph[i+1]=='y') ||
         (paragraph[i]=='h' && paragraph[i+1]=='y') || (paragraph[i]=='m' && paragraph[i+1]=='y') || 
         (paragraph[i]=='g' && paragraph[i+1]=='y') || (paragraph[i]=='b' && paragraph[i+1]=='y') ||
         (paragraph[i]=='p' && paragraph[i+1]=='y') || (paragraph[i]=='n' && paragraph[i+1]=='y'))
        {
            pairs[pairIndex][2] = paragraph[i+2];
            pairs[pairIndex][3] = '\0';
            increment=3;
        }
        else if (paragraph[i]=='a' ||paragraph[i]=='e' ||paragraph[i]=='i' ||paragraph[i]=='o' ||paragraph[i]=='u' )
        {
            pairs[pairIndex][1] = '\0';
            increment=1;
        
        }

        
        
        
        pairIndex++;
    }

    if ((strlen(pairs[pairIndex-1])==2 && pairs[pairIndex-1][1]!=paragraph[strlen(paragraph)-1]) ||
     (strlen(pairs[pairIndex-1])==3 && pairs[pairIndex-1][2]!=paragraph[strlen(paragraph)-1]))
    {
        pairs[pairIndex][0] = paragraph[strlen(paragraph)-1];
        pairs[pairIndex][1] = '\0';
        return pairIndex+1; 
    }
    else
    {
        return pairIndex;
    }
    
    


    
      // Return number of pairs created
}



