close all;

model = imread('model.gif');
img = imread('image.gif');

modelE = edge(model, 'Canny');
imgE = edge(img, 'Canny');

afficheImg(modelE, 'Canny model');
afficheImg(imgE, 'Canny image');

[Um, Vm] = getCoords(modelE);
[Ui, Vi] = getCoords(imgE);
A = [Um; Vm];
B = [Ui; Vi];
%hD1(A, B);
Hf2(A, B, @hD50Kth)
%MHD = D22 = f2 + d6