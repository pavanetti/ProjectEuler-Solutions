module ProjectEuler.Problem33 where


f2 = concatMap osQueEuQuero f1
    where
        f1 = [(a,b,c) | a <- [1..9], b <- [1..9], c <- [1..9]]

osQueEuQuero :: (Num a, Ord a) => (a, a, a) -> [((a, a), (a, a))]
osQueEuQuero (a, b, c)
    | a == b || b == c || a == c = []
    | ab_c == a * bc = [((ab, bc), (a,c)) | ab < bc]
    | ab_c == a * cb = [((ab, cb), (a,c)) | ab < cb]
    | ab_c == b * ac = [((ab, ac), (b,c)) | ab < ac]
    | ab_c == b * ca = [((ab, ca), (b,c)) | ab < ca]
    | otherwise = []
    where
        ab_c = (10 * a + b) * c
        ab = 10 * a + b

        ac = 10 * a + c
        bc = 10 * b + c
        ca = 10 * c + a
        cb = 10 * c + b
