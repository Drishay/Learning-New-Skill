# Write your MySQL query statement below
/*
Three side lengths can form a triangle if and only if the sum of the lengths of any two sides is
strictly greater than the length of the third side.

The Triangle Inequality RuleIf your three given sides are named \(a\), \(b\), and \(c\), they must satisfy all three of these conditions at the same time:\(a + b > c\)\(b + c > a\)\(c + a > b\)


it is strictly an "and" condition—all three inequalities must be true simultaneously. If even one of those conditions fails, the sides cannot connect to form a closed triangle.
*/

-- SELECT x,y,z, IF((x+y > z) AND (y+z > x) AND (z+x > y), "Yes", "No") AS triangle
-- FROM Triangle;

SELECT *, IF((x+y > z) AND (y+z > x) AND (z+x > y), "Yes", "No") AS triangle
FROM Triangle;

