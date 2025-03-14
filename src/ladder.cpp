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

bool is_in_word_list(const string &word1, const set<string>& word_list)
{
    for (const string &s : word_list)
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
    vector<string> solution;
    if (begin_word == end_word)
    {
        solution.push_back(begin_word);
        return solution;
    } else if (!is_in_word_list(begin_word, word_list) || !is_in_word_list(end_word, word_list)) {
        error(begin_word, end_word, "Not in word list");
    }

    map<string, vector<string>> mappings;

    for (const string &word : word_list)
    {

    }
}



void load_words(set<string> & word_list, const string& file_name) {}
void print_word_ladder(const vector<string>& ladder) {}
void verify_word_ladder() {}