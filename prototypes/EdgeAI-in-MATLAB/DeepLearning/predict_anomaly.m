function out = predict_anomaly(in)
    %#codegen
    global net % 전역 변수 선언 추가
    out = predict(net, in);
end