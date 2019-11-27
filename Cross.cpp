#include<bits/stdc++.h>
using namespace std;


char sudoku[10][10];
char changed[10][10];

void printOutput()
{
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << endl;
    }
}


bool row_or_col_Error()
{
    for(int i = 1; i <= 9; i++)
    {
        vector<char> row;
        vector<char> col;
        for(int j = 1; j <= 9; j++)
        {
            if(sudoku[i][j] != '.')row.push_back(sudoku[i][j]);
            if(sudoku[j][i] != '.')col.push_back(sudoku[j][i]);
        }
        set<char> srow(row.begin(), row.end());
        set<char> scol(col.begin(), col.end());
        if((srow.size() != row.size()) || (scol.size() != col.size()))
        {
            return false;
        }
    }
    return true;
}


bool box_Error()
{
    for(int i = 1 ; i <= 9; i = i + 3)
    {
        for(int j = 1; j <= 9; j = j + 3)
        {
            vector<char> box;
            for(int r = 0; r <= 2; r++)
            {
                for(int c = 0; c <= 2; c++)
                {
                    if(sudoku[i + r][j + c] != '.') box.push_back(sudoku[i + r][j + c]);
                }
            }
            set<char> sbox(box.begin(), box.end());
            if(sbox.size() != box.size())
            {
                return false;
            }
        }
    }
    return true;
}

void cross(int n)
{
    for(int i = 1 ; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(changed[i][j] == char(n + 48))
            {
                for(int k = 1; k <= 9; k++)
                {
                    if(changed[i][k] == '.') changed[i][k] = 'x';
                    if(changed[k][j] == '.') changed[k][j] = 'x';
                }
                for(int dr = 0; dr <= 2; dr++)
                {
                    for(int dc = 0; dc <= 2; dc++)
                    {
                        int br = 3*((i-1)/3) + 1 + dr;
                        int bc = 3*((j-1)/3) + 1 + dc;
                        if(changed[br][bc] == '.') changed[br][bc] = 'x';
                    }
                }
            }
        }
    }
}

int hatch(int n)
{
    for(int i = 1 ; i <= 9; i = i + 3)
    {
        for(int j = 1; j <= 9; j = j + 3)
        {
            int nr, nc, empty = 0, filled = 0;
            for(int dr = 0; dr <= 2; dr++)
            {
                for(int dc = 0; dc <= 2; dc++)
                {
                    if(changed[i + dr][j + dc] == '.')
                    {
                        nr = i + dr;
                        nc = j + dc;
                        empty++;

                    }
                    if(changed[i + dr][j + dc] == char(n + 48))
                    {
                        filled = 1;
                    }
                }
            }

            if(filled + empty == 0)
            {
                return -1;
            }
            if(empty == 1)
            {
                sudoku[nr][nc] = char(n + 48);
                return 1;
            }
        }
    }
    return 0;
}

bool solve()
{
    bool check = (row_or_col_Error() and box_Error());
    if(check == false) return false;
    bool con = true;
    while(con)
    {
        con = false;
        for(int num = 1; num <= 9; num++)
        {
            for(int i = 1; i <= 9; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    changed[i][j] = sudoku[i][j];
                }
            }
            cross(num);
            if(hatch(num) == 1) con = true;
            if(hatch(num) == -1) return false;

        }
    }
    return true;
}



int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for(int i = 1; i <= 9 ; i++)
    {
        for(int j = 1; j <= 9 ; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    bool ans = solve();
    if(ans)
    {
        printOutput();
    }
    else cout << "ERROR";
}
