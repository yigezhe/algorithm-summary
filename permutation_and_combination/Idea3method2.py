def combinations(iterable, r):
        pool = tuple(iterable)
        n = len(pool)
        for indices in permutations(range(n), r):
                if sorted(indices) == list(indices):
                        yield tuple(pool[i] for i in indices)
