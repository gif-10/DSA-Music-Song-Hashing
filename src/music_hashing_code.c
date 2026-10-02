#include <stdio.h>
#define SIZE 10
#define N 8

int hashTable[SIZE];
int hashFunction(int key)
{
    return key % SIZE;
}

void initialize()
{
    int i;

    for(i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

void displayTable()
{
    int i;

    for(i = 0; i < SIZE; i++)
    {
        if(hashTable[i] == -1)
            printf("- ");
        else
            printf("%d ", hashTable[i]);
    }

    printf("\n");
}

void insert(int key)
{
    int index, i, pos;
    int collisions = 0;
    index = hashFunction(key);
    for(i = 0; i < SIZE; i++)
    {
        pos = (index + i) % SIZE;

        if(hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            break;
        }
        collisions++;
    }
    printf("Insert %d: Hash Index = %d, Final Index = %d, "
           "Collisions = %d\n",
           key, index, pos, collisions);
    printf("Table: ");
    displayTable();
}

int hashSearch(int key, int *comparisons)
{
    int index, i, pos;
    *comparisons = 0;
    index = hashFunction(key);
    for(i = 0; i < SIZE; i++)
    {
        pos = (index + i) % SIZE;

        if(hashTable[pos] == -1)
            return -1;
        (*comparisons)++;
        if(hashTable[pos] == key)
            return pos;
    }
    return -1;
}

int linearSearch(int arr[], int n, int key, int *comparisons)
{
    int i;
    *comparisons = 0;
    for(i = 0; i < n; i++)
    {
        (*comparisons)++;

        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int songs[N] = {105, 210, 315, 420,
                    525, 630, 735, 840};
    int i;
    int position;
    int hashComparisons;
    int linearComparisons;
    int totalHashComparisons = 0;
    int totalLinearComparisons = 0;
    initialize();
    printf("============================================\n");
    printf("       MUSIC SONG ID HASHING SYSTEM\n");
    printf("============================================\n");

    printf("\nHash Function: h(k) = k %% 10\n");
    printf("Collision Resolution: Linear Probing\n");
    printf("Table Size: %d\n\n", SIZE);

    printf("------------- INSERTION -------------------\n");

    for(i = 0; i < N; i++)
    {
        insert(songs[i]);
    }
    printf("\n------------- FINAL HASH TABLE ------------\n");
    for(i = 0; i < SIZE; i++)
    {
        if(hashTable[i] == -1)
            printf("Index %d : -\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
    printf("\n------------- HASHING SEARCH ---------------\n");
    for(i = 0; i < N; i++)
    {
        position = hashSearch(songs[i], &hashComparisons);

        printf("%d -> Index %d, Comparisons = %d\n",
               songs[i], position, hashComparisons);
        totalHashComparisons += hashComparisons;
    }

    printf("\n------------- LINEAR SEARCH ----------------\n");

    for(i = 0; i < N; i++)
    {
        position = linearSearch(songs, N,
                                songs[i],
                                &linearComparisons);

        printf("%d -> Position %d, Comparisons = %d\n",
               songs[i], position, linearComparisons);

        totalLinearComparisons += linearComparisons;
    }
    printf("\n------------- PERFORMANCE ------------------\n");

    printf("Total Hashing Comparisons = %d\n",
           totalHashComparisons);
    printf("Average Hashing Comparisons = %.2f\n",
           (float)totalHashComparisons / N);
    printf("Total Linear Search Comparisons = %d\n",
           totalLinearComparisons);
    printf("Average Linear Search Comparisons = %.2f\n",
           (float)totalLinearComparisons / N);
    printf("\nLoad Factor = %d / %d = %.2f\n",
           N, SIZE, (float)N / SIZE);
    return 0;
}
