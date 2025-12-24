itr = int(input(""))

for i in range(0, itr):
    num_str = input("")
    if num_str[0] == "1" and num_str[1] == '0' :
        pwr_str = num_str[2:]
        if pwr_str[0] >= "1" and pwr_str[0] <= "9":
            pwr = int(pwr_str)
            if pwr >= 2:
                print("YES")
            else:
                print("NO")
        else:
            print("NO")
    else:
        print("NO")