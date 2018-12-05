
%See http://www.cse.msu.edu/prip/Files/DubuissonJain.pdf
%to see notations and d1 distance
function dist = hD1(A, B)

    [la, ca] = size(A);
    [lb, cb] = size(B);
    dist = 0;
    for i=1:ca
        a = [A(1, i), A(2, i)];
        min = inf;
        for j = 1:cb
            d = normL2(a, [B(1, j), B(2, j)]);
            if (min > d)
                min = d;
            end
        end
        if (min > dist)
            dist = min;
        end
    end

end