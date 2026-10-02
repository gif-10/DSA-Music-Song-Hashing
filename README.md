
# Music Song ID Hashing - DSA Assignment

## Problem

A music application stores the following song IDs:

105, 210, 315, 420, 525, 630, 735, 840

The task is to implement hashing using the Division Method, search the song IDs using hashing and linear search, and compare their performance.

## Implementation Details

- Programming Language: C
- Hash Function: h(k) = k % 10
- Hash Table Size: 10
- Collision Resolution: Linear Probing
- Number of Song IDs: 8

## Input Data

The input song IDs are stored in:

`input/input.txt`

## Hash Table Result

Final Hash Table:

| Index | Song ID |
|------:|--------:|
| 0 | 210 |
| 1 | 420 |
| 2 | 630 |
| 3 | 840 |
| 4 | - |
| 5 | 105 |
| 6 | 315 |
| 7 | 525 |
| 8 | 735 |
| 9 | - |

Total Collisions = 12

## Search Performance

| Method | Total Comparisons | Average Comparisons |
|---|---:|---:|
| Hashing | 20 | 2.50 |
| Linear Search | 36 | 4.50 |

## Load Factor

Load Factor = Number of elements / Table size

Load Factor = 8 / 10 = 0.80

## Complexity Analysis

### Hashing with Linear Probing

- Best-case search: O(1)
- Average-case search: O(1), when collisions are controlled
- Worst-case search: O(n)
- Space complexity: O(m)

### Linear Search

- Best-case search: O(1)
- Average-case search: O(n)
- Worst-case search: O(n)
- Space complexity: O(1)

## Trace Table

The insertion and search trace tables are available in:

`trace/trace_table.txt`

## Output

The complete program output is available in:

`output/output.txt`

## Source Code

The C source code is available in:

`music_hashing_code.c`

## Conclusion

For the given song IDs, hashing with linear probing required fewer average comparisons than linear search.

Hashing required 2.50 average comparisons, while linear search required 4.50 average comparisons.

The load factor was 0.80 and 12 collisions occurred. Collisions increased the number of positions that had to be checked during insertion and searching.

Hashing is therefore useful for frequent song-ID searching when a suitable hash function and table size are used to control collisions.
