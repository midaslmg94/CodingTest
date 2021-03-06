## MySQL



### IF

- `select`, `where` 절 에서 사용가능

  ```mysql
  SELECT IF(10 > 5, '크다', '작다') AS result;
  
  ```



### Order By

- Order by 뒤에 우선순위가 있는 열을 순서대로 적는다.



### LIKE

- `where` 절과 함께 특정 패턴을 검색할 때 사용

  ```mysql
  SELECT *
  FROM Student
  WHERE Student_ID like 'a%';
  
  LIKE 'a%' // a로 시작되는 모든 것
  LIKE 'a_%_%' // a로 시작되고 최소 3이상의 길이를 가진 것
  LIKE '_a%' // 두번째 자리에 a가 들어가는 모든 것
  
  ```

  

### IN

- `where`절 내 여러 값을 설정하고자 할 때 사용

- 연산 속도가 상대적으로 빠름

- or 연산과 유사한 효과

  ```
  select *
  from Customers
  where country in ('UK', 'Korea') // Customers 중 country가 UK이거나 KOREA인 것 다 뽑기
  ```

  

- 문제 : 동물 보호소에 들어온 동물 중 이름이 `Lucy, Ella, Pickle, Rogan, Sabrina, Mitty`인 동물의 아이디와 이름, 성별 및 중성화 여부를 조회하는 SQL 문을 작성해주세요.

  ```mysql
  select ANIMAL_ID, NAME, SEX_UPON_INTAKE
  from ANIMAL_INS ani
  where NAME in ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty');
  ```

  

### Between

- `where` 절 내 검색 조건으로 범위를 지정하고자 할 때 사용 
- `between`과 `and` 사이에 들어 가는 값은  `~이상 ~ 이하` 이다

```mysql
select *
from products
where price between 10 and 20;

select *
from products
where price not between 10 and 20;

select *
from products
where (price between 10 and 20) and not  id in(2,3); // 이렇게 쓸 수도 있다
```







### Null의 처리

예를 들어 `ANIMAL_INS` 테이블이 다음과 같다면

| ANIMAL_ID | ANIMAL_TYPE | DATETIME            | INTAKE_CONDITION | NAME  | SEX_UPON_INTAKE |
| --------- | ----------- | ------------------- | ---------------- | ----- | --------------- |
| A350276   | Cat         | 2017-08-13 13:50:00 | Normal           | Jewel | Spayed Female   |
| A350375   | Cat         | 2017-03-06 15:01:00 | Normal           | Meo   | Neutered Male   |
| A368930   | Dog         | 2014-06-08 13:20:00 | Normal           | NULL  | Spayed Female   |

마지막 줄의 개는 이름이 없기 때문에, 이 개의 이름은 No name으로 표시합니다. 따라서 SQL문을 실행하면 다음과 같이 나와야 합니다.

| ANIMAL_TYPE | NAME    | SEX_UPON_INTAKE |
| ----------- | ------- | --------------- |
| Cat         | Jewel   | Spayed Female   |
| Cat         | Meo     | Neutered Male   |
| Dog         | No name | Spayed Female   |

`Ifnull` 사용

> SELECT ANIMAL_TYPE, IFNULL(NAME,'No name') AS NAME, SEX_UPON_INTAKE
> FROM ANIMAL_INS



`coalesce` 사용

> SELECT ANIMAL_TYPE, coalesce(NAME,'No name') AS NAME, SEX_UPON_INTAKE
> FROM ANIMAL_INS



coalesce는 정의된 열 중 null이 아닌 첫번째 값을 화면에 출력. 

coalesce('a', 'b')인 경우, 가장 왼쪽이 null이 아닌 'a'이다. 그러므로 a가 출력이 된다.

coalesce(null, 'b', 'c')인 경우, 'b'가 출력된다.



### Case 문

> CASE    
>
> ​		 WHEN 조건1 THEN '조건1 반환값'   
>
> ​		 WHEN 조건2 THEN '조건2 반환값'   
>
> ​		 ELSE '충족되는 조건 없을때 반환값'
>
> END

생긴건 swtich .. case 와 비슷하게 생겼다. WHEN .. THEN은 쌍으로 같이다녀야하고 조건을 여러개 추가 할 수 있다.  

**SELECT, WHERE, ORDER BY** 절에서 사용 가능하고 보통 SELECT 절에서 많이 쓰인다.

ELSE를 생략하면 결과 값이 NULL이 나오므로 주의

