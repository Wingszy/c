x=sym('x')

y=int(exp(-1*x^2),-inf,inf)


for I=1:3
    if rand(1)>0.5
        disp('the random is great than 0.5')
    else
        disp('the random is not great than 0.5')
    end
end