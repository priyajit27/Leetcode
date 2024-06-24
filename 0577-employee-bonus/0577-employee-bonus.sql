# Write your MySQL query statement below
SELECT name,bonus
FROM
Employee as a 
LEFT JOIN Bonus as b
ON a.empId=b.empId
WHERE b.bonus IS NULL 
OR b.bonus<1000

