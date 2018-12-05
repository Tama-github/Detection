
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and d5 distance
function dist = hD5(A, B)

    [la, ca] = size(A);
    [lb, cb] = size(B);
    dist = inf;
    for i=1:ca
        a = [A(1, i), A(2, i)];
        max = 0;
        for j = 1:cb
            d = normL2(a, [B(1, j), B(2, j)]);
            if (max < d)
                max = d;
            end
        end
        if (max < dist)
            dist = max;
        end
    end

end