```mysql
SELECT 
	seq, 
	CASE
		WHEN (u.seq BETWEEN 1 AND 3) THEN 
            CASE 
                WHEN (u.enabled IS TRUE) THEN 'A+'
                ELSE 'A0'
            END 
		WHEN (u.seq BETWEEN 4 AND 6) THEN
            CASE 
                WHEN (u.enabled IS TRUE) THEN 'B+'
                ELSE 'B0'
            END
        ELSE 'C+'
	END AS case_result
FROM `user` u
```







### Limit 함수

```mysql
// 조건식이 있는 경우
SELECT 열명 
FROM 테이블명 
WHERE 조건식 
LIMIT 행수     

// 조건식이 없는 경우
SELECT 열명
FROM 테이블명
LIMIT 행수                  


// 지정한 숫자 개수 리턴
SELECT *
FROM
LIMIT 0,3; // 0번부터 3개
```



### Group By

- 집계함수와 함께 사용 되어, 결과를 지정한 칼럼에 따라 그룹으로 묶고자 할 때 사용

  ```mysql
  select count(id)
  from customers
  group by country // 각 도시에 사는 사람이 몇명인지
  ```

  



### MIN(), MAX(), COUNT(), AVG(), SUM()

- 집계함수

- `select` 에서 사용

  - `count` : `null`은 숫자로 세지 않는다.

  ```mysql
  select count(id) from products;
  select avg(price) from products;
  select sum(price) from products;
  ```

- 문제 : 평균 잔고(balance) 가 700이상인 지점의 이름과 평균 잔고를 구하라

  ```mysql
  select branch_name, avg(balance)
  from account
  group by branch_name 
  having avg(balance) >= 700;
  ```





### Union

- `select`의 칼럼 리스트를 기준으로 두 개 이상의 질의 결과를 하나의 테이블로 합치고자 할 때 사용
- 기본적으로 중복값을 제거한다.
- 중복값을 포함하고 싶은 경우 `union all`을 사용한다.

```mysql
select *
from customers
union
select city from orders
order by city;
```







### Join

![image-20201023235348062](C:\Users\midas\AppData\Roaming\Typora\typora-user-images\image-20201023235348062.png)

컬럼 구조

```
test1 
1
2
3
*********
test2
3
4
5
```



**INNER JOIN** : 교집합

```mysql
select test1.number 
from test1 join test2 on test1.number = test2.number;
```

- 결과 : 3

- test1 과 test2 의 number 컬럼을 서로 비교하여 중첩되는 값이 존재하면 test1.number 컬럼의 중첩 값만 출력한다.

- 동일 테이블의 조인 결과를 구할 때도 쓴다.

  >  우유와 요거트를 동시에 구입한 장바구니가 있는지 알아보려 합니다. 우유와 요거트를 동시에 구입한 장바구니의 아이디를 조회하는 SQL 문을 작성해주세요. 이때 결과는 장바구니의 아이디 순으로 나와야 합니다.

  ```mysql
  select distinct c.cart_id
  from cart_products c inner join cart_products p on(c.cart_id=p.cart_id)
  where (c.name='우유' and p.name='요거트') or (c.name='요거트'and p.name='우유')
  order by c.cart_id;
  ```

  



**LEFT JOIN** : 왼쪽 기준

```mysql
select test1.number 
from test1 left join test2 on test1.number = test2.number;
```

- 결과 : 3 2 1

- test1(왼) 과 test2(오) 의 number 컬럼을 서로 비교하여 중첩되는 값이 존재하면 왼쪽 테이블(test1)의 number 컬럼의 값을 출력한다.



**RIGHT JOIN** : 오른쪽 기준

```mysql
① test1.number 컬럼을 출력하는 경우
select test1.number 
from test1 right join test2 on test1.number = test2.number;

② test2.number 컬럼을 출력하는 경우
select test2.number 
from test1 right join test2 on test1.number = test2.number;
```

\- 결과1 : 3 null null

\- 결과2 : 3 4 5

\- left join 과 마찬가지로 중첩되는 값을 기준으로 오른쪽 테이블의 number 컬럼 값을 출력한다.



**OUTER JOIN** : 매칭되는 값이 없어도 출력

```
select test1.*, test2.number 
from test1 
left outer join test2 
on test1.number = test2.number;
```

\- 결과 : 3 c 3 / 2 b null / 1 a null ( 3line )

\- 조건에 부합하지 않는 test2.number (test1.number 가 1, 2 일때 해당 테이블의 값은 null 이지만 null로 출력되게끔 join됨 )



\* OUTER JOIN 에도 LEFT, RIGHT, FULL 가 있는데 이는 INNER JOIN과 마찬가지로 왼쪽, 오른쪽 기준 매칭되는 값이 없어도 모두 출력함

