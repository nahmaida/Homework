#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9
#define MAX_STACK 1000

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

typedef struct
{
    int num;
    int nodes[MAX_STACK];
} adjacent;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void fillZero(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");
    fillZero();

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            vote(j, name, ranks);
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!strcmp(candidates[i], name))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

void fillZero()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            preferences[i][j] = 0;
        }
    }
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int toIgnore[candidate_count];
    int nIgnore = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            bool ignore = false;
            for (int k = 0; k < nIgnore; k++)
            {
                if (j == toIgnore[k])
                {
                    ignore = true;
                    break;
                }
            }
            if (ignore || j == ranks[i])
                continue;
            preferences[ranks[i]][j]++;
            toIgnore[nIgnore] = ranks[i];
            nIgnore++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count * (candidate_count - 1) / 2; i++)
    {
        for (int j = 0; j < candidate_count * (candidate_count - 1) / 2 - i; j++)
        {
            if (j + i != i && preferences[i][j + i] != preferences[j + i][i])
            {
                pair newPair;
                newPair.winner = (preferences[i][j + i] > preferences[j + i][i]) ? i : j + i;
                newPair.loser = (preferences[i][j + i] > preferences[j + i][i]) ? j + i : i;
                pairs[pair_count] = newPair;
                pair_count++;
            }
        }
    }
}

int getdiff(int pair)
{
    int winner = pairs[pair].winner;
    int loser = pairs[pair].loser;
    int diff = preferences[winner][loser] - preferences[loser][winner];
    return diff;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    bool swapped;
    for (int i = 0; i < pair_count - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            if (getdiff(j) <= getdiff(j + 1))
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    printf("\n");
}

adjacent findAdjacent(int n)
{
    adjacent adj;
    adj.num = 0;
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[n][i])
        {
            adj.nodes[adj.num] = i;
            adj.num++;
        }
    }
    return adj;
}

// Detect loops using depth first traversal
bool dfs(int current, bool visited[], bool recStack[])
{
    if (!visited[current])
    {
        visited[current] = true;
        recStack[current] = true;
    }
    adjacent adj = findAdjacent(current);
    for (int i = 0; i < adj.num; i++)
    {
        int node = adj.nodes[i];
        if ((!visited[node] && dfs(node, visited, recStack)) || recStack[node])
        {
            return true;
        }
    }

    recStack[current] = false;
    return false;
}

bool dfsinit()
{
    bool visited[pair_count];
    bool recStack[pair_count];
    for (int j = 0; j < pair_count; j++)
    {
        visited[j] = false;
        recStack[j] = false;
    }
    for (int i = 0; i < pair_count; i++)
    {
        if (!visited[i] && dfs(i, visited, recStack))
        {
            return true;
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if (dfsinit())
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        bool winner = true;
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[j][i])
            {
                winner = false;
                break;
            }
        }
        if (winner)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
