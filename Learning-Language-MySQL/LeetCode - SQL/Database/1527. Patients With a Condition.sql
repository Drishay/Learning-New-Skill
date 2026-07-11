# Write your MySQL query statement below
-- SELECT patient_id, patient_name, conditions
-- FROM Patients
-- WHERE conditions LIKE "%DIAB1%";

/*
--Wrong Answer
14 / 17 testcases passed

Editorial
Input
Patients =
| patient_id | patient_name | conditions |
| ---------- | ------------ | ---------- |
| 1          | Daniel       | SADIAB100  |

Use Testcase
Output
| patient_id | patient_name | conditions |
| ---------- | ------------ | ---------- |
| 1          | Daniel       | SADIAB100  |
Expected
| patient_id | patient_name | conditions |
| ---------- | ------------ | ---------- |

*/

SELECT patient_id, patient_name, conditions
FROM Patients
WHERE 
    conditions LIKE "DIAB1%"
    OR
    conditions LIKE "% DIAB1%"
; 

-- conditions LIKE "DIAB1%" checks for the prefix in start.
-- conditions LIKE "% DIAB1%" check for the prefic in the second string, and the space helps to differentiate btw first and second string.
