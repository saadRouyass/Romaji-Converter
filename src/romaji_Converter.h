#ifndef ROMAJI_CONV
#define ROMAJI_CONV

#define MAX_PARAGRAPH_SIZE 1000
#define MAX_PAIR_SIZE 4  

void remove_spaces(char* str);
int split_into_pairs(const char* paragraph, char pairs[][MAX_PAIR_SIZE]);








#endif