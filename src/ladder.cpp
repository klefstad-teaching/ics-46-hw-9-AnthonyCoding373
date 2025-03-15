#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cerr << word1 << " " << word2 << " " << msg;
}

int get_edit_distance(const std::string& str1, const std::string& str2)
{
    int m = str1.size();
    int n = str2.size();

    vector<int> matrixWagnerFischer((m+1) * (n+1));


    // Initialize the first row to edit distance of word to an empty string
    for (int i = 0; i <= m; ++i)
    {
        matrixWagnerFischer[i] = i;
    }

    for (int i = 0; i <= n; ++i)
    {
        matrixWagnerFischer[i * (m + 1)] = i;
    }
    

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            int index = x * (m + 1) + y;
            if (str1[y - 1] == str2[x - 1])
                matrixWagnerFischer[index] = matrixWagnerFischer[index - (m + 2)] ;
            else {
                int topLeft = matrixWagnerFischer[index - (m + 2)];
                int left = matrixWagnerFischer[index - 1];
                int top = matrixWagnerFischer[index - (m + 1)];
                int min = std::min(std::min(topLeft, left), top);
                matrixWagnerFischer[index] = min + 1;
            }
        }
    }

    return matrixWagnerFischer[(m + 1) * (n + 1) - 1];
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    int edit_distance = get_edit_distance(str1, str2);
    return edit_distance <= d;
}

bool is_adjacent(const string& word1, const string& word2)
{
    return edit_distance_within(word1, word2, 1);
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
        return solution;
    }

    queue<vector<string>> ladder;
    vector<string> partialLadder;
    partialLadder.push_back(begin_word);
    ladder.push(partialLadder);
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder.empty())
    {
        partialLadder = ladder.front();
        ladder.pop();
        string last_word = partialLadder[partialLadder.size() - 1];
        for (const string &word : word_list)
        {
            if (is_adjacent(last_word, word))
            {
                if (!visited.contains(word))
                {
                    visited.insert(word);
                    vector<string> new_partial_ladder = partialLadder;
                    new_partial_ladder.push_back(word);
                    if (word == end_word)
                    {
                        return new_partial_ladder;
                    }

                    ladder.push(new_partial_ladder);
                }
            }
        }
    }

    vector<string> defaultReturn;
    return defaultReturn;
}



void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);

    string word;
    while (in >> word)
    {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder) {

    if (ladder.size() == 0)
    {
        cout << "No word ladder found." << endl;
        return;
    }

    cout << "Word ladder found: ";

    for (const string &word : ladder)
    {
        cout << word << " ";
    }
    cout << endl;
}


#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    // my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    // my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    // my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    // my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    // my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}