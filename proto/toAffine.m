function transfo = toAffine(base)

transfo = zeros(3);

e1 = base(1,:);
e2 = base(2,:);
e3 = base(3,:);
e4 = base(4,:);

A = [e1(1), e2(2), 0;
    e3(3), e4(4), 0;
    0, 0, 1];

transfo = maketform('affine', A);

end