# Write your MySQL query statement below

#make the table after joining , easy
SELECT
    c.name AS customers
FROM 
    customers c
LEFT JOIN 
    orders o
    on c.id = o.customerId
WHERE
    o.customerid IS NULL;
