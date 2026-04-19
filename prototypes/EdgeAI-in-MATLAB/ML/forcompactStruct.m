load('MLModel_Diet.mat');

saveLearnerForCoder(trainedModel.ClassificationKNN, 'KNN_Model_coder');