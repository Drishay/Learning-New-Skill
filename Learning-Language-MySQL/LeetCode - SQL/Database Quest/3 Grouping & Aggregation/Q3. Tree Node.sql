# Write your MySQL query statement below
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