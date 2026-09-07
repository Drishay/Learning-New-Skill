# Write your MySQL query statement below
-- Find people who have the same 2015 investment as someone else, BUT live in a location where nobody else in 
-- the table lives. Then add up their 2016 investments.

/*
Person 1:
tiv_2015 = 10 → same as Person 3 and 4 ✅
location = (10,10) → unique ✅
→ Include tiv_2016 = 5

Person 2:
tiv_2015 = 20 → nobody else has 20 ❌
→ Exclude

Person 3:
tiv_2015 = 10 → same as Person 1 and 4 ✅
location = (20,20) → same as Person 2 ❌
→ Exclude

Person 4:
tiv_2015 = 10 → same as Person 1 and 3 ✅
location = (40,40) → unique ✅
→ Include tiv_2016 = 40

Final: 5 + 40 = 45.00
*/


SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
)
AND (lat, lon) IN (
    SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(*) = 1
);
