DATA ex4;
input ht1-ht5 wt1-wt5;
ARRAY height [5] ht1 ht2 ht3 ht4 ht5;
ARRAY weight [5] wt1 wt2 wt3 wt4 wt5;
ARRAY dens [5] dens1 dens2 dens3 dens4 dens5;

DO i = 1 TO 5;
  dens[i] = weight[i] / height[i]**2;
END;
DROP i;

KEEP dens1 dens2 dens3 dens4 dens5;
cards;
180 160 178 172 168 82  62  77  70  73
170 160 174 155 184 77  71  75  65  77
160 170 173 176 170 58  75  68  66  70
170 150 166 169 159 72  55  67  66  60
;
PROC PRINT data = ex4;
RUN;
