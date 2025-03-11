#include "ladder.h"
#include <algorithm>
void error(string word1, string word2, string msg){
    std::cout << "ERR of words: " << word1 << " and" << word2 << "" << msg << endl;
}

// bool edit_distance_within(const std::string& str1, const std::string& str2, int d){

// }

bool is_adjacent(const string& word1, const string& word2){
    // if(word1.length() == word2.length()){
    //     //equal leng
    //     bool one_diff = false;
    //     for (int i = 0; i < word1.length(); ++i){
    //         if(word1[i] != word2[i]){
    //             if(one_diff) return false;
    //             else one_diff = true;
    //         }
    //     }
    //     return one_diff;
    // }
    // else if(word1.length() - word2.length() == 1 ){
    //     //delete
    //     bool one_diff = false;
    //     int i2 = 0;
    //     for(int i1 = 0; i1 < word2.length(); ++i1){
    //         if(i2 >= word2.length()){
    //             return !one_diff;
    //         }
    //         if(word1[i1] != word2[i2]){
    //             if(one_diff) return false;
    //             else one_diff = true;
    //         }
    //         else ++i2;
    //     }
    //     return true;

    // }
    // else if(word1.length() - word2.length() == -1){
    //     //insertion
    //     bool one_diff = false;
    //     int i1 = 0;
    //     for(int i2 = 0; i2 < word2.length(); ++i2){
    //         if(i1 >= word2.length()){
    //             return !one_diff;
    //         }
    //         if(word1[i2] != word2[i1]){
    //             if(one_diff) return false;
    //             else one_diff = true;
    //         }
    //         else ++i1;
    //     }
    //     return true;
    // }
    // else return false;
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int m = str1.length();
    int n = str2.length(); 
    int dic[m+1][n+1] = {0};
    for(int i = 1; i <= m; ++i) dic[i][0] = i;
    for(int j = 1; j <= n; ++j) dic[0][j] = j;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <=n ; ++j){
            if(str1[i-1] == str2[j-1])
                dic[i][j] = dic[i-1][j-1];
            else{
                dic[i][j] = 1 + std::min(dic[i][j-1], std::min(dic[i-1][j], dic[i-1][j-1]));
            }
        }
    }
    return dic[m][n] <= d;
}