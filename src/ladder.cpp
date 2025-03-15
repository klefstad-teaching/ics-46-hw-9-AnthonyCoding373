#include "ladder.h"

void error(string word1, string word2, string msg)
{
    cerr << word1 << " " << word2 << " " << msg;
}

int get_edit_distance(const std::string& str1, const std::string& str2)
{
    int m = str1.size();
    int n = str2.size();

    // cout << m << " " << n << endl;

    vector<int> matrixWagnerFischer((m+1) * (n+1), 0);


    // Initialize the first row to edit distance of word to an empty string
    for (int i = 0; i <= m; ++i)
    {
        matrixWagnerFischer[i] = i;
    }

    // std::cout << "Current" << endl;

    for (int i = 0; i <= n; ++i)
    {
        matrixWagnerFischer[i * (m + 1)] = i;
    }

    std::cout << "VAL" << endl;
    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= m; ++y)
        {
            std::cout << "(" << x << " " << y << "): " << matrixWagnerFischer[x * (m+1) + y] << endl;
        }
    }
    

    std::cout << 1 * (m + 1) + 1 << endl;
    std::cout << 1 * (m + 1) + 1 - (m + 2) << endl;
    

    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= m; ++y)
        {
            cout << x << " " << y << endl;
            int index = x * (m + 1) + y;
            if (str1[y - 1] == str2[x - 1])
                matrixWagnerFischer[index] = matrixWagnerFischer[index - (m + 2)] ;
            else {
                int topLeft = matrixWagnerFischer[index - (m + 2)];
                int left = matrixWagnerFischer[index - 1];
                int top = matrixWagnerFischer[index - (m + 1)];
                int min = std::min(std::min(topLeft, left), top);
                cout << "New Val: " << min << endl;
                matrixWagnerFischer[index] = min + 1;
            }
        }
    }

    std::cout << "VAL" << endl;
    for (int x = 0; x <= n; ++x)
    {
        for (int y = 0; y <= m; ++y)
        {
            std::cout << "(" << x << " " << y << "): " << matrixWagnerFischer[x * (m+1) + y] << endl;
        }
    }

    // cout << matrixWagnerFischer[m][n] << endl;

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
        solution.push_back(begin_word);
        return solution;
    } else if (!is_in_word_list(begin_word, word_list) || !is_in_word_list(end_word, word_list)) {
        error(begin_word, end_word, "Not in word list");
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



void load_words(set<string> & word_list, const string& file_name) {}
void print_word_ladder(const vector<string>& ladder) {}
void verify_word_ladder() {}