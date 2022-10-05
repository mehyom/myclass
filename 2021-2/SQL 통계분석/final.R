################################## 1 ###
library("DBI")
library("RSQLite")
drv <- dbDriver("SQLite")
con <- dbConnect(drv, dbname = "C:\\Users\\FAMILY\\Desktop\\기말고사\\madang.sqlite")


# 1-(a)
dbGetQuery(con, paste("SELECT bookname, price",
                      "FROM book",
                      "WHERE price >= 10000 AND price <= 15000"))

# 1-(b)
dbGetQuery(con, paste("SELECT bookname, price, publisher",
                      "FROM book",
                      "ORDER BY price DESC, publisher"))

# 1-(c)
dbGetQuery(con, paste("SELECT custid, AVG(saleprice)",
                      "FROM orders",
                      "GROUP BY custid",
                      "HAVING AVG(saleprice) >= 10000"))

# 1-(d)
dbGetQuery(con, paste("SELECT book.bookname, book.price-orders.saleprice AS discount",
                      "FROM orders JOIN book on orders.bookid = book.bookid"))

# 1-(e)
dbGetQuery(con, paste("SELECT customer.name, MAX(saleprice)",
                      "FROM orders join customer on orders.custid = customer.custid",
                      "GROUP BY orders.custid"))




################################## 2 ###
library(tidyverse)
book = dbReadTable(con, "book")
customer = dbReadTable(con, "customer")
orders = dbReadTable(con, "orders")


# 2-(a)
book %>% filter(price >= 10000 & price <= 15000) %>% select(bookname, price) %>% print()

# 2-(b)
book %>% arrange(desc(price), publisher) %>% select(bookname, price, publisher) %>% print()

# 2-(c)
orders %>% group_by(custid) %>% summarize(meanOfSaleprice = mean(saleprice)) %>% 
  filter(meanOfSaleprice >= 10000) %>% print()

# 2-(d) 
orders %>% inner_join(book, by = c("bookid" = "bookid", "bookname" = "bookname")) %>% 
  summarize(bookname = bookname, discount = price-saleprice) %>% print()

# 2-(e)
orders %>% inner_join(customer, by = "custid") %>% group_by(name) %>%
  summarize(maxOfSaleprice = max(saleprice)) %>% print()

# 2-(f)
orders %>% inner_join(customer, by = "custid") %>% 
  summarize(name=name, bookname=bookname) %>% print()

# 2-(g) 
orders %>% inner_join(book, by = "bookid") %>%
  inner_join(customer, by = "custid") %>% select(name, price, saleprice) %>%
  mutate(averageDiscountRate = (price-saleprice)/price*100) %>%
  group_by(name) %>% summarize(averageDiscountRate = mean(averageDiscountRate)) %>%
  filter(averageDiscountRate > 5) %>% print()




################################## 3 ###
library("ggplot2")
library(gridExtra)
  
  
# 3-(a)
ggplot(mtcars, aes(y = mpg, x = hp, color = factor(vs))) + geom_point(size = .8) + scale_x_log10()

# 3-(b) 
ggplot(mtcars, aes(x=hp, fill=factor(vs))) + geom_histogram(position = "dodge", binwidth = 30) 

# 3-(c)
a <- ggplot(data = mtcars, aes(fill = factor(cyl))) + geom_bar(aes(x = cyl))
b <- ggplot(data = mtcars, aes(fill = factor(cyl))) + geom_bar(aes(x = factor(1))) 
c <- ggplot(data = mtcars, aes(fill = factor(cyl))) + geom_bar(aes(x = factor(1))) + coord_polar(theta = "y")
grid.arrange(a, b, c, nrow=1, ncol=3)
