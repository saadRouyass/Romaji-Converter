#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "hash_table.h"
#include "romaji_Converter.h"

int main() {

    printf("Initializing.....\n");
    char paragraph[MAX_PARAGRAPH_SIZE];
    char pairs[MAX_PARAGRAPH_SIZE / 2][MAX_PAIR_SIZE];
    ht_hash_table* ht = ht_new();
        // Vowels
    ht_insert(ht, "a",  "あ");
    ht_insert(ht, "i",  "い");
    ht_insert(ht, "u",  "う");
    ht_insert(ht, "e",  "え");
    ht_insert(ht, "o",  "お");

    // K-group
    ht_insert(ht, "ka", "か");
    ht_insert(ht, "ki", "き");
    ht_insert(ht, "ku", "く");
    ht_insert(ht, "ke", "け");
    ht_insert(ht, "ko", "こ");

    // S-group
    ht_insert(ht, "sa", "さ");
    ht_insert(ht, "shi","し");
    ht_insert(ht, "su", "す");
    ht_insert(ht, "se", "せ");
    ht_insert(ht, "so", "そ");

    // T-group
    ht_insert(ht, "ta", "た");
    ht_insert(ht, "chi","ち");
    ht_insert(ht, "tsu","つ");
    ht_insert(ht, "te", "て");
    ht_insert(ht, "to", "と");

    // N-group
    ht_insert(ht, "na", "な");
    ht_insert(ht, "ni", "に");
    ht_insert(ht, "nu", "ぬ");
    ht_insert(ht, "ne", "ね");
    ht_insert(ht, "no", "の");

    // H-group
    ht_insert(ht, "ha", "は");
    ht_insert(ht, "hi", "ひ");
    ht_insert(ht, "fu", "ふ");
    ht_insert(ht, "he", "へ");
    ht_insert(ht, "ho", "ほ");

    // M-group
    ht_insert(ht, "ma", "ま");
    ht_insert(ht, "mi", "み");
    ht_insert(ht, "mu", "む");
    ht_insert(ht, "me", "め");
    ht_insert(ht, "mo", "も");

    // Y-group
    ht_insert(ht, "ya", "や");
    ht_insert(ht, "yu", "ゆ");
    ht_insert(ht, "yo", "よ");

    // R-group
    ht_insert(ht, "ra", "ら");
    ht_insert(ht, "ri", "り");
    ht_insert(ht, "ru", "る");
    ht_insert(ht, "re", "れ");
    ht_insert(ht, "ro", "ろ");

    // W-group
    ht_insert(ht, "wa", "わ");
    ht_insert(ht, "wo", "を");

    // N
    ht_insert(ht, "n",  "ん");

    // Dakuten (voiced sounds)
    ht_insert(ht, "ga", "が");
    ht_insert(ht, "gi", "ぎ");
    ht_insert(ht, "gu", "ぐ");
    ht_insert(ht, "ge", "げ");
    ht_insert(ht, "go", "ご");

    ht_insert(ht, "za", "ざ");
    ht_insert(ht, "ji", "じ");
    ht_insert(ht, "zu", "ず");
    ht_insert(ht, "ze", "ぜ");
    ht_insert(ht, "zo", "ぞ");

    ht_insert(ht, "da", "だ");
    ht_insert(ht, "dji","ぢ");  // for completeness
    ht_insert(ht, "dzu","づ");  // same here
    ht_insert(ht, "de", "で");
    ht_insert(ht, "do", "ど");

    ht_insert(ht, "ba", "ば");
    ht_insert(ht, "bi", "び");
    ht_insert(ht, "bu", "ぶ");
    ht_insert(ht, "be", "べ");
    ht_insert(ht, "bo", "ぼ");

    // Handakuten (p-sounds)
    ht_insert(ht, "pa", "ぱ");
    ht_insert(ht, "pi", "ぴ");
    ht_insert(ht, "pu", "ぷ");
    ht_insert(ht, "pe", "ぺ");
    ht_insert(ht, "po", "ぽ");

    // Youon (combinations)
    ht_insert(ht, "kya", "きゃ");
    ht_insert(ht, "kyu", "きゅ");
    ht_insert(ht, "kyo", "きょ");

    ht_insert(ht, "sha", "しゃ");
    ht_insert(ht, "shu", "しゅ");
    ht_insert(ht, "sho", "しょ");

    ht_insert(ht, "cha", "ちゃ");
    ht_insert(ht, "chu", "ちゅ");
    ht_insert(ht, "cho", "ちょ");

    ht_insert(ht, "nya", "にゃ");
    ht_insert(ht, "nyu", "にゅ");
    ht_insert(ht, "nyo", "にょ");

    ht_insert(ht, "hya", "ひゃ");
    ht_insert(ht, "hyu", "ひゅ");
    ht_insert(ht, "hyo", "ひょ");

    ht_insert(ht, "mya", "みゃ");
    ht_insert(ht, "myu", "みゅ");
    ht_insert(ht, "myo", "みょ");

    ht_insert(ht, "rya", "りゃ");
    ht_insert(ht, "ryu", "りゅ");
    ht_insert(ht, "ryo", "りょ");

    ht_insert(ht, "gya", "ぎゃ");
    ht_insert(ht, "gyu", "ぎゅ");
    ht_insert(ht, "gyo", "ぎょ");

    ht_insert(ht, "ja",  "じゃ");
    ht_insert(ht, "ju",  "じゅ");
    ht_insert(ht, "jo",  "じょ");

    ht_insert(ht, "bya", "びゃ");
    ht_insert(ht, "byu", "びゅ");
    ht_insert(ht, "byo", "びょ");

    ht_insert(ht, "pya", "ぴゃ");
    ht_insert(ht, "pyu", "ぴゅ");
    ht_insert(ht, "pyo", "ぴょ");

    printf("------------------------\n");
    printf("Type something and click Enter:\n");

    while (1)
    {
        printf("\n>>");
        fgets(paragraph, sizeof(paragraph), stdin);

        char* splited_paragraph = strtok(paragraph," \t\n\r,.");
        
        printf(">> ");
        while (splited_paragraph!=NULL)
        {
            int pairCount = split_into_pairs(splited_paragraph, pairs);
            // print the result 
            
            for (int i = 0; i < pairCount; i++) {
                           
                printf("%s",ht_search(ht,pairs[i]));
                
            }
            printf(" ");
            splited_paragraph = strtok(NULL," \t\n\r,.");
    
        }
        
        printf("\n");
    }

    return 0;
}