# Write your MySQL query statement below
UPDATE Salary
SET sex = IF(sex = 'm', 'f', 'm')
WHERE sex IN ('m', 'f');


/*
UPDATE Salary
SET sex = CASE 
    WHEN sex = 'm' THEN 'f'
    WHEN sex = 'f' THEN 'm'
    ELSE sex -- Keeps any other values (like NULL) unchanged
END
WHERE sex IN ('m', 'f'); -- Limits the update to relevant rows
*/