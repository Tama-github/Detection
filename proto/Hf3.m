
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and d1 distance
%h is the hausdorff distance h
function d = Hf3(A, B, h)

    d1 = h(A, B);
    d2 = h(B, A);
    
    d = (d1 + d2)/2;
end