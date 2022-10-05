clc
clear
close all

x = csvread('netflix.csv');
added = x(2:end,7);
release = x(2:end,8); 
