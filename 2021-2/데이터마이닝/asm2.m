## 데이터마이닝 과제2
## 20190917 통계학과 신효민

# 1-(1) bar chart
# 1-(2) mean
# 1-(3)
clc
clear
close all

data = csvread('항공통계.csv');
data = [data(133:141,3)';data(283:291,3)'];
data_avg = mean(data');
data_label = ['inland';'jeju'];
bar(data_avg)
set(gca, 'XTickLabel', data_label); 
grid on

# 2
clc
clear
close all

data1 = csvread('food_1.csv');
data2 = csvread('food_2.csv');
data1 = data1(2,3:end);
data2 = data2(2,3:end);
data1 = mean(reshape(data1,12,11));
data2 = mean(reshape(data2,12,11));
data = [data1;data2];
plot(1:11, data(1,:),'-bo',1:11, data(2,:),'-g+')
grid on
xlabel("Years")
ylabel("Index")
legend("jjajang","jjamppong")
