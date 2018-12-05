function afficheImg(img, nom)
    figure('Name', nom);
    img = double(img);
    imagesc(img);
    colormap(gray);
    axis image;
end