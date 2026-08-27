# Write your MySQL query statement below
-- SELECT class
-- FROM   
--     (SELECT class, count(student) as students
--     FROM Courses
--     GROUP BY class) as grouped_students
-- WHERE students >=5; 

SELECT class
FROM Courses
GROUP BY class
HAVING count(student) >=5;

# Remember 
-- WHERE SUM(salary) > 500000; -- Invalid!
-- better use having : GROUP BY department HAVING SUM(salary) > 500000;

-- WHERE salary > AVG(salary); -- Invalid!
-- WHERE salary > (SELECT AVG(salary) FROM employees);