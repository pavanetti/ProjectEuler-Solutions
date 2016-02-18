module ProjectEuler.Problem33 where

import Data.Ratio

type RepeatingDigitsFraction a = (a,a,a)

answer33 :: Integer
answer33 = denominator $ product twoDigitsCuriosFractions

twoDigitsCuriosFractions :: [Ratio Integer]
twoDigitsCuriosFractions =
    concatMap curiousFraction [(a,b,c) | a <- [1..9], b <- [1..9], c <- [1..9]]

curiousFraction :: RepeatingDigitsFraction Integer -> [Ratio Integer]
curiousFraction (a, b, c)
    | a == b || b == c || a == c = []
    | ab_c == a * bc = [ab % bc | ab < bc]
    | ab_c == a * cb = [ab % cb | ab < cb]
    | ab_c == b * ac = [ab % ac | ab < ac]
    | ab_c == b * ca = [ab % ca | ab < ca]
    | otherwise = []
    where
        ab_c = (10 * a + b) * c
        ab = 10 * a + b

        ac = 10 * a + c
        bc = 10 * b + c
        ca = 10 * c + a
        cb = 10 * c + b
