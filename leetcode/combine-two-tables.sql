# Write your MySQL query statement below
select Person.firstName, Person.lastName, Address.city, Address.state from Person left join Address on Person.personId = Address.personId;