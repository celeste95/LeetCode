select Name as Customers
from Customers
left join Orders 
on Customers.Id=Orders.CustomerId
where Orders.CustomerId is null

--example
select Name Customers from Customers where id not in (select CustomerId from Orders)