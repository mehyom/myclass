# 다음의 데이터베이스 파일(lahman2016.sqlite)을 불러오도록 한다
# 파일을 불러올 때는 파일의 directory를 잘 설정해주도록 한다.
# 현재 R session의 directory는 getwd()를 통해 알아낼 수 있다.
library("DBI")
library("RSQLite")
drv <- dbDriver("SQLite")
con <- dbConnect(drv, dbname = "C:\\Users\\FAMILY\\Desktop\\SQL 통계분석\\lahman2016.sqlite")

# con 데이터베이스가 가지고 있는 다양한 테이블의 이름을 출력
dbListTables(con)

# Batting, Pitching 테이블이 가지고 있는 속성을 출력
dbListFields(con, "Batting")
dbListFields(con, "Pitching")

# 데이터베이스 table을 data.frame으로 불러오기
batting <- dbReadTable(con, "Batting") 
class(batting) 
dim(batting)
names(batting)







## SELECT문
# SELECT columns
# FROM table
# WHERE condition
# GROUP BY columns
# HAVING condition
# ORDER BY column [ASC | DESC]
# LIMIT offset, count;


# Batting에서 playerID, yearID, AB, H, HR 5개 속성의 첫 10줄 값을 출력해보자.
dbGetQuery(conn = con, 
           statement = paste("SELECT playerID, yearID, AB, H, HR",
                             "FROM Batting",
                             "LIMIT 10"))
