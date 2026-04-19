function label = entry_point(iq, id)
    mag   = sqrt(single(iq)^2 + single(id)^2);
    phase = atan2(single(iq), single(id));
    inputData = [mag, phase];

    persistent model
    if isempty(model)
        model = loadLearnerForCoder('KNN_Model_coder.mat');
    end
    
    label = predict(model, inputData);
    label = uint8(label);
end