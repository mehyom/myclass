DATA Car;
 INFILE 'C:\Users\FAMILY\Desktop\carexample3.txt' FIRSTOBS=2;
 INPUT id size$ manufact$ model$ mileage reliable index;
RUN;
PROC MEANS DATA=Car MAXDEC=2 NOPRINT;
 VAR mileage reliable;
 OUTPUT OUT=Car_m
  MEAN(mileage reliable) = mean_m mean_r
  STD(mileage reliable) = std_m std_r
  CV(mileage reliable) = cv_m cv_r;
RUN;
PROC UNIVARIATE DATA=Car;
 VAR mileage;
 HISTOGRAM mileage;
 PROBPLOT mileage;
 QQPLOT mileage;
RUN;
