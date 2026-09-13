# Write your MySQL query statement below
-- SELECT 
--     t1.id,
--     t1.p_id AS parent,
--     JSON_ARRAYAGG(t2.id) AS children
-- FROM Tree AS t1
-- LEFT JOIN Tree AS t2
--     ON t1.id = t2.p_id
-- GROUP BY t1.id, t1.p_id;
/*
| id | parent | children |
| -- | ------ | -------- |
| 1  | null   | [3, 2]   |
| 2  | 1      | [5, 4]   |
| 3  | 1      | [null]   |
| 4  | 2      | [null]   |
| 5  | 2      | [null]   |
*/

-- SELECT t1.id, t1.p_id as parent, GROUP_CONCAT(t2.id ORDER BY t2.id) as child
-- FROM Tree as t1
-- LEFT JOIN Tree as t2
-- ON t1.id = t2.p_id
-- GROUP BY t1.id;
/*
| id | parent | child |
| -- | ------ | ----- |
| 1  | null   | 2,3   |
| 2  | 1      | 4,5   |
| 3  | 1      | null  |
| 4  | 2      | null  |
| 5  | 2      | null  |
*/


# logic building 

-- SELECT t1.id,
--     t1.p_id as parent, 
--     COUNT(t2.p_id) as child
-- FROM Tree as t1
-- LEFT JOIN Tree as t2
-- ON t1.id = t2.p_id
-- GROUP BY t1.id;
/*
| id | parent | child |
| -- | ------ | ----- |
| 1  | null   | 2     |
| 2  | 1      | 2     |
| 3  | 1      | 0     |
| 4  | 2      | 0     |
| 5  | 2      | 0     |
*/
-- now, i want to add a columns for type, where parent is null -> root, child  is 0 -> leaf, else inner

SELECT t1.id,
    CASE
        WHEN t1.p_id IS NULL THEN 'Root'
        WHEN COUNT(t2.p_id) = 0 THEN 'Leaf'
        ELSE 'Inner'
    END AS type
FROM Tree as t1
LEFT JOIN Tree as t2
ON t1.id = t2.p_id
GROUP BY t1.id;
/*
| id | type  |
| -- | ----- |
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |
| 5  | Leaf  |
*/

# CHAT GPT solution
-- SELECT
--     id,
--     CASE
--         WHEN p_id IS NULL THEN 'Root'
--         WHEN id NOT IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL)
--             THEN 'Leaf'
--         ELSE 'Inner'
--     END AS type
-- FROM Tree;


# other used solution
# Write your MySQL query statement below
-- SELECT id,CASE WHEN p_id IS NULL THEN "Root" WHEN id IN (SELECT DISTINCT p_id FROM Tree) 
-- THEN "Inner" ELSE "Leaf" END AS type FROM Tree;