function result = PredictStation(input_features)
    %#codegen
    persistent myModel
    if isempty(myModel)
        % 방금 만든 MySVMModel.mat을 로드합니다.
        myModel = loadLearnerForCoder('MySVMModel.mat');
    end
    
    % 이제 'predict' 함수가 C코드로 완벽하게 변환될 겁니다.
    result = predict(myModel, input_features);
end