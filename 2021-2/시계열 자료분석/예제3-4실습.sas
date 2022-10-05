data beer;
 infile 'C:\Users\stat111\Desktop\¿¹Á¦3-4.txt';
 input yt; 
 t=_n_;
 run;

goptions i=join;
proc gplot data=beer;
 plot yt*t;
run;  

proc arima ;
  identify var=yt nlag=24;
  identify var=yt(1) nlage=24;
  estimate ml plot;
  forecast lead=4 back=4 out=result;
run;
