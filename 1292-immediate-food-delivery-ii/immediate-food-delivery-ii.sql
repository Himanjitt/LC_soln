# Write your MySQL query statement below


SELECT ROUND(
    SUM(CASE WHEN d.customer_pref_delivery_date = f.first_order_date THEN 1 ELSE 0 END) * 100 / COUNT(*)
, 2) AS immediate_percentage
FROM delivery d
LEFT JOIN (SELECT  customer_id, MIN(order_date) AS first_order_date
FROM delivery
GROUP BY customer_id ) f
ON d.customer_id = f.customer_id
WHERE d.order_date = f.first_order_date;


