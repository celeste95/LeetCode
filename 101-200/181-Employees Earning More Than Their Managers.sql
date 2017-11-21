--Write your MySQL query statement below
--my solution
select Employee1.name as Employee
from Employee as Employee1
join Employee as Employee2
on Employee1.ManagerId=Employee2.Id
where Employee1.Salary > Employee2.Salary

-- example solution
select name as Employee from employee a
inner join
(select distinct id, salary as mana_salary from employee) b
on a.managerID=b.id
where salary > mana_salary