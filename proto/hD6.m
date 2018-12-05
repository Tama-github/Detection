
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and d6 distance
function dist = hD6(A, B)

    [la, ca] = size(A);
    [lb, cb] = size(B);
    dist = 0;
    for i=1:ca
        a = [A(1, i), A(2, i)];
        min = inf;
        for j = 1:cb
            d = normL2(a, [B(1, j), B(2, j)]);
            dist = dist + d;
        end
    end
    dist = dist/ca;
end