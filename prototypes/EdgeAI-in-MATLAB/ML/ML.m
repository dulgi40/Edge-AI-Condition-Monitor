clear;
normal = readtable("GimbalData\normal.csv");
abnormal = readtable("GimbalData\abnormal.csv");




normal = normal(:,2:5);
normal = normal(1:200:end,:);

abnormal = abnormal(:,2:5);
abnormal = abnormal(1:100:end,:);

normal{:,5} = 0;
abnormal{:,5} = 1;

set = [normal; abnormal];