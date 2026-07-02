-- Select the employee ID
SELECT employee_id,

    -- If employee_id is odd AND name does not start with 'M',
    -- bonus = salary, otherwise bonus = 0
    IF(employee_id % 2 != 0 AND name NOT LIKE 'M%', salary, 0) AS bonus

-- Read data from the Employees table
FROM Employees

-- Sort the result by employee_id in ascending order
ORDER BY employee_id;