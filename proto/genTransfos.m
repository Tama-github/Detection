%Parameters are 
%bornes, 
%steps, 
%aMax : maximum aspect ratio skew
%sMax : shear value
%dMin : minimal determinant matrix we want
%dMax : maximal determinant matrix we want
function transfos = genTransfos(bornes, steps, aMax, sMax, dMin, dMax)

I1Min = bornes(1,1);
I1Max = bornes(1,2);

I2Min = bornes(2,1);
I2Max = bornes(2,2);

I3Min = bornes(3,1);
I3Max = bornes(3,2);

I4Min = bornes(4,1);
I4Max = bornes(4,2);

stepI1 = steps(1);
stepI2 = steps(2);
stepI3 = steps(3);
stepI4 = steps(4); 



e1 = [I1Min, 0, 0, 0, 0, 0];
e2 = [0, I2Min, 0, 0, 0, 0];
e3 = [0, 0, I3Min, 0, 0, 0];
e4 = [0, 0, 0, I4Min, 0, 0];
e5 = [0, 0, 0, 0, 1, 0];
e6 = [0, 0, 0, 0, 0, 1];

base = [e1; e2; e3; e4; e5; e6];
transfos = [];
for i=I1Min:stepI1:I1Max
    for j=I2Min:stepI2:I2Max
        for k=I3Min:stepI3:I3Max
            for l=I4Min:stepI4:I4Max
                e4 = e4 + [0, 0, 0, stepI4, 0, 0];
                base = [e1; e2; e3; e4; e5; e6];
                a00 = e1(1);
                a01 = e3(3);
                a10 = e2(2);
                a11 = e4(4);
                det = a00*a11 - a01*a10;
                skewTest = max([(sqrt(a00^2 + a10^2)/(sqrt(a01^2 + a11^2)) ), (sqrt(a01^2 + a11^2)/(sqrt(a00^2 + a10^2)) )]) <= aMax;
                scaleTest = (abs(a00*a01 + a10*a11)/(sqrt(a00^2 + a10^2) * sqrt(a01^2 + a11^2))) <= sMax;
                detTest = (det > 0) && (det > dMin) && (det < dMax);
                if (skewTest && scaleTest && detTest)
                    transfos = [transfos toAffine(base)];
                end
                
            end
            e4 = [0, 0, 0, I4Min, 0, 0];
            e3 = e3 + [0, 0, stepI3, 0, 0, 0];
        end
        e3 = [0, 0, I3Min, 0, 0, 0];
        e2 = e2 + [0, stepI2, 0, 0, 0, 0];
    end
    e2 = [0, I2Min, 0, 0, 0, 0];
    e1 = e1 + [stepI1, 0, 0, 0, 0, 0];
end

end