clear;
normal = readtable("GimbalData\normal.csv");
abnormal = readtable("GimbalData\abnormal.csv");
size_g = 1000;
normal = normal(:,4:5); abnormal = abnormal(:,4:5);


    normal = normal(1:floor(height(normal) / size_g):floor(height(normal)/size_g)*size_g,:);
    abnormal = abnormal(1:floor(height(abnormal)/size_g):floor(height(abnormal)/size_g)*size_g,:);






normal = table2array(normal);
abnormal = table2array(abnormal);

size = height(normal);
abnormal = abnormal(1:height(normal), :);


mag_normal = sqrt(normal(:,1).^2 + normal(:,2).^2);
ang_normal = atan2(normal(:,1), normal(:,2));

mag_abn = sqrt(abnormal(:,1).^2 + abnormal(:,2).^2);
ang_abn = atan2(abnormal(:,1), abnormal(:,2));

normal_ml = [mag_normal;ang_normal];
abnormal_ml = [mag_abn;ang_abn];

set = [normal_ml, abnormal_ml];

set(1:size, 3) = 0;
set(size+1:2*size, 3) = 1;
