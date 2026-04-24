-- i need customers who never order anything
/* how ?
use set theory
Customer - Order = Customers who never order anything
*/



-- using not in
SELECT name
FROM Customers
WHERE id NOT IN (
    SELECT customerId
    FROM Orders
);

-- Using NOT EXISTS
SELECT name
FROM Customers c
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders o
    WHERE o.customerId = c.id
);

-- Using EXCEPT (Pure Set Theory)
SELECT id FROM Customers
EXCEPT
SELECT customerId FROM Orders;

SELECT name
FROM Customers
WHERE id IN (
    SELECT id FROM Customers
    EXCEPT
    SELECT customerId FROM Orders
);



-- I know with JOIN I can do this, USING LEFT JOIN
-- Submitted at leetcode
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerId
WHERE o.customerId IS NULL;