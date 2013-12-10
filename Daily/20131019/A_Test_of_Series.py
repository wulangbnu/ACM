while True:
    n =int(raw_input())
    a=1
    b=1
    for i in range(3,n+1):
        b=a+b
        a=b-a
    print b
    if(n==0):
        exit(0)
