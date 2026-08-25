/*
===========================================================
LEETCODE 1174 - IMMEDIATE FOOD DELIVERY II
===========================================================

MY THINKING / JOURNEY
---------------------

Goal:
For every customer, we need to consider ONLY their FIRST order.

Then:
    If order_date = customer_pref_delivery_date
        → Immediate order
    Else
        → Scheduled order

Finally:
    immediate orders / total customers * 100


===========================================================
APPROACH 1 - TRYING TO USE ORDER BY + GROUP BY
===========================================================

My first thought was:

"If I sort the table by order_date ASC and then GROUP BY
customer_id, maybe GROUP BY will take the first row for
each customer."

I tried:

WITH Table1 AS
(
    SELECT customer_id, order_date, customer_pref_delivery_date
    FROM Delivery
    ORDER BY order_date ASC
)

Then:

SELECT customer_id, order_date, customer_pref_delivery_date
FROM Table1
GROUP BY customer_id;


PROBLEM:
--------

I expected customer 3 to give:

customer 3 → 2019-08-21

But I got:

customer 3 → 2019-08-24


WHY?

Because ORDER BY and GROUP BY do different jobs.

ORDER BY:
    Sorts the result.

GROUP BY:
    Creates groups based on a column.

GROUP BY does NOT mean:

    "Take the first row from the sorted table."

SQL does not guarantee which row's non-grouped
columns will be returned.

IMPORTANT LESSON:

    ORDER BY ≠ choosing a row

If I need the earliest date, I should explicitly use:

    MIN(order_date)


===========================================================
APPROACH 2 - USING MIN(order_date)
===========================================================

I then realized:

    MIN(order_date)

can be used with dates.

So I tried to get:

customer_id + MIN(order_date)

This correctly gives:

| customer_id | first_order |
|-------------|-------------|
| 1           | 2019-08-01  |
| 2           | 2019-08-02  |
| 3           | 2019-08-21  |
| 4           | 2019-08-09  |


BUT I GOT STUCK:
----------------

MIN(order_date) gives me the earliest date.

But I ALSO need:

    customer_pref_delivery_date

from THAT SAME ROW.


For example:

Customer 3:

2019-08-21 → 2019-08-22
2019-08-24 → 2019-08-24

MIN(order_date)
    ↓
2019-08-21

But I need the preference date belonging to
2019-08-21:

    2019-08-22


So the problem became:

    "How do I get the other columns from the row
     containing MIN(order_date)?"


===========================================================
KEY INSIGHT
===========================================================

I realized that:

    MIN(order_date)

only tells me WHICH order I want.

It does not automatically give me the other columns
from that row.

Therefore:

    STEP 1 → Find the first order for every customer.
    STEP 2 → JOIN that result back to Delivery.
    STEP 3 → Retrieve customer_pref_delivery_date
             from that exact row.


Mental model:

Delivery
   ↓
GROUP BY customer_id
   ↓
MIN(order_date)
   ↓
"I now know each customer's first order"
   ↓
JOIN back to Delivery
   ↓
"Give me the complete row"
   ↓
Compare order_date with customer_pref_delivery_date
   ↓
Calculate percentage


This is a very important SQL pattern:

    Find MIN/MAX value
          +
    Need other columns from the same row
          ↓
    Find the row first
          ↓
    JOIN back to the original table


===========================================================
APPROACH 3 - TRYING TO JOIN IMMEDIATE ORDERS
===========================================================

I tried:

SELECT
    tab1.customer_id,
    MIN(tab1.order_date) AS order_date,
    tab2.customer_pref_delivery_date
FROM Delivery AS tab1
LEFT JOIN
(
    SELECT order_date, customer_pref_delivery_date
    FROM Delivery
    WHERE order_date = customer_pref_delivery_date
) AS tab2
ON tab1.order_date = tab2.order_date
GROUP BY customer_id;


PROBLEM 1:
----------

I was filtering:

    WHERE order_date = customer_pref_delivery_date

too early.

That means I was first finding IMMEDIATE orders.

But the problem asks:

    1. Find the FIRST order.
    2. Then check whether that first order was immediate.

So the correct order of thinking is:

    FIRST ORDER
        ↓
    CHECK IF IMMEDIATE


NOT:

    IMMEDIATE ORDER
        ↓
    Find FIRST


PROBLEM 2:
----------

I joined using only:

    tab1.order_date = tab2.order_date

But order_date alone may not uniquely identify
a customer's order.

I should connect both:

    customer_id
    +
    order_date


===========================================================
APPROACH 4 - REVERSE THE LOGIC
===========================================================

I then thought:

"Instead of starting with Delivery and trying to find
the first order, why don't I FIRST create a table that
contains each customer's first order?"

So I created:

SELECT
    customer_id,
    MIN(order_date) AS order_date
FROM Delivery
GROUP BY customer_id;


This produces:

| customer_id | order_date |
|-------------|------------|
| 1           | 2019-08-01 |
| 2           | 2019-08-02 |
| 3           | 2019-08-21 |
| 4           | 2019-08-09 |


Now I have exactly what I need to identify
the first order.

Then I JOIN this result back to Delivery.

This was the breakthrough.


===========================================================
APPROACH 5 - FINAL SOLUTION
===========================================================

WITH table1 AS
(
    SELECT
        tab2.customer_id,
        tab2.order_date,
        tab1.customer_pref_delivery_date
    FROM Delivery AS tab1
    RIGHT JOIN
    (
        SELECT
            customer_id,
            MIN(order_date) AS order_date
        FROM Delivery
        GROUP BY customer_id
    ) AS tab2
    ON tab1.customer_id = tab2.customer_id
    AND tab1.order_date = tab2.order_date
)

SELECT
    ROUND(
        SUM(
            IF(
                order_date = customer_pref_delivery_date,
                1,
                0
            )
        )
        / COUNT(customer_id) * 100,
        2
    ) AS immediate_percentage
FROM table1;


===========================================================
HOW THE FINAL SOLUTION WORKS
===========================================================

PART 1:
-------

SELECT customer_id, MIN(order_date)
FROM Delivery
GROUP BY customer_id

Meaning:

    Find the earliest order for every customer.


PART 2:
-------

JOIN back to Delivery using:

    customer_id
    AND
    order_date


Why BOTH?

Because we want:

    "The exact row belonging to this customer
     AND their earliest order."


This gives:

| customer_id | order_date | customer_pref_delivery_date |
|-------------|------------|-----------------------------|
| 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 2019-08-02 | 2019-08-02                  |
| 3           | 2019-08-21 | 2019-08-22                  |
| 4           | 2019-08-09 | 2019-08-09                  |


PART 3:
-------

Check:

    order_date = customer_pref_delivery_date


Customer 1:

    2019-08-01 ≠ 2019-08-02
    → Not immediate


Customer 2:

    2019-08-02 = 2019-08-02
    → Immediate


Customer 3:

    2019-08-21 ≠ 2019-08-22
    → Not immediate


Customer 4:

    2019-08-09 = 2019-08-09
    → Immediate


Therefore:

    Immediate orders = 2
    Total customers = 4

    2 / 4 × 100 = 50%


===========================================================
IMPORTANT SQL LESSONS FROM THIS PROBLEM
===========================================================

1. ORDER BY does NOT mean "take the first row".

2. GROUP BY creates groups; it doesn't automatically
   select the earliest/latest row.

3. MIN() works perfectly with DATE values.

4. MIN(order_date) tells us the earliest date,
   but does NOT automatically give us other columns
   from that row.

5. If I need other columns from the MIN/MAX row:

       Find MIN/MAX
           ↓
       Identify the row
           ↓
       JOIN back to original table

6. When joining to identify an exact row, think about
   what columns are required to uniquely connect it.

7. Don't filter for the final condition too early.

   First identify the relevant rows.
   Then apply the condition.

8. Break complicated SQL problems into stages:

       What rows do I need?
            ↓
       How do I identify them?
            ↓
       What information do I need from those rows?
            ↓
       What calculation do I perform?


===========================================================
THE BIGGEST THING I LEARNED
===========================================================

Initially I was thinking:

    "How can I make GROUP BY give me the first row?"

Now I understand:

    "I don't need GROUP BY to give me the first row.

     I can explicitly find the first date using MIN(),
     then use that information to retrieve the
     corresponding row."

This changed my thinking from:

    ORDER BY → GROUP BY → somehow get first row

to:

    GROUP BY
        ↓
    MIN(order_date)
        ↓
    identify first order
        ↓
    JOIN back
        ↓
    get remaining columns
        ↓
    calculate result


This is the main SQL pattern I should remember from
LeetCode 1174.
*/