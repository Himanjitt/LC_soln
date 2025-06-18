# Write your MySQL query statement below
SELECT
    e2.name as employee
FROM 
    employee e1
JOIN
    employee e2 
    on e1.id = e2.managerid
WHERE
    e2.salary > e1.salary;