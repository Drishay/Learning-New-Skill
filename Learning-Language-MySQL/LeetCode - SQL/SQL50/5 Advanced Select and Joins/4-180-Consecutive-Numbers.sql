# Write your MySQL query statement below
-- Can i group the connsecutive numbers? because If I group consecutive numbers, I can count how many are in each group, and then find the numbers that occur at least 3 times consecutively.

-- WITH consecutive_nums AS (
--     SELECT
--         id,
--         num,
--         LAG(num, 1) OVER (ORDER BY id) AS prev_num,
--         LAG(num, 2) OVER (ORDER BY id) AS prev2_num
--     FROM Logs
-- )

-- /*
-- | id | num | prev_num | prev2_num |
-- | -- | --- | -------- | --------- |
-- | 1  | 1   | null     | null      |
-- | 2  | 1   | 1        | null      |
-- | 3  | 1   | 1        | 1         |
-- | 4  | 2   | 1        | 1         |
-- | 5  | 1   | 2        | 1         |
-- | 6  | 2   | 1        | 2         |
-- | 7  | 2   | 2        | 1         |
-- */
-- SELECT DISTINCT
--     num AS ConsecutiveNums
-- FROM consecutive_nums
-- WHERE num = prev_num
--   AND num = prev2_num;

/*
| ConsecutiveNums |
| --------------- |
| 1               |
*/

-- others answer
# Write your MySQL query statement below

SELECT DISTINCT
    l1.num AS ConsecutiveNums
FROM Logs l1
JOIN Logs l2
    ON l2.id = l1.id + 1
JOIN Logs l3
    ON l3.id = l2.id + 1
WHERE
    l1.num = l2.num
    AND l2.num = l3.num;
/*
========================================================
SQL PATTERN: CONSECUTIVE / STREAK / GAPS & ISLANDS
========================================================

1. WHAT DOES "CONSECUTIVE" MEAN?
--------------------------------------------------------
Consecutive = rows next to each other according to some
ORDER BY column.

Example:

id   num
1    1
2    1
3    1
4    2
5    1
6    1

The first 1,1,1 is a consecutive streak.
The last 1,1 is a SEPARATE streak.

IMPORTANT:
GROUP BY num alone is WRONG because it combines
separate streaks of the same value.

Think:
"Consecutive" → I need to look at neighboring rows.


2. HOW DO I LOOK AT NEIGHBORING ROWS?
--------------------------------------------------------

LAG()   → looks BACK
LEAD()  → looks FORWARD

LAG(num, 1) → previous row
LAG(num, 2) → 2 rows before

LEAD(num, 1) → next row
LEAD(num, 2) → 2 rows after

Example:

id   num   LAG(num,1)   LAG(num,2)
1     1       NULL         NULL
2     1        1           NULL
3     1        1            1
4     2        1            1

For id = 3:

current = 1
previous = 1
2-before = 1

Therefore → 1 occurred 3 times consecutively.


3. HOW MANY CONSECUTIVE?
--------------------------------------------------------

"2 consecutive" means:

current = previous

Example:
1  1

"3 consecutive" means:

current = previous = 2-before

Example:
1  1  1

"4 consecutive" means:

current = previous = 2-before = 3-before

Example:
1  1  1  1

GENERAL IDEA:

N consecutive
→ compare current row with previous N-1 rows.


4. LAG() vs ROW_NUMBER() vs SUM()
--------------------------------------------------------

LAG()
→ Compare a row with previous/next rows.
→ Best for detecting a fixed-length consecutive pattern.

Example:
Find 3 consecutive same numbers.

LAG(num,1)
LAG(num,2)


ROW_NUMBER()
→ Gives every row a sequential number.

ROW_NUMBER() OVER (ORDER BY id)

1, 2, 3, 4, 5...

Useful when:
→ creating positions
→ comparing row positions
→ identifying gaps
→ building Gaps & Islands


SUM()
→ Creates a running total.
→ Very useful for assigning GROUP/ISLAND numbers.

Example idea:

New island? = 1
Same island? = 0

Running SUM of that flag:

0, 0, 1, 1, 1, 2...

This becomes the island/group ID.


5. GAPS & ISLANDS
--------------------------------------------------------

ISLAND = a continuous/consecutive group.

Example:

1  1  1 | 2 | 1  1 | 3  3  3

Island 1 → 1,1,1
Island 2 → 2
Island 3 → 1,1
Island 4 → 3,3,3

GAP = break between islands.

Use Gaps & Islands when the problem asks for:
→ consecutive days
→ streaks
→ continuous periods
→ longest streak
→ groups of consecutive values
→ gaps between events


6. HOW TO THINK ABOUT A CONSECUTIVE SQL PROBLEM
--------------------------------------------------------

STEP 1:
What column determines the ORDER?

Usually:
ORDER BY id
OR
ORDER BY date


STEP 2:
What value must remain the same?

Example:
num


STEP 3:
How many consecutive rows are required?

3 → compare current + previous 2


STEP 4:
Choose the technique.

Fixed number of consecutive rows?
→ LAG()

Need to identify entire streaks/islands?
→ LAG() + SUM()
OR
→ ROW_NUMBER() techniques


STEP 5:
After identifying groups:
→ GROUP BY
→ COUNT()
→ HAVING


7. LC 180 — CONSECUTIVE NUMBERS
--------------------------------------------------------

Question:
Find numbers appearing at least 3 times consecutively.

Think:

current = previous = 2-before

Therefore:

LAG(num,1)
LAG(num,2)


8. LC 180 SOLUTION
--------------------------------------------------------

WITH consecutive_nums AS (
    SELECT
        id,
        num,
        LAG(num, 1) OVER (ORDER BY id) AS prev_num,
        LAG(num, 2) OVER (ORDER BY id) AS prev2_num
    FROM Logs
)

SELECT DISTINCT
    num AS ConsecutiveNums
FROM consecutive_nums
WHERE num = prev_num
  AND num = prev2_num;


9. QUICK MEMORY MAP
--------------------------------------------------------

CONSECUTIVE
     ↓
Need ORDER BY
     ↓
Need neighboring rows?
     ↓
LAG() / LEAD()
     ↓
Fixed N consecutive?
     ↓
Compare current with N-1 previous rows


WHOLE STREAK / ISLAND?
     ↓
Detect where new group starts
     ↓
SUM() → group ID
     ↓
GROUP BY group ID
     ↓
COUNT() / MIN() / MAX()


ROW_NUMBER()
     ↓
Give rows positions
     ↓
Useful for gaps/islands and row comparisons


10. ONE-LINE MEMORY RULE
--------------------------------------------------------

"LAG = look back.
ROW_NUMBER = give position.
SUM = build running/group number.
GROUP BY + COUNT = analyze the group.

CONSECUTIVE → think NEIGHBORING ROWS first.
WHOLE STREAK → think GAPS & ISLANDS."
========================================================
*/