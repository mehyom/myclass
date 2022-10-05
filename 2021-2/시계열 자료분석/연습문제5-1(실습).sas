data liquor;
   infile 'F:\시계열자료분석학부강의\2021수업\제5장\연습문제5-1.txt';
   input year yt x1t x2t;
   t=year - 1869;
   x3t = (t - 3.5)**2;
run;

proc reg data=liquor;
  model yt = x1t x2t t x3t;
  output out=time r=residual ;
run;

/* preintervention series 자료 생성  */
data liquor1; set time;
    if year >= 1909 then delete;
run;

/*  preintervention series에 대한   노이즈모형 선택  */
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

