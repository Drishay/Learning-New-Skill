# Write your MySQL query statement below
-- i could use, after the sorting in DESC, i can use "IN" operator to look for the "visited_on - 6" in the table, if present, then add the sum from visited_on to visited_on-6;

-- SELECT visited_on, AVG(amount) AS amount
-- FROM Customer
-- GROUP BY visited_on;

/*
| visited_on | amount |
| ---------- | ------ |
| 2019-01-01 | 100    |
| 2019-01-02 | 110    |
| 2019-01-03 | 120    |
| 2019-01-04 | 130    |
| 2019-01-05 | 110    |
| 2019-01-06 | 140    |
| 2019-01-07 | 150    |
| 2019-01-08 | 80     |
| 2019-01-09 | 110    |
| 2019-01-10 | 140    |
*/

-- Now, building on above.

-- SELECT 
--     visited_on, 
--     IF(visited_on - 6 IN (SELECT visted_on FROM Customer) as a, 
--         (SELECT SUM(amount) FROM Customer WHERE visited_on >= visted_on - 6) as b, 
--         0) as amount,
--     IF(visited_on - 6 IN (SELECT visted_on FROM Customer), 
--         (SELECT AVG(amount) FROM Customer WHERE visited_on >= visted_on - 6) as c, 
--         0) as average_amount
-- FROM 
--     (
--         SELECT visited_on, AVG(amount) AS amount
--         FROM Customer
--         GROUP BY visited_on
--     ) as d;

-- ABOVE is what I am thinking.

-- Doing chat gpt, Yep — your core idea is correct: first collapse multiple customer rows into one row per 
-- visited_on, then for each date look backward 6 days and calculate the 7-day total.

/*
WHAT I DID WRONG:

1. Used AVG(amount) when grouping by date.
   WRONG:  AVG(amount)
   CORRECT: SUM(amount)
   -> We need the total amount spent on each day.

2. Used "visited_on - 6".
   -> MySQL DATE should use:
      DATE_SUB(visited_on, INTERVAL 6 DAY)

3. Misspelled "visited_on" as "visted_on".

4. My subquery:
      WHERE visited_on >= visited_on - 6
   is ambiguous.
   -> Both visited_on refer to the inner table.
   -> I need an alias for the OUTER table, e.g. d.visited_on.

5. I used AVG(amount) again for average_amount.
   -> The problem wants:
      7-day total / 7
   -> NOT the average of individual customer amounts.

HOW TO DO IT WITH MY LOGIC:

My original idea was:
"Check whether visited_on - 6 exists, and if it does,
calculate the sum from visited_on - 6 to visited_on."

That logic is valid.

I should:

1. First create daily totals:
      SELECT visited_on, SUM(amount)
      FROM Customer
      GROUP BY visited_on

2. For each date (outer row), check whether:
      DATE_SUB(d.visited_on, INTERVAL 6 DAY)
   exists in the daily dates.

3. If it exists, calculate:
      SUM(amount)
   for dates between:
      DATE_SUB(d.visited_on, INTERVAL 6 DAY)
      AND d.visited_on

4. Then calculate:
      SUM(amount) / 7

5. Dates where the 6-days-before date doesn't exist
   should be excluded.

NOTE:
The SELF JOIN approach is cleaner, but my original
"check 6 days before → calculate 7-day sum" idea
can also be used.
*/

SELECT
    d.visited_on,
    SUM(w.amount) AS amount,
    ROUND(SUM(w.amount) / 7, 2) AS average_amount
FROM
    (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) d
JOIN
    (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) w
ON w.visited_on BETWEEN
       DATE_SUB(d.visited_on, INTERVAL 6 DAY)
       AND d.visited_on
GROUP BY
    d.visited_on
HAVING
    COUNT(w.visited_on) = 7
ORDER BY
    d.visited_on;


/*
# Write your MySQL query statement below

with cte as(
    select visited_on, sum(amount) as total_amount
    from Customer
    group by visited_on
),
cte2 as(
    select visited_on, sum(total_amount) over(order by visited_on rows between 6 preceding and current row) as total, rank() over(order by visited_on) as rn
    from cte
)

select visited_on, total as amount, round((total/7),2) as average_amount
from cte2
where rn>=7;
*/