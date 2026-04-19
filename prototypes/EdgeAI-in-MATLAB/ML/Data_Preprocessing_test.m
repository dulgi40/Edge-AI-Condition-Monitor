clear;
testdata = readtable("GymbalData\abnormal_test.csv");


testdata = testdata(:,4:5);
testdata = testdata(1:50:end,:);
size = height(testdata);

testdata = table2array(testdata);



mag_normal = sqrt(testdata(:,1).^2 + testdata(:,2).^2);
ang_normal = atan2(testdata(:,1), testdata(:,2));


set_test = [mag_normal,ang_normal];


set_test(1:size, 3) = 1;
