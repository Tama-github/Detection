function [u, v] = getCoords(cloud)
u = [];
v = [];
[x, y] = size(cloud);

for i=1:x
    for j=1:y
        if (cloud(i, j) == 1)
            u = [u i];
            v = [v j];
        end
    end
end


end