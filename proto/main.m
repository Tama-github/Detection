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

%steps defines the grid of rasterization
steps = [0.1, 0.1, 0.1, 0.1, 0.1, 0.1];
%bornes defines for each base's elements ei with i in [1, 6]
bornes = [  -1, 1;
            -1, 1;
            -1, 1;
            -1, 1;
            -1, 1;
            -1, 1
         ];
%All transformations we need to apply to cloud (need to add translations)
transfos = genTransfos(bornes, steps, 2, 0.4, 0.3, 1);