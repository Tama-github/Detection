
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and d1 distance
%h is the hausdorff distance h
function d = Hf4(A, B, h)
    d1 = h(A, B);
    d2 = h(B, A);
    [la, Na] = size(A);
    [lb, Nb] = size(B);
    d = (Na*d1+Nb*d2)/(Na + Nb);
end