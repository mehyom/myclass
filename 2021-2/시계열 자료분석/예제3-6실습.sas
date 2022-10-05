data farm;
 infile 'C:\Users\stat111\Desktop\¿¹Á¦3-6.txt';
 input yt; 
 t=_n_;
 lnyt=log(yt);
run;

goptions i=join;
proc gplot data=farm;
 plot yt*t;
 plot lnyt*t;
run;  

%logtest(farm, yt, out=trans, print=yes);

proc arima data=farm ;
   identify var=lnyt nlag=24;
   identify var=lnyt(1) nlag=24;
   identify var=lnyt(1,1) nlag=24;
   estimate p=1 ml plot;
   forecast lead=6 out=out_farm;
run;
