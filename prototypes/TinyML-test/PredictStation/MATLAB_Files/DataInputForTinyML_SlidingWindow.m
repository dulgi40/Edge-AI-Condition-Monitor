clear; clc;
data_learning = csvread("C:\Users\vayne\Downloads\TinyML\learnR.csv");
data_test = csvread("C:\Users\vayne\Downloads\TinyML\testR.csv");

window = 50;
stride = 25; % 50% 오버랩
d_num = 5;

% --- 1. 학습 데이터 추출 ---
size_for = floor((size(data_learning,1) - window) / stride) + 1;
data_f = zeros(size_for, 4); % 이름을 data_f로 통일

for i = 1:size_for
    s_idx = (i-1)*stride + 1;
    e_idx = s_idx + window - 1;
    
    s_temp = data_learning(s_idx:e_idx, 1:3);
    data_s = s_temp(:); 
    size(data_s)
    data_f(i,1) = mean(s_temp, 'all');
    data_f(i,2) = rms(s_temp, 'all');
    data_f(i,3) = std(data_s);
    
    if sum(data_learning(s_idx:e_idx, 4)) >= d_num
        data_f(i,4) = 1;
    else
        data_f(i,4) = 0;
    end
end
data_learningF = array2table(data_f); % 여기서 Var1~Var4 결정

% --- 2. 테스트 데이터 추출 ---
size_fort = floor((size(data_test,1) - window) / stride) + 1;
data_f = zeros(size_fort, 4); % 같은 이름을 써야 테이블 구조가 같아짐

for i = 1:size_fort
    s_idx = (i-1)*stride + 1;
    e_idx = s_idx + window - 1;
    
    s_tempt = data_test(s_idx:e_idx, 1:3);
    data_st = s_tempt(:);
    
    data_f(i,1) = mean(s_tempt, 'all');
    data_f(i,2) = rms(s_tempt, 'all');
    data_f(i,3) = std(data_st);
    
    if sum(data_test(s_idx:e_idx, 4)) >= d_num
        data_f(i,4) = 1;
    else
        data_f(i,4) = 0;
    end
end
data_testF = array2table(data_f); % 학습 데이터와 동일한 Var1~Var4 생성

% 깔끔한 마무리
clear data_f data_learning data_test d_num e_idx i s_idx s_temp s_tempt data_s data_st size_for size_fort stride window;