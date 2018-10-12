def min_max(f, int0, int1):
    if int0 > int1:
        int0 = int0 + int1
        int1 = int0 - int1
        int0 = int0 - int1
    min_value = None
    max_value = None
    for i in range(int1 - int0 + 1):
        x = f(int0 + i)
        if min_value is None or x < min_value:
            min_value = x
        elif max_value is None or x > max_value:
            max_value = x

    return min_value, max_value

    pass


print(min_max(lambda x: x ** 2 - 2 * x, -5, 5))
