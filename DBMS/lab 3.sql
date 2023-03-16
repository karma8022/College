-- use lab;
-- create table dept (
-- deptno int,
-- dname char(100),
-- loc varchar(100));
-- insert into dept
-- values (40,'Operations','Boston');

-- SET 1

-- SELECT COUNT(empno) as num_employees, AVG(sal) as avg_salary 
-- FROM emp 
-- WHERE deptno = 20;

-- SELECT ename,sal,(sal*0.1) as pf
-- FROM emp;

-- SELECT * FROM emp ORDER BY sal;

-- SELECT ename,hiredate from emp ORDER BY hiredate

-- SELECT ename,sal,(sal *0.1) as pf,(sal *0.5) as hra,(sal*0.3) as da from emp ORDER BY hra+da+pf-- 

-- SELECT deptno, COUNT(empno) as num_employees 
-- FROM emp
-- GROUP BY deptno;

-- SET SQL_SAFE_UPDATES = 0;
-- UPDATE emp
-- SET sal = sal * 1.1 
-- WHERE job = 'Salesman';

-- SELECT SUM(sal) as total_salary, 
--        MAX(sal) as max_salary, 
--        MIN(sal) as min_salary, 
--        AVG(sal) as avg_salary 
-- FROM emp
-- WHERE deptno = 20;

-- SELECT * 
-- FROM emp 
-- WHERE ename LIKE '__i%';

SELECT ename, MAX(sal)
FROM emp 
WHERE job='Salesman';














