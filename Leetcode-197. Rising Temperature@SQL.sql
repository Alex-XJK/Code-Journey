# Write your MySQL query statement below
SELECT cur.id
FROM Weather cur
LEFT JOIN Weather pre
ON DATEDIFF(cur.recordDate, pre.recordDate) = 1
WHERE cur.temperature > pre.temperature
;