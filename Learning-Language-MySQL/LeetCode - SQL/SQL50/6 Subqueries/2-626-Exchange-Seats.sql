# Write your MySQL query statement below
-- can i just access the even rows? because my logic "when id is even, i want that current student should swap with the last student"
/*
Method 1: Using ROW_NUMBER() This method assigns a temporary sequential number to every row based on your 
sorting rule, then filters for even numbers.
SELECT * 
FROM (
    SELECT *, ROW_NUMBER() OVER (ORDER BY column_name) AS row_num
    FROM table_name
) ranked
WHERE row_num % 2 = 0;

Method 2: Using an Existing ID Column - If your table already has an auto-incrementing or sequential numeric 
primary key, you can use the modulo operator (%) directly.
SELECT * 
FROM table_name 
WHERE id_column % 2 = 0;
*/


-- Now I have to update the table.
-- I HAVE to use set.

-- WITH table1 as
-- (
--     UPDATE Seat
--     SET Seat.id = LAG(seat.id, 1) OVER BY id
--     WHERE id%2=0
-- )
-- SELECT * FROM table_name;

# Reading more and see the logic
-- SELECT IF(id%2=0, id+1, id-1) as id, student
-- FROM Seat;

-- error in logic

# again, thinking same and then UNION
-- SELECT IF(id%2=0, id-1, -1) as id, student
-- FROM Seat
-- WHERE id%2 = 0;
/*
| id | student |
| -- | ------- |
| 1  | Doris   |
| 3  | Green   |
*/

-- SELECT IF(id%2 != 0, id+1, -1) as id, student
-- FROM Seat
-- WHERE id%2 != 0 ;
/*
| id | student |
| -- | ------- |
| 2  | Abbot   |
| 4  | Emerson |
| 6  | Jeames  |
*/

# thought to not count last row when id is odd
-- SELECT IF(id%2 != 0, id+1, -1) as id, student
-- FROM Seat
-- WHERE (id%2 != 0 AND (LEAD(id,1) OVER BY id) IS NOT NULL);
# syntax wrong + we cannot use CTE function in where clause;



-- again rethink #Working

# for even
SELECT IF(id%2=0, id-1, -1) as id, student
FROM Seat
WHERE id%2 = 0
/*
| id | student |
| -- | ------- |
| 1  | Doris   |
| 3  | Green   |
*/

# for odd

-- SELECT IF(id+1 IS NOT NULL, id+1, -1) as id, student
-- FROM Seat
-- WHERE id%2 != 0;
/* error in IF(id+1 IS NOT NULL) , If you want to keep exactly this style with IF(), you need to check whether the 
row with id + 1 exists, not whether the expression id + 1 is NULL.
*/
UNION

SELECT IF(
    (SELECT id FROM Seat s2 WHERE s2.id = Seat.id + 1) IS NOT NULL, id + 1, id) AS id, student
FROM Seat
WHERE id % 2 != 0
/*
| id | student |
| -- | ------- |
| 2  | Abbot   |
| 4  | Emerson |
| 5  | Jeames  |
*/
ORDER BY id;
/*
| id | student |
| -- | ------- |
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
*/


/* gpts solution
SELECT
    CASE
        WHEN id % 2 = 0 THEN id - 1
        WHEN EXISTS (SELECT 1 FROM Seat s2 WHERE s2.id = Seat.id + 1)
            THEN id + 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;

*/

/*
UPDATE Seat s1
JOIN Seat s2
    ON s2.id = CASE
                  WHEN s1.id % 2 = 0 THEN s1.id - 1
                  ELSE s1.id + 1
               END
SET s1.student = s2.student;
*/

/*
SELECT
    CASE
        WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat)
            THEN id
        WHEN id % 2 = 1
            THEN id + 1
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id;
*/


/* OTHER USER CODE
# Write your MySQL query statement below
SELECT
    CASE
        WHEN id = (SELECT MAX(id) FROM Seat)
             AND id % 2 = 1
        THEN id
        WHEN id % 2 = 1
        THEN id + 1
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id;
*/