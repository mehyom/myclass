use world;


# 1. city 테이블을 이용해 다음 질문에 답하는 SQL 문을 작성하시오. (각 5점)

# 1-(a) ID가 5인 도시의 인구수(Population)를 구하시오.
SELECT Population
FROM city
WHERE id=5;

# 1-(b) 인구수(Population)가 150만 이상 160만 이하인 도시 이름과 각 도시의 인구수를 구하시오 (인구수 별로 내림차순하시오.).
SELECT Name, Population
FROM city
WHERE Population >= 150000 and Population <= 160000
ORDER BY Population DESC;

# 1-(c) 국가 코드(CountryCode)가 ARM인 도시의 개수와 도시들의 총 인구수를 구하시오.
SELECT Count(*), SUM(Population)
FROM city
WHERE CountryCode='ARM';

# 1-(d) 도시 이름(Name)이 Q로 시작하는 도시를 가지고 있는 국가의 수(즉, CountryCode의 가지수)를 구하시오.
SELECT Count(*)
FROM city
WHERE Name LIKE 'Q%';

# 1-(e) 인구수 백만명 이상의 도시가 10개 이상인 국가들의 국가 코드를 구하시오.
SELECT CountryCode
FROM city
WHERE Population >= 1000000
GROUP BY CountryCode
HAVING Count(*) >= 10;


# 2. country 테이블을 이용해 다음 질문에 답하는 SQL 문을 작성하시오. (각 5점)

# 2-(a) 한국(South Korea)에 대한 전체 정보를 구하시오.
SELECT *
FROM country
WHERE Name = 'South Korea';

# 2-(b) 아르헨티나(Argentina)의 GNP와 인구수(Population)를 구하시오.
SELECT GNP, Population
FROM country
WHERE Name = 'Argentina';

# 2-(c) Asia 대륙(Continent)에 속하면서 인구수가 1억명이 넘는 국가의 이름과 GNP를 구하시오.
SELECT Name, GNP
FROM country
WHERE Continent = 'Asia' and Population >= 100000000;

# 2-(d) 대륙별로 한국의 독립연도(IndepYear) 이후에 독립한 국가의 개수를 구하시오.
SELECT Count(*)
FROM country
WHERE IndepYear > (SELECT IndepYear FROM country WHERE Name = 'South Korea');


# 3. countrylanguage 테이블을 이용해 다음 질문에 답하는 SQL 문을 작성하시오. (각 5점)

# 3-(a) 한국어(Korean)를 공식 언어로 사용 사용(IsOfficial=T)하는 국가의 전체 정보를 구하시오.
SELECT *
FROM countrylanguage
WHERE Language = 'Korean' and IsOfficial = 'T';

# 3-(b) 영어(English)를 공식 언어로 사용하는 국가들의 영어 사용 비율(Percentage)의 최소값, 최대값 및 평균값을 구하시오.
SELECT MIN(Percentage) AS Minimum, MAX(Percentage) AS Maximum, AVG(Percentage) AS Average
FROM countrylanguage
WHERE Language = 'English' and IsOfficial = 'T';

# 3-(c) 영어, 스페인어(Spanish)를 모두 사용하지 않는 국가들의 개수를 구하시오.
SELECT Count(*)
FROM countrylanguage
WHERE Language NOT IN ('English', 'Spanish');

# 3-(d) 국가코드가 IRN인 국가가 사용하는 언어 종류보다 많은 종류의 언어를 사용하는 국가들의 국가코드를 구하시오.
SELECT CountryCode
FROM countrylanguage
GROUP BY CountryCode
HAVING Count(Language) > (SELECT Count(Language) FROM countrylanguage WHERE CountryCode = 'IRN');


# 4. 두 개 이상의 테이블을 조인하여 다음 질문에 답하는 SQL 문을 작성하시오. (각 5점)

# 4-(a) 10개보다 많은 언어를 사용하는 국가의 이름을 구하시오.
SELECT Name
FROM country, countrylanguage
WHERE country.Code = countrylanguage.CountryCode
GROUP BY CountryCode
HAVING Count(DISTINCT Language) > 10;

# 4-(b) 9백만 이상의 도시를 가지고 있는 국가의 이름.
SELECT DISTINCT Country.Name
FROM country, city
WHERE country.Code = city.CountryCode and city.Population >= 9000000;

# 4-(c) 한국의 도시 중 인구수가 백만명이 넘는 도시를 구하시오.
SELECT DISTINCT city.Name
FROM country, city
WHERE (SELECT Code FROM country WHERE Name = 'South Korea') = city.CountryCode and city.Population >= 1000000;

# 4-(d) 대륙별로 영어 사용 비율이 90% 이상인 국가들의 수를 구하시오.
SELECT country.Continent, Count(DISTINCT country.Code) AS Count
FROM country, countrylanguage
WHERE country.Code = countrylanguage.CountryCode and countrylanguage.Language = 'English' and countrylanguage.Percentage >= 90
GROUP BY country.Continent;

# 4-(e) Europe 내 국가 중 영어 사용 비율이 North America 내 국가들의 평균 영어 사용 비율보다 높은 국가들을 구하시오.
SELECT DISTINCT country.Name
FROM country, countrylanguage
WHERE country.Code = countrylanguage.CountryCode
	and country.Continent = 'Europe'
	and countrylanguage.Language = 'English'
    and countrylanguage.Percentage > 
		(SELECT AVG(countrylanguage.Percentage)
		FROM country, countrylanguage 
        WHERE country.Code = countrylanguage.CountryCode 
			and countrylanguage.Language = 'English'
            and country.Continent = 'North America');
