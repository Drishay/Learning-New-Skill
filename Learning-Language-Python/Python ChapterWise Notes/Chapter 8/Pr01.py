def _greatestnum():
    a = int(input("enter num "))
    b = int(input("enter num "))
    c = int(input("enter num "))

    if a > b :
        if a > c:
            print(F"{a} is greatest")
        elif c > a:
            print(F"{c} is greatest")
        else:
            print(f"a({a}) = c({c})")

    elif b > a:
        if b > c:
            print(F"{b} is greatest")
        elif c > b:
            print(f"{c} is greatest")
        else:
            print(f"b({b}) = c({c})")

    else:
        print(f"a({a}) = b({b})")

_greatestnum()