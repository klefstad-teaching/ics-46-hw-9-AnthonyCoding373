#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cerr << word1 << " " << word2 << " " << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    
}

bool is_adjacent(const string& word1, const string& word2)
{
    
}

bool is_same_word(const string &word1, const string &word2)
{
    if (begin_word == end_word)
    {
        return begin_word;
    } 
}

bool is_in_word_list(const string &word1, const set<string>& word_list)
{
    for (string &s : word_list)
    {
        if (s == word1)
        {
            return true;
        }
    }
    return false;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    if (is_same_word)
    {
        return begin_word;
    } else if (!is_in_word_list(begin_word, word_list) || !is_in_word_list(end_word, word_list)) {
        error(begin_word, end_word, "Not in word list");
    }

    map<string, vector<string>> mappings;

    for (string &word : begin_word)
    {

    }
}



void load_words(set<string> & word_list, const string& file_name) {}
void print_word_ladder(const vector<string>& ladder) {}
void verify_word_ladder() {}