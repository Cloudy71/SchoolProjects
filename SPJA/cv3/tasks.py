def filter_file(path, keyword):
    """
    0.5 point
    Open file located at `path` and return all lines that contain the `keyword`.
    Strip line feeds from the lines.
    Example:
        filter_file('test.txt', 'car') == ['my car is awesome', 'is this your car?']

        test.txt:
        my car is awesome
        but it is so slow
        is this your car?
        no, this is Patrick
    """

    ret = []
    with open(path, "r") as file:
        lines = file.readlines()
        for line in lines:
            line = line[0:len(line) - 1] if "\n" in line else line
            if keyword in line:
                ret.append(line)
                pass
            pass
        pass

    return ret
    pass


# print(filter_file('test.txt', 'car'))


def sort_file(source, target):
    """
    1 point
    Open file located at `source`, read its lines and sort them.
    Then output the sorted lines to the file located at `target`.

    Return 'ok' if everything was successful.
    Return 'file not found' if the `source` file was not found (FileNotFoundError).
    Return 'error' if anything else went wrong.

    Example:
        sort_file('from.txt', 'to.txt') == 'ok'

        from.txt:
        dceb
        abc
        fff

        to.txt
        abc
        dceb
        fff
    """

    with open(source, "r") as sFile:
        lines = sFile.readlines()
        lines.sort()
        with open(target, "w") as tFile:
            for line in lines:
                tFile.write(line)
                pass
            pass

    pass


# sort_file("test.txt", "to.txt")


def incrementor(n=1):
    """
    0.5 point
    Return a function that will add `n` to its parameter.
    If this function receives no parameter, it should create an incrementor that adds 1 to its parameter.
    Example:
        inc = incrementor(5)
        inc(6) # 11
        inc(1) # 6

        inc = incrementor()
        inc(2) # 3
    """

    return (lambda x:
            n + x
            )
    pass


# print(incrementor()(0))


def fibonacci_closure():
    """
    2 points
    Return a closure that will generate elements of the Fibonacci sequence when called repeatedly.
    Example:
        g = fibonacci_closure()
        g() # 1
        g() # 1
        g() # 2
        g() # 3
        ...
    """

    global n, nV
    n = 0
    nV = [None, None]

    def seq():
        global n, nV

        nO = nV[0]
        nV[0] = 0 if n is 0 else 1 if n is 1 else nV[1]
        nV[1] = 1 if n is 0 or n is 1 else nO + nV[1]
        n += 1

        return nV[1]
        pass

    return seq


pass


def fibonacci_generator():
    """
    2 points
    Return a generator that will generate elements of the Fibonacci sequence when iterated.
    Example:
        for i in fibonacci_generator():
            print(i)
        # 1, 1, 2, 3, 5 ...
    """
    global closure
    closure = fibonacci_closure()

    def gen():
        global closure
        while 1:
            yield closure()
            pass
        pass

    return gen()

    pass


def cached(f):
    """
    2 points
    Create a decorator that caches the latest function result.
    When `f` is called multiple times in a row with the same parameter, compute the result just
    once and then return the result from cache.
    When `f` receives a different parameter, reset the cache and compute the new result.
    Assume that `f` receives exactly one parameter.
    Example:
        @cached
        def fn(a):
            return a + 1 # imagine an expensive computation

        fn(1) == 2 # computed
        fn(1) == 2 # returned from cache, fn is not called
        fn(3) == 4 # computed
        fn(1) == 2 # computed
    """

    global cachedKey, cachedValue
    cachedKey = None
    cachedValue = None

    def d(v):
        global cachedKey, cachedValue
        if v is not cachedKey:
            cachedValue = f(v)
            cachedKey = v
        return cachedValue

    return d
    pass


def bonus_tree_walker(tree, order):
    """
    1 point (bonus)
    Write a generator that traverses `tree` in the given `order` ('inorder', 'preorder' or 'postorder').
    You should know this from 'Algoritmy II'.
    The tree is represented with nested tuples (left subtree, value, right subtree).
    If there is no subtree, it will be marked as None.
    Example:
        tree = (((None, 8, None), 3, (None, 4, None)), 5, (None, 1, None))
            5
           / \
          3   1
         / \
        8   4
        list(bonus_tree_walker(tree, 'inorder')) == [8, 3, 4, 5, 1]
        list(bonus_tree_walker(tree, 'preorder')) == [5, 3, 8, 4, 1]
        list(bonus_tree_walker(tree, 'postorder')) == [8, 4, 3, 1, 5]
    """
    pass
