% 비정상 데이터(abnormal1) 전처리
% 주의: 정상 데이터와 동일한 열(2:5)과 동일한 다운샘플링(1:10:end)을 적용해야 합니다.
abnormal_r = abnormal{:, 2:5}; 
abnormal_diet = abnormal_r(1:10:end, :); 
abnormal_cell = {abnormal_diet'};

%% 2. 모델 예측 (복원) 수행
reconstruction_norm = predict(model, normal_cell);
reconstruction_abnorm = predict(model, abnormal_cell);

%% 3. 오차(MSE) 계산
% 정상 오차
err_norm = (normal_cell{1} - reconstruction_norm{1}).^2;
mse_norm = mean(err_norm, 1); % 시점별 평균 오차

% 비정상 오차
err_abnorm = (abnormal_cell{1} - reconstruction_abnorm{1}).^2;
mse_abnorm = mean(err_abnorm, 1);

%% 4. 결과 시각화 및 임계값 설정
figure('Name', 'Anomaly Detection Verification');

% 정상 데이터 오차 그래프
subplot(2,1,1);
plot(mse_norm, 'b', 'LineWidth', 1);
hold on;
title('Normal State: Reconstruction Error');
ylabel('MSE');
grid on;

% 비정상 데이터 오차 그래프
subplot(2,1,2);
plot(mse_abnorm, 'r', 'LineWidth', 1);
hold on;
title('Abnormal State (abnormal1): Reconstruction Error');
ylabel('MSE');
xlabel('Time Steps (Downsampled)');
grid on;

% 임계값(Threshold) 계산 및 표시
% 정상 데이터의 최대 오차보다 약간 높게 설정 (1.5배)
threshold = max(mse_norm) * 1.5;
subplot(2,1,1); yline(threshold, 'k--', 'Threshold', 'LineWidth', 2);
subplot(2,1,2); yline(threshold, 'k--', 'Threshold', 'LineWidth', 2);

fprintf('정상 데이터 최대 오차: %.6f\n', max(mse_norm));
fprintf('설정된 판단 임계값: %.6f\n', threshold);
fprintf('비정상 데이터 최대 오차: %.6f\n', max(mse_abnorm));