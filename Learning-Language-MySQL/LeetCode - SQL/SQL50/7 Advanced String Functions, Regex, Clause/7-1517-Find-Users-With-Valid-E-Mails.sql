# Write your MySQL query statement below
/*
A valid e-mail has a prefix name and a domain where:
- The domain must be exactly '@leetcode.com' in lowercase.
- FOR prefix name
    - may contain upper or lower case letters
    - digits or number
    - symbols like underscore '_', period '.', and/or dash '-'
    - prefix name must start with a letter i.e first character cannot be number or symbol

*/

-- SELECT * FROM Users WHERE mail LIKE "%@leetcode.com";
/*
| user_id | name      | mail                    |
| ------- | --------- | ----------------------- |
| 1       | Winston   | winston@leetcode.com    |
| 3       | Annabelle | bella-@leetcode.com     |
| 4       | Sally     | sally.come@leetcode.com |
| 5       | Marwan    | quarz#2020@leetcode.com |
| 7       | Shapiro   | .shapo@leetcode.com     |
*/

-- SELECT *
-- FROM Users
-- WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$';

/*
Regular Expressions (Regex) in SQL allow you to search, filter, extract, and replace text based on complex patterns
rather than exact matches. While standard string functions like LIKE handle basic wildcard filtering (e.g., 
%keyword%), regex handles advanced tasks like validating emails, phone numbers, or extracting subdomains

How the regex works
^                  -- start of string
[A-Za-z]           -- first character MUST be a letter
[A-Za-z0-9_.-]*   -- remaining prefix: letters/digits/_/./-
@leetcode\\.com    -- exact domain
$                  -- end of string

*/

/*
Wrong Answer 27 / 29 testcases passed

Input
Users =
| user_id | name    | mail                 |
| ------- | ------- | -------------------- |
| 1       | Winston | winston@leetcode.COM |

Use Testcase
Output
| user_id | name    | mail                 |
| ------- | ------- | -------------------- |
| 1       | Winston | winston@leetcode.COM |

Expected
| user_id | name | mail |
| ------- | ---- | ---- |

MySQL REGEXP can be case-insensitive depending on the column's collation, so [A-Za-z] alone may not guarantee that 
@leetcode.com is lowercase.
*/

-- SELECT *
-- FROM Users
-- WHERE mail REGEXP BINARY '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$';

/*
Why BINARY?
It makes the regex comparison case-sensitive.

So:

abc@leetcode.com → ✅
abc@LeetCode.com → ❌
abc@LEETCODE.COM → ❌
Abc123-._@leetcode.com → ✅
1abc@leetcode.com → ❌
.abc@leetcode.com → ❌
abc#123@leetcode.com → ❌
The key part is:
*/

-- Character set 'utf8mb3_general_ci' cannot be used in conjunction with 'binary' in call to regexp_like.
-- LeetCode's MySQL version/collation doesn't allow REGEXP BINARY in that form.
-- A cleaner solution is to explicitly compare the domain using a binary/case-sensitive comparison, while using 
-- regex only for the prefix:

# SOLUTIONS

-- SELECT *
-- FROM Users
-- WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$'
--   AND RIGHT(mail, 13) = BINARY '@leetcode.com';

SELECT *
FROM Users
WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$'
  AND mail LIKE BINARY '%@leetcode.com';

# RUN for test cases
-- SELECT *
-- FROM Users
-- WHERE SUBSTRING_INDEX(mail, '@', 1) REGEXP '^[A-Za-z][A-Za-z0-9_.-]*$'
--   AND SUBSTRING_INDEX(mail, '@', -1) = BINARY 'leetcode.com';
