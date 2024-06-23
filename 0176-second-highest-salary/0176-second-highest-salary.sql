# Write your MySQL query statement below
SELECT MAX(a.salary) AS SecondHighestSalary FROM 
Employee a INNER JOIN
Employee b
ON a.salary<b.salary;