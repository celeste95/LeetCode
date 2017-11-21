select distinct a.Email as Email
from Person as a
inner join Person as b
on a.Email=b.Email and a.Id<>b.Id

Select Email from Person group by Email having count(email) > 1;