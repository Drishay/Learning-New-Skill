# Write your MySQL query statement below
-- WITH Table1 AS
-- (
--     SELECT *
--     FROM Queue
--     ORDER BY turn
-- )
/*
| person_id | person_name | weight | turn |
| --------- | ----------- | ------ | ---- |
| 5         | Alice       | 250    | 1    |
| 3         | Alex        | 350    | 2    |
| 6         | John Cena   | 400    | 3    |
| 2         | Marie       | 200    | 4    |
| 4         | Bob         | 175    | 5    |
| 1         | Winston     | 500    | 6    |
*/

-- I need to calculate the cumulative sum of the weights until the total reaches 1,000 kg or more. At the specific
-- row where this threshold is met or exceeded, I need to output that person's name.

-- I can do this using loop in a Python or C++, but how to do this in MySql
-- I can use LAG() OR LEAD(), like the 180 consecutive questions, i can create a column where it adds the last 




-- SELECT turn, person_id, person_name, weight, (LAG(weight,1) + weight) AS cumulative_sum
-- FROM table1;

/*
The main logic error is that LAG(weight, 1) + weight does not calculate a cumulative sum (running total). It only adds the previous row's weight to the current row's weight.
Additionally, standard SQL window functions like LAG require an OVER clause to define the row order.
❌ The Problems
Wrong Logic: It only sums two adjacent rows, not all preceding rows.
Missing OVER Clause: Window functions fail without an OVER (ORDER BY ...) specification.
Null Handling: The first row will return NULL because the first LAG result is NULL.
The Fix-
To calculate a true cumulative sum (running total), use the SUM() function combined with the OVER clause ordered by your sequence column (likely turn).
*/
WITH table1 as
(
    SELECT 
        turn, 
        person_id, 
        person_name, 
        weight, 
        SUM(weight) OVER (ORDER BY turn) AS cumulative_sum 
    FROM Queue
),

/*
| turn | person_id | person_name | weight | cumulative_sum |
| ---- | --------- | ----------- | ------ | -------------- |
| 1    | 5         | Alice       | 250    | 250            |
| 2    | 3         | Alex        | 350    | 600            |
| 3    | 6         | John Cena   | 400    | 1000           |
| 4    | 2         | Marie       | 200    | 1200           |
| 5    | 4         | Bob         | 175    | 1375           |
| 6    | 1         | Winston     | 500    | 1875           |
*/

-- Now, filter rows where the running total is 1,000 or less.
table2 as
(
    SELECT *
    FROM table1
    WHERE cumulative_sum <= 1000
)
/*
| turn | person_id | person_name | weight | cumulative_sum |
| ---- | --------- | ----------- | ------ | -------------- |
| 1    | 5         | Alice       | 250    | 250            |
| 2    | 3         | Alex        | 350    | 600            |
| 3    | 6         | John Cena   | 400    | 1000           |
*/

-- NOW, access the last row only
-- SELECT * 
-- FROM table2 
-- ORDER BY turn DESC;

/*
| turn | person_id | person_name | weight | cumulative_sum |
| ---- | --------- | ----------- | ------ | -------------- |
| 3    | 6         | John Cena   | 400    | 1000           |
| 2    | 3         | Alex        | 350    | 600            |
| 1    | 5         | Alice       | 250    | 250            |
*/

-- i can add limit in the query for just one row. 

SELECT person_name
FROM table2 
ORDER BY turn DESC 
LIMIT 1;

/* shorter way of writing
WITH table1 AS (
    SELECT 
        person_name, 
        turn,
        SUM(weight) OVER (ORDER BY turn) AS cumulative_sum 
    FROM Queue
)
SELECT person_name
FROM table1
WHERE cumulative_sum <= 1000
ORDER BY turn DESC
LIMIT 1;
*/


/* Solution by other user
# Write your MySQL query statement below
SELECT G.person_name
FROM (SELECT turn,person_id,person_name,weight,
SUM(weight) OVER (ORDER BY turn) AS Total_Weight
FROM Queue
ORDER BY turn) AS G
WHERE G.Total_Weight<=1000
ORDER BY G.Total_Weight DESC
LIMIT 1;

*/