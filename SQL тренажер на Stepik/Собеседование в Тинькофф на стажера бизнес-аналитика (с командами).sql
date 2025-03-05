# Исходные таблицы по изначальному условию

CREATE TABLE employee
(emp_id int, loc_id int, salary numeric(10,2), group_id int, birthday_dt date);
CREATE TABLE location
(loc_id int, loc_name varchar(100), pos varchar(10));

# Задание 1
Нужно найти всех сотрудников(emp_id),
кто работает в офисе "Водный"(loc_name),
при этом зарплата больше средней всех работников,
кто работает в офисе "ТЦР(loc_name)"

# Задание 2
Вывести кол-во сотрудников в каждой группе

# Задание 3
Вывести вторую минимальную премию в организации.

#1 решение первой задачи

SELECT emp_id 
FROM 
	employee INNER JOIN location
	ON employee.loc_id = location.loc_id
WHERE loc_name = 'Водный' AND 
	  salary > (
	  	SELECT AVG(salary) AS Average_Salary
	  	FROM 
	  		employee INNER JOIN location
	  		ON employee.loc_id = location.loc_id
	  	WHERE loc_name = 'ТЦР' 
	  	#средняя зарплата
	  );

#2 решение второй задачи

SELECT group_id AS Группа, COUNT(emp_id) AS Количество_сотрудников
FROM employee
GROUP BY group_id;

#3 На третью не хватило времени, потому что я тупил и долго писал чёт. Пропустили 
# и перешли к задачам на мат. логику