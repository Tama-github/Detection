
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and d1 distance
%h is the hausdorff distance h
function d = Hf2(A, B, h)

    d1 = h(A, B);
    d2 = h(B, A);
    
    d = max(d1, d2);
end