
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and dKth distance
%with k in [0, 1]
function dist = hDKth(A, B, k)
    [la, ca] = size(A);
    [lb, cb] = size(B);
    dist = 0;
    distances = [];
    for i=1:ca
        a = [A(1, i), A(2, i)];
        min = inf;
        for j = 1:cb
            d = normL2(a, [B(1, j), B(2, j)]);
            distances = [distances d];
        end
    end
    distances = sort(distances);
    kth = 0;
    if (k == 0)
        kth = 1;
    else
        kth = floor(ca*k);
    end
    dist = distances(kth);
    
end