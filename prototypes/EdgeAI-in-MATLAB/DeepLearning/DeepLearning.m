options = trainingOptions('adam', ...
    'MaxEpochs', 50, ...             
    'MiniBatchSize', 32, ...         % CPU 학습 시 32~64가 적당 (메모리 부담 완화)
    'InitialLearnRate', 0.01, ...    % 학습 속도를 조금 높여서 빠르게 수렴 유도
    'Plots', 'training-progress');
normal_r = normal{:,2:5};

normal_diet = normal_r(1:10:end, :);


normal_cell = {normal_diet'};

model = trainNetwork(normal_cell, normal_cell, layers_1, options);
