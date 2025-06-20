# Write your MySQL query statement below
SELECT
     name
FROM
     SalesPerson
WHERE 
    sales_id not in (
        SELECT
            sales_id
        FROM 
         Orders
        WHERE
            com_id = (
                SELECT
                    com_id 
                FROM 
                    Company 
                WHERE
                    name = 'RED'))