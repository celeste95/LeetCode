select Person.FirstName, Person.LastName, Address.City, Address.State
from Person 
LEFT JOIN Address
ON Address.PersonId=Person.PersonId