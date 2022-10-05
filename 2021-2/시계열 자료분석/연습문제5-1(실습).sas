data liquor;
   infile 'F:\�ð迭�ڷ�м��кΰ���\2021����\��5��\��������5-1.txt';
   input year yt x1t x2t;
   t=year - 1869;
   x3t = (t - 3.5)**2;
run;

proc reg data=liquor;
  model yt = x1t x2t t x3t;
  output out=time r=residual ;
run;

/* preintervention series �ڷ� ����  */
data liquor1; set time;
    if year >= 1909 then delete;
run;

/*  preintervention series�� ����   ��������� ����  */
proc arima data=liquor1 ;
   identify var=residual  nlag=24;
   estimate p=1 noint ml plot maxit=100;
run;

data liquor2;
  set time;
   if year=1909 then pt=1; else pt=0;
run; 

proc print data=liquor2;
run;

