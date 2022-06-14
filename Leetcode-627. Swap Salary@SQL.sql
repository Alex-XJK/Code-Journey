# Solution I: MySQL [AC] 263 ms

# Write your MySQL query statement below
UPDATE Salary 
SET sex = IF(sex = 'm', 'f', 'm')
;


# Solution II: MySQL [AC] 411 ms

# Write your MySQL query statement below
UPDATE Salary
SET sex = (
    CASE WHEN sex = 'm'
    THEN 'f'
    ELSE 'm'
    END
);