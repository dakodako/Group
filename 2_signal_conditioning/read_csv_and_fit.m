%freq at col1, temp at col2
data_raw = heat2;
%data_raw = csvread('filename');
freq = transpose(data_raw(:,1));
temp = transpose(data_raw(:,2));

