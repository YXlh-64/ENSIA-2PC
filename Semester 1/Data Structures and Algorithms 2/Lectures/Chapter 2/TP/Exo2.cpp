#include <iostream>
using namespace std;
void wordPuzzle(string *words, int size_w, char letters[][8], int rows_lttr)
{
    // first iteration through the matrix of letters
    for (int i = 0; i < rows_lttr; i++)
    {
        for (int j = 0; j < 8; ++j)
        {
            // second iteration to loop through the different words of the list
            for (int w = 0; w < size_w; ++w)
            {
                if (letters[i][j] == words[w][0])
                {

                    // TOP
                    if (j - words[w].size() >= 0 && words[w][1] == letters[i - 1][j])
                    {
                        bool maching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i - i1][j])
                                maching = false;
                        }

                        if (maching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'TOP\' "
                                 << endl;
                    }
                    // TOP RIGHT
                    if (j + words[w].size() <= 8 && i - words[w].size() >= 0)
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i - i1][j + i1])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'TOP-RIGHT\' "
                                 << endl;
                    }
                    // RIGHT
                    if (words[w][1] == letters[i][j + 1] && j + words[w].size() <= 8)
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i][j + i1])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'RIGHT\' "
                                 << endl;
                    }

                    // BOTTOM-RIGHT
                    if (i + words[w].size() <= rows_lttr && j + words[w].size() <= 8)
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i + i1][j + i1])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'BOTTOM-RIGHT\' "
                                 << endl;
                    }
                    // BOTTOM
                    if (i + words[w].size() <= rows_lttr && /*Additional condition*/ words[w][1] == letters[i + 1][j])
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i + i1][j])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'BOTTOM\' "
                                 << endl;
                    }

                    // BOTTOM-LEFT
                    if (j - words[w].size() >= 0 && i + words[w].size() <= rows_lttr)
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i + i1][j - i1])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'BOTTOM-LEFT\' "
                                 << endl;
                    }

                    // LEFT
                    if (j - words[w].size() >= 0 && words[w][1] == letters[i][j - 1])
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i][j - i1])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'LEFT\' "
                                 << endl;
                    }
                    // TOP-LEFT
                    if (j - words[w].size() >= 0 && i - words[w].size() >= 0)
                    {
                        bool matching = true;
                        for (int i1 = 1; i1 < words[w].size(); ++i1)
                        {
                            if (words[w][i1] != letters[i - i1][j - i1])
                                matching = false;
                        }

                        if (matching)
                            cout << "the word " << words[w] << " starts at index: "
                                 << "(" << i << "," << j << ")"
                                 << " in the direction: \'TOP-LEFT\' "
                                 << endl;
                    }
                }
            }
        }
    }
}
// a program to solve the word puzzle problem
int main()
{
    // complexity of the algorithm is O(N^4) where N is the maximum of
    // the number of rows of a matrix, the number of columns, and the number
    // of items in the wordlist
    const int rows = 7;
    const int columns = 8;
    char arr[rows][columns] = {
        {'J', 'S', 'O', 'L', 'U', 'T', 'I', 'S'},
        {'S', 'U', 'N', 'A', 'R', 'U', 'U', 'A'},
        {'N', 'E', 'P', 'T', 'U', 'N', 'E', 'T'},
        {'S', 'O', 'N', 'I', 'E', 'I', 'S', 'U'},
        {'R', 'C', 'E', 'V', 'T', 'R', 'E', 'R'},
        {'A', 'H', 'T', 'R', 'A', 'E', 'S', 'N'},
        {'M', 'M', 'E', 'R', 'C', 'U', 'R', 'Y'}};
    string word_list[] = {
        "EARTH", "JUPITER", "MARS", "MERCURY", "NEPTUNE", "SATURN", "URANUS", "VENUS"};
    wordPuzzle(word_list, 8, arr, rows);
    return 0;
}