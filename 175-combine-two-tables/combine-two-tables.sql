# Write your MySQL query statement below
#Write a solution to report the first name, last name, city, and state of each person in the Person

SELECT
    person.firstName,
    person.lastName,
    address.city,
    address.state
FROM
    person
LEFT JOIN 
    address ON 
    person.personId = address.personId;
