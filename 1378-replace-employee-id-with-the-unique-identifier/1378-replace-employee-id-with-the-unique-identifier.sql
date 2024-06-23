# Write your MySQL query statement below
SELECT unique_id,name FROM
Employees as a LEFT JOIN
EmployeeUNI as b 
ON a.id=b.id;