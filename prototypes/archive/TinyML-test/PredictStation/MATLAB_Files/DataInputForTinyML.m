clear; clc;
data_learning = csvread("C:\Users\vayne\Downloads\TinyML\learnR.csv");
data_test = csvread("C:\Users\vayne\Downloads\TinyML\testR.csv");



window = 50;
d_num = floor(window/10);
d_num
size_for = floor(size(data_learning,1)/window);
data_f = zeros(size_for,4);

size_fort = floor(size(data_test,1)/window);

for i = 1:1:size_for
    data_f(i,1) = mean(data_learning((window*(i-1)+1):window*i,1:3),'all');
    data_f(i,2) = rms(data_learning((window*(i-1)+1):window*i,1:3),'all');
    
    s_temp = data_learning((window*(i-1)+1:window*i),1:3);
    
    data_s = [s_temp(:,1);s_temp(:,2);s_temp(:,3);];
    %data_f(i,1) = kurtosis(data_s);
    data_f(i,3) = std(data_s);
    
    d = sum(data_learning((window*(i-1)+1):window*i,4));
    if d>=d_num
        data_f(i,4) = 1;
    else
        data_f(i,4) = 0;
    end
    
    
end
data_learningF = array2table(data_f);
data_f = zeros(size_fort,4);


for i = 1:1:size_fort
    data_f(i,1) = mean(data_test((window*(i-1)+1):window*i,1:3),'all');
    data_f(i,2) = rms(data_test((window*(i-1)+1):window*i,1:3),'all');
    
    s_tempt = data_test((window*(i-1)+1:window*i),1:3);
    
    data_st = [s_tempt(:,1);s_tempt(:,2);s_tempt(:,3);];
    %data_f(i,1) = kurtosis(data_st);
    data_f(i,3) = std(data_st);
    
    d = sum(data_test((window*(i-1)+1):window*i,4));
    if d>=d_num
        data_f(i,4) = 1;
    else
        data_f(i,4) = 0;
    end
    
    
end
data_testF = array2table(data_f);


clear d d_num data_f data_ft data_s data_st i s_temp s_tempt size_for size_fort window;
