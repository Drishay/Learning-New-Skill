# Write your MySQL query statement below
-- SELECT
--     id,
--     visit_date,
--     people,
--     IF(people>=100, 1, 0) as present_people,
--     CASE 
--         WHEN LEAD(people, 1) OVER (ORDER BY id) >= 100 THEN 1 
--         ELSE 0 
--     END AS next1_people,
--     IF(LEAD(people, 2) OVER (ORDER BY id) >= 100, 1,0) as next2_people
--     -- In standard SQL, you cannot use an IF statement directly like this with window functions
-- FROM Stadium;
/*
| id | visit_date | people | present_people | next1_people | next2_people |
| -- | ---------- | ------ | -------------- | ------------ | ------------ |
| 1  | 2017-01-01 | 10     | 0              | 1            | 1            |
| 2  | 2017-01-02 | 109    | 1              | 1            | 0            |
| 3  | 2017-01-03 | 150    | 1              | 0            | 1            |
| 4  | 2017-01-04 | 99     | 0              | 1            | 1            |
| 5  | 2017-01-05 | 145    | 1              | 1            | 1            |
| 6  | 2017-01-06 | 1455   | 1              | 1            | 1            |
| 7  | 2017-01-07 | 199    | 1              | 1            | 0            |
| 8  | 2017-01-09 | 188    | 1              | 0            | 0            |
*/



-- WITH table1 AS
-- (
--     SELECT
--         id,
--         visit_date,
--         people,
--         IF(people>=100, 1, 0) as present_people,
--         CASE
--             WHEN LEAD(people, 1) OVER (ORDER BY id) >= 100 THEN 1
--             WHEN LEAD(people, 1) OVER (ORDER BY id) < 100 THEN 0
--             ELSE NULL
--         END AS next1_people,
--         CASE
--             WHEN LEAD(people, 2) OVER (ORDER BY id) >= 100 THEN 1
--             WHEN LEAD(people, 2) OVER (ORDER BY id) < 100 THEN 0
--             ELSE NULL
--         END AS next2_people
--     FROM Stadium
-- )
/*
| id | visit_date | people | present_people | next1_people | next2_people |
| -- | ---------- | ------ | -------------- | ------------ | ------------ |
| 1  | 2017-01-01 | 10     | 0              | 1            | 1            |
| 2  | 2017-01-02 | 109    | 1              | 1            | 0            |
| 3  | 2017-01-03 | 150    | 1              | 0            | 1            |
| 4  | 2017-01-04 | 99     | 0              | 1            | 1            |
| 5  | 2017-01-05 | 145    | 1              | 1            | 1            |
| 6  | 2017-01-06 | 1455   | 1              | 1            | 1            |
| 7  | 2017-01-07 | 199    | 1              | 1            | null         |
| 8  | 2017-01-09 | 188    | 1              | null         | null         |
*/
-- SELECT id, visit_date, people
-- FROM table1
-- WHERE
--     present_people = 1
--     AND (next1_people = 1 OR next1_people IS NULL)
--     AND (next2_people = 1 OR next2_people IS NULL)
-- ORDER BY visit_date ASC;





/* -- Solution updated by chat

Why your solution failed
Your logic was:

present = 1
AND (next1 = 1 OR next1 IS NULL)
AND (next2 = 1 OR next2 IS NULL)

The problem is that NULL means there is no next row, not that the condition is satisfied.

So for the last row:

id=3, people=150
next1 = NULL
next2 = NULL

your condition treats it as valid, even though there are only 2 consecutive qualifying rows, not 3.

What changed
Instead of only looking forward with LEAD(), we check both directions using LAG() and LEAD():

(prev2 >= 100 AND prev1 >= 100)
OR
(prev1 >= 100 AND next1 >= 100)
OR
(next1 >= 100 AND next2 >= 100)

This means the current row is returned only if it is part of 3 consecutive rows with people >= 100.

So:

10, 109, 150

has only 2 qualifying rows → return nothing.

Whereas:

10, 109, 150, 145

has 3 consecutive qualifying rows → return 109, 150, 145.

Main lesson: NULL should not be treated as a successful condition. Your original query effectively allowed the sequence to end early.

WITH table1 AS
(
    SELECT
        id,
        visit_date,
        people,

        LAG(people, 2) OVER (ORDER BY id) AS prev2_people,
        LAG(people, 1) OVER (ORDER BY id) AS prev1_people,

        LEAD(people, 1) OVER (ORDER BY id) AS next1_people,
        LEAD(people, 2) OVER (ORDER BY id) AS next2_people

    FROM Stadium
)
SELECT id, visit_date, people
FROM table1
WHERE
    people >= 100
    AND (
        -- current row is the 3rd row
        (prev2_people >= 100 AND prev1_people >= 100)

        OR

        -- current row is the middle row
        (prev1_people >= 100 AND next1_people >= 100)

        OR

        -- current row is the 1st row
        (next1_people >= 100 AND next2_people >= 100)
    )
ORDER BY visit_date;
*/




WITH filtered AS (
    SELECT
        id,
        visit_date,
        people,
        ROW_NUMBER() OVER (ORDER BY id) AS rn
    FROM Stadium
    WHERE people >= 100
),
grouped AS (
    SELECT
        id,
        visit_date,
        people,
        id - rn AS grp
    FROM filtered
)
SELECT
    id,
    visit_date,
    people
FROM grouped
WHERE grp IN (
    SELECT grp
    FROM grouped
    GROUP BY grp
    HAVING COUNT(*) >= 3
)
ORDER BY visit_date;