# 또는
dbGetQuery(conn = con, 
           statement = "SELECT playerID, yearID, AB, H, HR
         FROM Batting
          LIMIT 10")
# paste 함수를 사용하면 코드를 줄 맞춰서 정렬할 때 좋다.(가독성↑)
batting[1:10, c("playerID", "yearID", "AB", "H", "HR")] # 메모리 측면에서 비효율적이다.







## ORDER BY문
# ORDER BY 옵션은 튜플값들을 정렬할 때 사용한다.
# 오름차순이 기본값이고 DESC를 뒤에 붙여 내림차순으로 정렬할 수 있다.


# 연도별 홈런 수가 가장 많은 10명의 선수에 대한 결과를 뽑아보자.
dbGetQuery(con, paste("SELECT playerID, yearID, AB, H, HR",
                      "FROM Batting",
                      "ORDER BY HR DESC",
                      "LIMIT 10"))
# R 명령어를 이용해서도 위 명령어와 같은 작업을 수행할 수 있다.
batting[order(batting$HR,decreasing=T)[1:10], c("playerID", "yearID", "AB", "H", "HR")]


# 평균 홈런 횟수, 평균 안타(hit) 횟수를 계산해보자.
dbGetQuery(con, paste("SELECT AVG(HR), AVG(H)",
                      "FROM Batting"))
# R 명령어를 이용해서는 다음과 같이 계산할 수 있다.
print(c(mean(batting$HR, na.rm=TRUE),mean(batting$H, na.rm=TRUE)))






## GROUP BY 문

# playerID 별로 HR의 평균값을 살펴보자.
dbGetQuery(con, paste("SELECT playerID, AVG(HR)",
                      "FROM Batting",
                      "GROUP BY playerID",
                      "ORDER BY AVG(HR) DESC",
                      "LIMIT 10")) # GROUP BY와 ORDER BY의 순서를 바꾸면 오류가 나니 주의
# R 명령어를 이용해서는 다음과 같이 계산할 수 있다.
tmp = tapply(batting$HR, batting$playerID, mean, na.rm=T)
tmp[order(tmp, decreasing=T)[1:10]]







## AS 명령어
# SELECT문에 AS를 사용하여 출력하는 속성의 이름을을 바꿀 수 있다.

# 연도별로 평균 홈런수가 가장 많은 10년치 자료를 출력하자.
# 단, 연별로 avg(HR) 집계값을 avgHR로 바꾸어 출력해보자.
dbGetQuery(con, paste("SELECT yearID, AVG(HR) as avgHR",
                      "FROM Batting",
                      "GROUP BY yearID",
                      "ORDER BY avgHR DESC",
                      "LIMIT 10"))






## WHERE문의 활용
# WHERE 옵션은 특정 조건을 만족하는 튜플(행)을 선택할 때 사용한다.

# 연도별로 평균 홈런 개수가 많은 10개년도의 값을 출력해보자. 단, 1990년 이후만 고려한다.
dbGetQuery(con, paste("SELECT yearID, AVG(HR) as avgHR",
                      "FROM Batting",
                      "WHERE yearID >= 1990",
                      "GROUP BY yearID",
                      "ORDER BY avgHR DESC",
                      "LIMIT 10"))






## HAVING문의 활용
# HAVING문은 GROUP BY 문에 특정 조건을 부여하고 싶을 때 사용한다.
# (grouping 및 계산 이후에 수행됨)

# 1990년 이후에 연도별로 평균 홈런 개수가 많은 10개년도의 값을 출력해보자.
# 단, 평균 홈런의 수가 4개 이상인 해만 고려한다.
dbGetQuery(con, paste("SELECT yearID, AVG(HR) as avgHR",
                      "FROM Batting",
                      "WHERE yearID >= 1990",
                      "GROUP BY yearID",
                      "HAVING avgHR >= 4",
                      "ORDER BY avgHR DESC"))







## Join: 복수개의 테이블을 사용할 때
# SELECT문의 FROM 옵션에 join을 수행할 (복수의) 테이블을 입력할 수 있다.

# SELECT columns or computations
# FROM tabA JOIN tabB USING(key)
# WHERE condition
# GROUP BY columns
# HAVING condition
# ORDER BY column [ASC | DESC]
# LIMIT offset, count;

# SQLite: USING을 사용, FROM tabA JOIN tabB USING(key),
#         ON을 사용, FROM tabA JOIN tabB on tabA.keyA = tabB.keyB
# MySQL: ON을 사용, FROM tabA JOIN tabB ON keyA = keyB


## JOIN의 종류
# INNER JOIN (혹은 단순히 JOIN): 두 테이블의 공통된 행을 보존한다.
# LEFT OUTER JOIN (LEFT JOIN): 첫 번째(코드 상의 왼쪽) 테이블의 모든 행을 보존하고,
#       두 번째(코드 상의 오른쪽) 테이블에서는 첫 번째 테이블과 일치하는 행만 보존한다.
# RIGHT OUTER JOIN (RIGHT JOIN): 두 번째(코드 상의 오른쪽) 테이블의 모든 행을 보존하고,
#       첫 번째(코드 상의 왼쪽) 테이블에서는 두 번째 테이블과 일치하는 행만 보존한다.
# FULL OUTER JOIN (FULL JOIN): 두 테이블의 모든 행을 보존한다.

# 현재 RIGHT JOIN과 FULL JOIN은 RSQLite 패키지에서 제공되지 않는다.

# 평균 홈런 횟수가 가장 많은 10명의 평균 연봉이 궁금할 때
# 다음의 두 테이블을 이용하여 이를 알아볼 수 있다.
dbGetQuery(con, paste("SELECT yearID, teamID, lgID, playerID, HR",
                      "FROM Batting",
                      "ORDER BY playerID",
                      "LIMIT 15"))
dbGetQuery(con, paste("SELECT *",
                      "FROM Salaries",
                      "ORDER BY playerID",
                      "LIMIT 15"))

# yearID와 playerID를 기준으로 두 테이블을 join한다.
# Using과 On을 각각 사용해보자.
dbGetQuery(con, paste("SELECT yearID, playerID, salary, HR",
                      "FROM Batting JOIN Salaries USING(yearID, playerID)",
                      "ORDER BY playerID",
                      "LIMIT 15"))
dbGetQuery(con, paste("SELECT Batting.yearID, Batting.playerID, salary, HR",
                      "FROM Batting JOIN Salaries on Batting.yearID = Salaries.yearID 
                      AND Batting.playerID = Salaries.playerID",
                      "ORDER BY Batting.playerID",
                      "LIMIT 15"))
# join 후에 David Aardsma의 기록이 3개 삭제된 것에 유의한다.

# R에서 merge라는 base R 명령어를 사용할 수도 있다.
batting = dbReadTable(con, "Batting")
salaries = dbReadTable(con, "Salaries")
merged = merge(x=batting, y=salaries, by.x=c("yearID","playerID"),
               by.y=c("yearID","playerID"))
merged[order(merged$playerID)[1:15],
       c("yearID", "playerID", "salary", "HR")]
# 다시 원래 질문으로 돌아가서, 홈런을 잘 치는 선수들의 평균 연봉을 보도록 한다.
dbGetQuery(con, paste("SELECT playerID, AVG(HR), AVG(salary)",
                      "FROM Batting JOIN Salaries USING(yearID, playerID)",
                      "GROUP BY playerID",
                      "ORDER BY Avg(HR) DESC",
                      "LIMIT 15"))







## 데이터베이스 생성
employees <- data.frame(name = c("Alice","Bob","Carol","Dave","Eve","Frank"),
                        email  = c("alice@company.com", "bob@company.com",
                                   "carol@company.com", "dave@company.com",
                                   "eve@company.com",   "frank@comany.com"),
                        salary = c(52000, 40000, 30000, 33000, 44000, 37000),
                        dept = c("Accounting", "Accounting","Sales",
                                 "Accounting","Sales","Sales"))
phone <- data.frame(name  = c("Bob", "Carol", "Eve", "Frank"),
                    phone = c("010-555-1111", "010-555-2222", "010-555-3333", "010-555-4444"))
# 위의 두 데이터프레임을 con DB에 저장하자.
dbWriteTable(conn = con,         
             name = "employees", 
             value = employees,  
             overwrite = TRUE)
dbWriteTable(con, "phone", phone, overwrite = TRUE)
dbListTables(con)
# DB의 테이블을 R의 데이터 프레임 형태로 전환할 수도 있다.
employees_re = dbReadTable(con, "employees")
phone_re = dbReadTable(con, "phone")
print(employees_re)
print(phone_re)
# 테이블을 제거할 수도 있다.
dbExecute(con, "DROP table employees")
dbExecute(con, "DROP table phone")
dbListTables(con)
































library(tidyverse)
# R Studio에서 단축키 ctrl + shift + m (Windows)
# 하나의 입력 값을 파이프로 합성할 경우
# x %>% f %>% g %>% h
# h(g(f(x)))와 같이 해석한다.
# 요점: %>% 연산자는 '그리고 다음으로'라고 읽어낸다.

# exp(1)과 같은 계산은 파이프를 사용하여 1 %>% exp()로 수행할 수 있으며,
# log(exp(1))는 1 %>% exp() %>% log()로 수행한다.

# 입력 값이 여러 개인 함수는 다음과 같이 사용하며
# x %>% f(y) 
# f(x,y)로 해석한다.

# mtcars %>% head(4)   =>   head(mtcars, 4)

# x %>% f(y) 명령어는 dot 표기법을 이용하여 수행할 수도 있다.
# x %>% f(., y)
# x %>% f(y, .)
state_df <- data.frame(state.x77)
state.region %>% 
  tolower %>%
  tapply(state_df$Income, ., summary)

x <- "Ben really loves piping"
x %>% 
  strsplit(split = " ") %>%
  .[[1]] %>% # subsetting
  nchar() %>% 
  max()







## dplyr 명령어

# slice(): integer indexing을 통하여 행의 일부를 가져옴
# filter(): 논리 연산을 통해 행의 일부를 가져옴
# select(): 열의 일부를 가져옴
# pull(): 특정 열 하나를 가져옴
# arrange(): 특정 열을 기준으로 행을 정렬
# rename(): 열의 이름을 변경
# mutate(): 새로운 열 생성
# mutate_at(): 특정 열에 함수를 적용
# 요점: data.frame을 목적어로 생각하고 dplyr 함수를 동사로 생각하여
#       특정 대상에 함수를 적용한다고 생각하면 된다.

# slice(): 특정 번호의 행을 선택하고 싶을 때 slice()를 사용한다.
mtcars %>% slice(c(7,8,14:15))
mtcars[c(7,8,14:15),] # R

mtcars %>% 
  slice(-c(1:2,19:23)) %>% 
  nrow()
nrow(mtcars[-c(1:2,19:23),]) # R 

# filter(): 조건문을 사용하여 특정 조건을 만족하는 행을 뽑아낼 때는 filter()를 사용한다.
mtcars %>% 
  filter((mpg >= 14 & disp >= 200) | (drat <= 3)) %>% 
  head(2)
head(subset(mtcars, (mpg >= 14 & disp >= 200) | (drat <= 3)), 2) # R
head(mtcars[(mtcars$mpg >= 14 & mtcars$disp >= 200) | (mtcars$drat <= 3),], 2) # R

# select(): select()를 이용하여 특정 열을 뽑아낼 수 있다
mtcars %>% 
  select(cyl, disp, hp) %>% 
  head(2)
head(mtcars[, c("cyl", "disp", "hp")], 2) # R

# select()를 이용할 때 유용한 함수
mtcars %>% 
  select(starts_with("d")) %>% 
  head(2)
d_colnames <- grep(x = colnames(mtcars), pattern = "^d") # R
head(mtcars[, d_colnames], 2)
# etc
mtcars %>% select(ends_with('t')) %>% head(2)
mtcars %>% select(ends_with('yl')) %>% head(2)
mtcars %>% select(contains('ar')) %>% head(2)

# pull()
# pull을 사용하면 하나의 열을 선택하여 벡터 형태로 출력한다.
# 반면 select를 사용하여 하나의 열만 선택하면 열벡터 형태를 유지한다.
mtcars %>% pull(mpg)
mtcars %>% select(mpg)

# arrange(): 특정 열에 대해 내림,오름 차순으로 행을 정렬할 때 arrange()를 사용한다.
mtcars %>% 
  arrange(desc(disp)) %>% 
  select(mpg, disp, drat) %>%
  head(2)
drat_inds <- order(mtcars$disp, decreasing = TRUE) # R
head(mtcars[drat_inds, c("mpg", "disp", "drat")], 2)

mtcars %>% 
  arrange(desc(gear), desc(hp)) %>%
  select(gear, hp, everything()) %>%
  head(8) # 여러 열에 대하여

# mutate(): (여러 개의) 새로운 열을 생성 혹은 기존의 열을 수정할 때 mutate()를 사용한다.
mtcars <- mtcars %>% 
  mutate(hp_wt = hp/wt, 
         mpg_wt = mpg/wt) 
mtcars$hp_wt <- mtcars$hp/mtcars$wt # R
mtcars$mpg_wt <- mtcars$mpg/mtcars$wt
# 새로운 열 혹은 수정한 열을 가지고 새로운 data.frame을 생성할 수 있다.
mtcars <- mtcars %>% 
  mutate(hp_wt = 1) # update hp_wt to just the one value
mtcars %>% head(2)
mtcars$hp_wt <- 1# R
# 새로 정의된 변수는 같은 pipeline에서 바로 사용할 수 있다.
mtcars <- mtcars %>% 
  mutate(hp_wt_correct = hp/wt,
         hp_wt_cyl = hp_wt_correct/cyl) 
mtcars %>% head(2)
mtcars$hp_wt_correct <- mtcars$hp/mtcars$wt # R
mtcars$hp_wt_cyl <- mtcars$hp_wt_correct/mtcars$cyl

# mutate_at(): 함수를 열에 적용하고 싶을 때 mutate_at()을 사용한다.
mtcars <- mtcars %>% mutate(hp_wt = hp_wt_correct)
mtcars <- mtcars %>%
  mutate_at(c("hp_wt", "mpg_wt"), log) 
mtcars$hp_wt <- log(mtcars$hp_wt) # R
mtcars$mpg_wt <- log(mtcars$mpg_wt)

# rename(): 열의 이름을 변경할 때 rename()를 사용한다.
mtcars %>% 
  rename(hp_wt_log = hp_wt, mpg_wt_log = mpg_wt) %>%
  head(2)
colnames(mtcars)[colnames(mtcars) == "hp_wt"] <- "hp_wt_log" # R
colnames(mtcars)[colnames(mtcars) == "mpg_wt"] <- "mpg_wt_log"
head(mtcars, 2)
























## tidyr 명령어
# pivot_longer(): 'wide' data -> ;long' data
# pivot_wider(): 'long' data -> 'wide' data
# separate(): 특정 열을 여러 개의 열로 바꿈
# unite(): 여러 개의 열을 하나의 열로 합침

# pivot_longer(): 'wide' data를 'long' data로 바꾼다.
cases = read.csv("https://raw.githubusercontent.com/rstudio/EDAWR/master/data-raw/cases.csv")
cases %>% head(3)
cases %>% 
  pivot_longer(names_to = "year", values_to = "n", cols = 2:4) %>% 
  head(5)
# 여기서 2:4번째 열을 year 열로 변환
# 2:4번째 열에 있던 값들이 n이라는 열에 입력
# tidyr에서 transpose를 취하는 아주 번거로운 작업들을 간단하게 수행
cases %>% 
  pivot_longer(names_to = "year", values_to = "n", -country) %>% 
  head(5)

# pivot_wider(): 'long' data를 'wide' data로 바꾼다.
pollution = read.csv("https://raw.githubusercontent.com/rstudio/EDAWR/master/data-raw/pollution.csv")
pollution %>% head(5)
pollution %>% 
  pivot_wider(names_from = "size", 
              values_from = "amount")
# size 변수를 이용해서 wide 형식으로 transpose
# 각 size마다 값을 표로 정리
# tidyr은 이러한 번거로운 작업을 손쉽게 수행
# pivot_wider()와 pivot_longer()는 서로 반대되는 작업을 수행

# wide/long data의 용도?
# ggplot2 그림을 만들 때 (pivot_longer)
# 보기 좋은 table을 만들 때 (pivot_wider)
ggplot2::ggplot(data = cases %>% 
                  pivot_longer(names_to = "year", values_to = "n", cols = 2:4), 
                mapping = aes(x = year, y = n, color = country)) +
  geom_point()

# separate(): 하나의 열을 여러개의 열로 변경할 수 있다.
storms = read.csv("https://raw.githubusercontent.com/rstudio/EDAWR/master/data-raw/storms.csv")
storms %>% head(3)
storms2 <- storms %>% 
  separate(date, c("y", "m", "d"))

# unite(): 여러개의 열을 하나의 열로 통합할 수 있다.
storms2 %>%
  unite(date, y, m, d, sep = "-")
# unite()와 separate()는 서로 반대의 기능을 수행한다.







## dplyr: group_by() 와 summarize() 함수
# e.g. select는 SELECT문에, filter는 WHERE문에, arrange는 ORDER BY에 대응된다

# group_by(): 특정 행(들)을 기준으로 행의 그룹을 설정할 수 있다.
mtcars %>% 
  group_by(cyl) %>%
  head(4)
mtcars %>% 
  group_by(cyl) %>%
  head(4) %>% class
# 출력했을 때 Groups: ... 부분에 그룹 정보로 사용된 열을 알려준다.
# group_by는 자료 자체를 바꿔주지는 않지만 내부적으로 그룹 정보를 담고 있다.
# 다음에 등장하는 summarize 함수와 함께 사용하여 진가를 발휘한다.

# summarize(): 함수(들)을 행에 적용할 수 있다.
# 이때 그룹화 된 행들이 있다면 그룹마다 함수 결과 값이 계산된다.
mtcars %>% 
  summarize(mpg = mean(mpg),
            hp = mean(hp)) # Ungrouped
mtcars %>%
  group_by(cyl) %>%
  summarize(mpg = mean(mpg),
            hp = mean(hp)) # # Grouped by number of cylinders
mtcars %>%
  group_by(cyl) %>%
  summarize(mpg_mean = mean(mpg),
            mpg_max = max(mpg),
            hp_mean = mean(hp),
            hp_max = max(hp))

# ungroup(): 그룹 정보를 없앨 수 있다.
mtcars %>%
  group_by(cyl) %>%
  ungroup() %>%
  summarize(hp = mean(hp),
            mpg = mean(mpg))
# 실제로 우리가 사용하는 함수의 결과들은 더 다양한 형태가 많다.
mtcars %>% 
  pull(hp) %>% tapply(INDEX = mtcars$cyl, FUN = summary)





## dplyr: left_join()과 inner_join()
has_kids_tab1 <- data.frame(name = c("Robert Downey, Jr", "Scarlett Johansson", "Chris Hemsworth"), 
                            children = c(3, 1, 3),
                            stringsAsFactors = FALSE)
americans_tab2 <- data.frame(name = c("Chris Evans", "Robert Downey, Jr", "Scarlett Johansson"),
                             age = c(38, 54, 34),
                             stringsAsFactors = FALSE)
has_kids_tab1
americans_tab2

# inner_join(): tab1과 tab2를 (배우) 이름을 기준으로 합병하되
#               두 테이블에 모두 존재하는 배우만 가져오고 싶은 경우.
inner_join(x = has_kids_tab1, y = americans_tab2, by = "name")
# left_join(): tab1과 tab2를 (배우) 이름을 기준으로 합병하되
#              tab1 테이블에 존재하는 배우는 모두 가져오고 싶은 경우.
left_join(x = has_kids_tab1, y = americans_tab2, by = c("name" = "name"))
# right_join(): tab1과 tab2를 (배우) 이름을 기준으로 합병하되
#               tab2 테이블에 존재하는 배우는 모두 가져오고 싶은 경우.
right_join(x = has_kids_tab1, y = americans_tab2, by = "name")
# full_join(): tab1과 tab2를 (배우) 이름을 기준으로 합병하되
#              tab1, tab2 테이블에 존재하는 배우를 모두 가져오고 싶은 경우.
full_join(x = has_kids_tab1, y = americans_tab2, by = "name")

# 기타 특징
my_peeps <-
  data.frame(
    pol = factor(sample(c("R", "D"), 10, replace = T)),
    gender = factor(sample(c("F", "M"), 10, replace = T)),
    state = factor(sample(c("AZ", "PA"), 10, replace = T)),
    IQ = round(rnorm(
      n = 10, mean = 100, sd = 10
    ))
  )

politics <- data.frame(
  senator = c("Kyrsten Sinema", "Martha McSally",
              "Pat Toomey", "Boy Casey Jr."),
  pol = c("D", "R", "R", "D"),
  gender = c("F", "F", "M", "M"),
  STATE = c("AZ", "AZ", "PA", "PA")
)

my_peeps %T>% print() %>% dim()
politics %T>% print() %>% dim()

# %T>%는 Tee 파이프 연산자라고 부르며, 연산의 결과물을 출력하거나
# Plot을 얻고 싶으면서 동시에 결과물을 리턴하고 싶을 때 사용한다.
# 여기서 %T>%는 my_peeps를 print() 함수에 입력한 결과를 부수적으로 출력하고,
# 이어서 my_peeps를 나머지 파이프라인(여기에서는 dim())에 적용한다.

my_peeps %>% 
  left_join(politics,
            by = c("state" = "STATE", "pol" = "pol")) %>% head(6)

# 여러 열을 기준으로 join할 수 있다.
# by로 명시되지 않은 gender는 gender.x, gender.y로 나타나며
# 각각 첫 번째 (x), 두 번째 (y) 테이블에서 유래한 것을 의미한다.























## Part I. Plot basics: ggplot
#ggplot: 명령어의 시작으로서, 자료와 변수를 입력할 수 있다.

# geom: 'geometric objects', 어떤 종류의 그래프를 그릴 것인지 명시한다.
# geom_으로 시작하며 그래프의 종류가 뒤에 붙는다.

# geom_point(): 산점도
# geom_bar(): barplot
# geom_density(): 밀도 함수
# geom_line(): 선 연결
# 기타 많은 함수들(참고)
# aes: aesthetics (직역: 미학), 그래프의 미적인 부분을 명시한다.
# 변수를 입력할 경우 변수의 값에 따라서 아래 요소를 표시한다.

# shape: 점의 모양
# alpha: 투명도
# color: (선) 색상
# fill: (내부) 색상
# linetype: 선 종류





## gapminder 자료 분석
library("gapminder")
data(gapminder)

# 산점도(scatter plot)
library("ggplot2")
ggplot(gapminder, aes(y = lifeExp, x = gdpPercap)) + 
  geom_point()

# ggplot의 기초: 구조
ggplot(data = gapminder, aes(y = lifeExp, x = gdpPercap)) + 
  geom_point()
## equivalent
p <- ggplot(data = gapminder, aes(y = lifeExp, x = gdpPercap))
p + geom_point()
# 전역(global) 구조를 ggplot 함수에 입력한다.
# data: 사용할 자료 입력
# mapping: aes를 사용하여 변수를 입력
# 원하는 형태의 그래프를 그려줄 층(layer)을 추가한다.
# 통계 모형을 덧그릴 수도 있고 패널을 나눌 수도 있다.

# ggplot의 기초: 크기
ggplot(gapminder, aes(y = lifeExp, x = gdpPercap)) + 
  geom_point(size = .1)

# ggplot의 기초: 색상
ggplot(gapminder, aes(y = lifeExp, x = gdpPercap, color = continent)) + 
  geom_point(size = .1)

# ggplot의 기초: 척도(scale)
ggplot(gapminder, aes(y = lifeExp, x = gdpPercap, color = continent)) + 
  geom_point(size = .1) + 
  scale_x_log10() + scale_y_log10()

# (현재까지) ggplot의 구성 요소들
# data: 사용할 자료 명시
# aes: 미적 특성(position, length, color, symbol…)
# geom_: 그래프 형태 (point, line, bar…)
# scale: 척도 변경 (축의 범위, log 척도, 색/모양/… 변경)





## Part II. 그래프 예제

# ggplot: boxplot
ggplot(gapminder, aes(y = lifeExp, x = continent)) + 
  geom_boxplot() 

# ggplot: histogram (color vs fill)
ggplot(gapminder, aes(x = lifeExp)) + 
  geom_histogram(color = "black", fill = "blue") 

# ggplot: histogram (fill mapping)
ggplot(gapminder, aes(x = lifeExp)) + 
  geom_histogram(aes(fill = continent), color = "black")

# ggplot: line plots
ggplot(gapminder[gapminder$country %in% c("United States", "Canada", 
                                          "Mexico", "United Kingdom", 
                                          "Ireland",
                                          "Saudi Arabia"),], 
       aes(x = year, y = gdpPercap)) + 
  geom_line(aes(color = country)) 

# 이산형 자료 시각화
library(tidyverse)
titanic <- read_csv("https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv") %>%
  mutate(Pclass = factor(Pclass))

# ggplot intro: barchart
ggplot(data = titanic, aes(fill = Pclass)) + 
  geom_bar(aes(x = Pclass)) 
# 기본값: + coord_cartesian(), Cartesian coordinate system에 기반하고 있다.

# ggplot intro: spine chart
# 'Spine chart'(혹은 stacked bar plot)는 x값을 공통으로 하는 bar plot이다.
ggplot(data = titanic, aes(fill = Pclass)) + 
  geom_bar(aes(x = factor(1))) 

# ggplot intro: pie chart
# “Pie chart”: spine chart를 극좌표계(polar coordinates)로 그린 경우다.
# 갯수(count)는 높이(height)가 아니고 부채꼴의 각(angle)으로 표현된다.
ggplot(data = titanic, aes(fill = Pclass)) + 
  geom_bar(aes(x = factor(1)), width = 1) + coord_polar(theta = "y")






## Part III. 세련된 그래픽
# Facets: Facet은 (보통 이산형) 변수의 값에 따라 하위 plot을 여러 개 생성해준다.
p <- ggplot(titanic, aes(x = Pclass, fill = factor(Survived))) + 
  geom_bar()
p + facet_wrap(~ Sex)

# 덧그리기(stacking), 여러 이미지 그리기
a <- ggplot(gapminder,aes(x = lifeExp, y = ..density..)) + geom_histogram() 
a + geom_density()

# 여러 그림을 하나의 창에 표현
library(gridExtra)
a <- ggplot(gapminder,aes(x = lifeExp)) + 
  geom_histogram()
b <- ggplot(gapminder,aes(x = lifeExp)) + 
  geom_density()
grid.arrange(a, b, nrow=1, ncol=2) 

# Title
ggplot(gapminder, aes(y = lifeExp, x = gdpPercap, color = continent, shape = continent)) + 
  geom_point() + 
  scale_x_log10() + scale_y_log10() +
  labs(x = "GDP per Capita (log)",
       y = "Average Life Expectancy (log)",
       title = "National GDP per Capita vs Life Expectancy",
       shape='Continent shape', color = "Continent color")







## Part IV. 부록
# 전역(Global) vs. 국부(local)
# Global: ggplot() 내에서 자료와 aes를 입력한다.
#         처음으로 입력한 값이 다른 함수(가령 geom_)에도 유효하게 적용된다.
# Local: ggplot() 외 이후 함수에서 자료와 aes를 입력한다.
#        해당 함수에서만 유효하게 사용된다.

g_vis <- ggplot(gapminder, aes(y = lifeExp, x = gdpPercap)) + # global
  geom_point(color = "blue")  
l_vis <- ggplot() + 
  geom_point(data = gapminder, aes(y = lifeExp, x = gdpPercap)) # local
# ^ notice the need to write data = gapminder
g_vis2 <- g_vis + geom_line() 
l_vis2 <- l_vis + geom_line()  # geom_line doesn't do anything here

grid.arrange(g_vis, l_vis, 
             g_vis2, l_vis2, nrow = 2)

# local mapping을 통해 여러 자료를 이용해 그림을 그릴 수도 있다
gapminder2 <- gapminder
gapminder2$lifeExp <- 2 * gapminder2$lifeExp

g_vis <- ggplot(gapminder, aes(y = lifeExp, x = gdpPercap)) + # global
  geom_point(color = "blue") + scale_x_log10()
g_vis_plus_another <- g_vis + 
  geom_point(data = gapminder2, aes(y = lifeExp, x = gdpPercap), color = "red")

grid.arrange(g_vis, g_vis_plus_another, nrow = 1)
