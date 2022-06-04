# Write your MySQL query statement below
SELECT emp.name as Employee
FROM Employee emp, Employee mag
WHERE emp.managerId = mag.id
AND emp.salary > mag.salary 
;